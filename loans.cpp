#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "patron.h"
#include "patrons.h"
#include "book.h"
#include "item.h"
#include "audio.h"
#include "dvd.h"
#include "items.h"
#include "loan.h"
#include "loans.h"

using namespace std;

extern patrons pat; 
extern items boks;

  /////////////////////////////////////////////////////

     void loans::Checkout(){   //function to add a new loan in the Loans_list vector
      
    
    int loan;
    int Book;
    int Patron;
    string date;
    bool check ;
    LoanStatus status;
    
        check = false ;
      cout <<"Enter the Patron Id: " ;
      cin >> Patron;

      while(!pat.checkPatron(Patron)){
          cout <<"Patron with Patron Id: " << Patron <<" not found" << endl;
          cout <<"Re-enter your Patron Id: " ;
          cin >> Patron;
      }


      cout <<"Enter the Book Id: " ;
      cin >> Book;

      while(! boks.checkitem(Book)){
          cout <<"Patron with Library Id: " << Book <<" not found" << endl;
          cout <<"Re-enter Book's Library Id: " ;
          cin >> Book;
      }


      cout <<"Enter Loan Id: ";
      cin >> loan ; 

      while(checkLoan(loan)){
        cout <<"Loan id: " << loan <<" loan already in use." << endl;
          cout <<"Re-enter another Loan Id: " ;
          cin >> loan;
      }

      

       
        if(pat.getNoofBooks(Patron) >= 6){
          cout <<"You have already borrowed 6 or more Books." << endl;
          cout <<"Cannot Check out Book." << endl;
          check =true; 
        }

        if(pat.checkfine(Patron)!=0){
          cout <<"You have Fine amount due: $" << pat.checkfine(Patron) << endl;
          cout <<"Please pay the due amount before you check out a new Book" << endl;
          check = true ;
        }

        if(boks.itemin(Book)){
          cout <<"This book is not available at the Library at this Moment." << endl;
          cout <<"Please search for another Book." << endl;
          check =true ; 
        }

        int loantime = boks.getloantime(Book);


        time_t nowtime = time(0);
        nowtime += (86400 *loantime);

        char* duedate = ctime(&nowtime);
            
      if(!check){
       // cout << "loading " << endl;
      class loan temp(loan,Book , Patron, nowtime ,false,  Normal);
      Loans_list.push_back(temp);
      Loan_count ++ ;
      pat.changeBooktoapatron(Patron, 1);
      boks.itemstatuschange(Book,Out);
      cout <<"You are granted for this loan." << endl;
      cout << "This book will be due on: " << duedate << endl;
      Printaid(loan);
       cout <<"Returning to main Menu." << endl;
      
      } 
      else
      {
        cout <<"Returning to main Menu." << endl;
      }

      }
/////////////////////////////////////////////////////
bool loans::checkLoan(int id){ // function that checks whether a loan id already exits or not
       for (int i = 0 ; i < Loan_count ; i ++){
        if(Loans_list[i].getLoan_id()==id){
                    return true ;
                     
            }
 }
           
      
  return false;
   }
   

  /////////////////////////////////////////////////////
      void loans::Checking(){ //function to return a  book in the library
       
       changeLoanStatus();

    int loan;
    bool check = false;
    

    cout << "Enter your Loan Id: " ;
    cin >> loan ;

    for (int i = 0 ; i < Loan_count ; i++){

      if(Loans_list[i].getLoan_id()==loan){
          check = true;

         if(Loans_list[i].getLoanStatus() == Overdue ){
            int duedate = Loans_list[i].getDuedate();
              time_t nowtime = time(0);
              int dif_time = difftime(nowtime, duedate);
              if(dif_time >0){
                int id = Loans_list[i].getPatron_id();
                float fine = (dif_time / 86400) *0.25 ; 
                pat.changefineBal(id,fine);
              }



          }
                     pat.changeBooktoapatron(Loans_list[i].getPatron_id(), -1);
                     boks.itemstatuschange(Loans_list[i].getBook_id(),In);
          cout <<"We have received the Book." <<endl;
          cout <<"Thank you for using our Library Book" << endl;
           cout << "Returning to the main menu" << endl << endl;
            deleteLoan(loan);
            Loan_count -- ; 

      }

    }

    if(!check){
        cout << "Loan with the Id " <<loan <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
    }      
    


    }




      
  /////////////////////////////////////////////////////
      void loans::recheck (int id){ //function to recheck/renew a book
        changeLoanStatus();
        bool check = false ; 
          for (int i = 0 ; i < Loan_count ; i ++){
        if(Loans_list[i].getLoan_id()==id){
              if(Loans_list[i].getRenew() == false && Loans_list[i].getLoanStatus()== Normal){
                Loans_list[i].setRenew(true);
                int Book = Loans_list[i].getBook_id();
                 int loantime = boks.getloantime(Book);
                time_t nowtime = time(0);
                nowtime += (86400 *loantime);
                 char* duedate = ctime(&nowtime); 
                Loans_list[i].setDuedate(nowtime);
                cout <<"Your Loan status has been renewed." << endl;
                cout <<"You can return this book before: " << duedate << endl;

                Printaid(id);
                check = true ; 
                
              }
              else
              {
                cout<<"Cannot renew this loan." <<endl;
                cout <<"The duedate of this book is available below."<< endl;
                Printaid(id);
                check = true ;
              }
                     
            }
          }

          if(!check){
                    cout << "Patron with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  }

      }
      
  /////////////////////////////////////////////////////
      void loans::reportlost(){ //function to report a book as lost 
        int id; 
         bool check=false; 
              string name; 
              cout <<"Please enter your Loan Id: " ; 
              cin  >> id ;

               for (int i = 0 ; i < Loan_count ; i ++){
                  if(Loans_list[i].getLoan_id()==id){
                    check =true;
                    boks.itemstatuschange(Loans_list[i].getBook_id(),Lost);

                    int patron = Loans_list[i].getPatron_id();
                    float cost =boks.getcostofitem(patron) ;
                    pat.changefineBal(patron, cost);
                    cout <<"The book has been sucssfully recorded lost." << endl;
                    cout <<"Fine balance of $" << cost << " has been added to your account." << endl;
                    cout <<"This loan has been deleted." << endl;
                    deleteLoan(id); 
                    
                         }
              }
                       
                        if(!check){
                    cout << "Patron with the Loan Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  
      }   
      }
      
      
  /////////////////////////////////////////////////////

      void loans::findLoan (){  // function to find a loan from the Loans_list vector
        int id; 
         bool check=false; 
              string name; 
              cout <<"Please enter your Loan Id: " ; 
              cin  >> id ;

                for (int i = 0 ; i < Loan_count ; i ++){
                  if(Loans_list[i].getLoan_id()==id){
                    check =true;
                    Printaid(id);
                         }
                  
                 
              }
                       
                        if(!check){
                    cout << "Loan with the Loan Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                    
                  
      }   
      }
    ///////////////////////////////////////////////////

    void loans::deleteLoan(int id){ // function to delete a desired loan details upon called
        for (int i = 0 ; i < Loan_count ; i ++){
                  if(Loans_list[i].getLoan_id()==id){
                    Loans_list.erase(Loans_list.begin()+i);
                  }
    }
    }
      
  /////////////////////////////////////////////////////
      void loans::changeLoanStatus(){ //function that checks and changes the loan status to overdue after due date has passed

            time_t now = time(0);
         for (int i = 0 ; i < Loan_count ; i ++){
           time_t duetime = Loans_list[i].getDuedate();
           int dif_time = difftime(now, duetime);
           if(dif_time >0){
             Loans_list[i].setLoanStatus(Overdue);
           }

      }
      }
      
  /////////////////////////////////////////////////////
      void loans::Printalldue(){ //function that prints all the overdue loans

      changeLoanStatus();

        cout <<"Total Loans Count: " << Loan_count << endl; 
    cout << "Loan Id   \tPatrons Id \t Book Id \t Current Status \t Due Date  " << endl;
    cout <<"------------------------------------------------------------------------------"<< endl;
 
    for (int i=0; i < Loan_count; i++){
      if(Loans_list[i].getLoanStatus()== Overdue){
        time_t loandate = Loans_list[i].getDuedate();
        
        char* duedate = ctime(&loandate);
        //cout << duedate << endl; 




      string current ;
    if( Loans_list[i].getLoanStatus() == 1){
      current = "Normal";}
      else{
      current = "Overdue" ;}


     cout <<left <<setw(15) << Loans_list[i].getLoan_id() << setw(19) << Loans_list[i].getPatron_id() <<setw(18) << Loans_list[i].getBook_id() <<setw(15) <<  current  << duedate  ;
  }
    }


      }
      
      /////////////////////////////////////////////////////



      void loans::Printapatronloan(int id){ // function that prints the all loan details of a patron
         cout << "Loan Id   \tPatrons Id \t Book Id \t Current Status \t Due Date  " << endl;
    cout <<"------------------------------------------------------------------------------"<< endl;
  string date ;
    for (int i=0; i < Loan_count; i++){
           if(Loans_list[i].getPatron_id()==id){
             time_t loandate = Loans_list[i].getDuedate();
             char* duedate = ctime(&loandate);

               string current ;
                if( Loans_list[i].getLoanStatus() == 1){
                  current = "Normal";}
                  else{
                  current = "Overdue" ;}

                 cout <<left <<setw(15) << Loans_list[i].getLoan_id() << setw(19) << Loans_list[i].getPatron_id() <<setw(18) << Loans_list[i].getBook_id() <<setw(15) <<  current  << duedate  ;
           }

      }


      }
  /////////////////////////////////////////////////////
      void loans::Printaid(int id){ // function that prints a loan detail
          cout << "Loan Id   \tPatrons Id \t Book Id \t Current Status \t Due Date  " << endl;
    cout <<"------------------------------------------------------------------------------"<< endl;
  string date ;
    for (int i=0; i < Loan_count; i++){
           if(Loans_list[i].getLoan_id()==id){
             time_t loandate = Loans_list[i].getDuedate();
             char* duedate = ctime(&loandate);

               string current ;
                if( Loans_list[i].getLoanStatus() == 1){
                  current = "Normal";}
                  else{
                  current = "Overdue" ;}

                 cout <<left <<setw(15) << Loans_list[i].getLoan_id() << setw(19) << Loans_list[i].getPatron_id() <<setw(18) << Loans_list[i].getBook_id() <<setw(15) <<  current  << duedate  ;

           }

      }

      }
      
  /////////////////////////////////////////////////////
      void loans::Printallloan(){ // function that prints all of the loan details present in the Loans_list vector

        changeLoanStatus();



cout <<"Total Loans Count: " << Loan_count << endl; 
    cout << "Loan Id   \tPatrons Id \t Book Id \t Current Status \t Due Date  " << endl;
    cout <<"-----------------------------------------------------------------------------------------"<< endl;
 
    for (int i=0; i < Loan_count; i++){
        time_t loandate = Loans_list[i].getDuedate();
        
        char* duedate = ctime(&loandate);
        //cout << duedate << endl; 




      string current ;
    if( Loans_list[i].getLoanStatus() == 1){
      current = "Normal";}
      else{
      current = "Overdue" ;}


    cout <<left <<setw(15) << Loans_list[i].getLoan_id() << setw(19) << Loans_list[i].getPatron_id() <<setw(18) << Loans_list[i].getBook_id() <<setw(15) <<  current  << duedate  ;
  }


 }



//////////////////////////////////////////////////////
void loans::loadLoan(){    // function that stores the loans details from  a file to the Loans_list vector

   ifstream fin;

  int bookid, loanid, patronid, tempstat;
  int duedate ;
  string line;
  LoanStatus stat ; 
  bool renew;
  
    fin.open("Loans.dat");

  fin >> Loan_count;
  fin.ignore();

while (getline(fin, line)){
  //cout << line << endl;
  istringstream cut(line);
  
  cut >> duedate >>  loanid >> bookid >> patronid >> tempstat >> renew ; 
  if(tempstat ==0 )
  stat = Overdue ;
  else
  stat = Normal ; 

  loan temp( loanid , bookid, patronid , duedate ,renew , stat);
  Loans_list.push_back(temp);
}

  fin.close();
}

/////////////////////////////////////////////////////////////////////
void loans::storeLoan(){   // function that stores the Loans_list to a file when called

  ofstream fout;

  fout.open( "Loans.dat");

  Loan_count = Loans_list.size();

  fout << Loan_count << endl;

  for (int i=0; i < Loan_count; i++)
  {
   fout << Loans_list[i].getDuedate()<<" " <<Loans_list[i].getLoan_id() <<" "  <<Loans_list[i].getBook_id() <<" " <<Loans_list[i].getPatron_id()  <<" "  <<Loans_list[i].getLoanStatus() <<" " << Loans_list[i].getRenew() << endl ;
  }

  fout.close();
}


///////////////////////////////////
loans::loans(){
  Loan_count = 0;
}
///////////////////////////////////
loans::~loans(){
    Loans_list.clear();
}
/////////////////////////////////////


