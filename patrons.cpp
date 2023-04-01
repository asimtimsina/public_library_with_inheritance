#include<iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "patron.h"
#include "patrons.h"

using namespace std;



///////////////////////////////////////////////////////////////////////////////////////////////////

      void patrons::addPatron(){
          // function to add a new patron to the Patrons_list vector
         string name;
         int id;
         int b; 

         cout <<"Enter your Name: " ;
         cin.ignore();
         getline (cin, name);
        //cin >> name ;
       // cin.clear();
         // cin.ignore(256,'\n');
         
        
         
         cout << "Enter your Patron Id: ";
         cin >>  id;

        while(checkPatron(id)){
          cout <<"The id matches with another Patron" << endl;
           cout << "Enter your Patron Id: ";
            cin >>  id;
        }

        patron temp (name,id, 0,0);
        Patrons_list.push_back(temp);

        Patron_count ++; 
        cin.ignore();
      }


//////////////////////////////////////////////////////////////////////////////////////////////////////

      void patrons::editPatron(){//function to edit the details of the a patron using the patron id

         int id; 
         bool check=false; 
              string name; 
              cout <<"Please enter your Patron Id: " ; 
              cin  >> id ;



              for (int i = 0 ; i < Patron_count ; i ++){
                  if(Patrons_list[i].getId()==id){
                    printapatron(id);
                    check =true;
                      cout << "Enter your edited Name: " ;
                      cin >> name;
                       Patrons_list[i].setName(name);
                        cout <<"\nYour edited Name has been sucessfully saved in our database" << endl;
                       printapatron(id);
                       
                  }
                  }

                  if(!check){
                    cout << "Patron with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  }
      }



      //////////////////////////////////////////////////////////////////////////


      void patrons::changefineBal(int id , float amount){ //function to change the fine balance of the patron 

      
// cout << Patron_count << endl ;
 for (int i = 0 ; i < Patron_count ; i ++){
         
                  if(Patrons_list[i].getId()==id){
                      float patronfine = Patrons_list[i].getfine();
                          patronfine += amount ; 
                   Patrons_list[i].setFine(patronfine);
                   
                  }}

                 

      }


    ///////////////////////////////////////////////////////////////////////////
      void patrons::deletePatron(){ // function to delete a patron 
           int id; 
         bool check=false; 
              string name; 
              cout <<"Please enter your Patron Id: " ; 
              cin  >> id ;

                              for (int i = 0 ; i < Patron_count ; i ++){
                  if(Patrons_list[i].getId()==id){
                            check =true;
                      if(Patrons_list[i].getCurr_books()==0 && Patrons_list[i].getfine() == 0){
                  
                    cout << "The following record has been deleted from  our database " << endl;
                    printapatron(id);
                        Patrons_list.erase(Patrons_list.begin()+i);
                        Patron_count--;}
                        else{
                          cout <<"Cannot delete the Patron Id " << id << " ." << endl;
                          cout <<"Either Book on Loan or fine amount due." << endl;
                          printapatron(id); 
                        }

                       }
              }
                        if(!check){
                    cout << "Patron with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  
      }
              }
  //////////////////////////////////////////////////////////////////////////////////////
      void patrons::payfine(){ //function to pay the fine amount of a patron
         int id; 
         bool check=false; 
              string name; 
              cout <<"Please enter your Patron Id: " ; 
              cin  >> id ;
              bool amtchk = false ;
              float amount ;

                              for (int i = 0 ; i < Patron_count ; i ++){
                  if(Patrons_list[i].getId()==id){
                    check =true;
                    printapatron(id);
                    float tempfine = Patrons_list[i].getfine();
                    cout <<"Fine amount : $" << tempfine <<endl;
                    cout <<"Enter the amount you want to pay now : $";
                    do{
                      amtchk = false ;
                    
                    cin >> amount ;
                    if(amount > tempfine){
                      cout <<"Amount cannont be greater than Fine balance" << endl;
                      cout <<"Please re-enter the amount less than Fine balance : $" ;
                      amtchk = true;
                    }

                    }while (amtchk);
                    
                    tempfine -= amount;
                    Patrons_list[i].setFine(tempfine);
                    cout << endl << "Your new fine Balance is now $" <<tempfine << endl ; 
                     printapatron(id);

                  
      }
                              }
                               if(!check){
                    cout << "Patron with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;

      }
      }
          //    bool check = false;
             
               
 /////////////////////////////////////////////////////////////////////////////////           

int patrons::getNoofBooks(int id){  //function that returns the no of books borrowed by a patron
 bool check =false ;
// cout << Patron_count << endl ;
 for (int i = 0 ; i < Patron_count ; i ++){
         // printapatron(id);  //FIXME
                  if(Patrons_list[i].getId()==id){
                    check = true ;
                    return Patrons_list[i].getCurr_books();
                  }}

                  if(!check){
            cout << "Patron with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  
                  }
return -1;



}

  //////////////////////////////////////////    
      void patrons::printapatron(int id){  //function that prints a data of a patron by asking the patron id
      //    int id; 
          bool check =false ;
         //  cout <<"Please enter your Patron Id: " << endl; 
           //   cin  >> id ;

              for (int i = 0 ; i < Patron_count ; i ++){
                  if(Patrons_list[i].getId()==id){
                    check = true ;
                    cout << "Patrons Name\tPatrons Id \t Current No of Books \t Fine Balane " << endl;
                    cout <<"------------------------------------------------------------------"<< endl;
                  
                    
    cout <<left <<setw(20) << Patrons_list[i].getName() << setw(15) << Patrons_list[i].getId() <<setw(22) << Patrons_list[i].getCurr_books() <<setw(20) << Patrons_list[i].getfine() << endl;
                  }
         }
         if(!check){
            cout << "Patron with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  }
      }
                      
      

///////////////////////////////////////////////////////////////////////////
      void patrons::printallpatron(){ //function that prints all patrons details
        
     cout <<"Total Patron Number: " << Patrons_list.size() << endl; 
    cout << "Patrons Name\tPatrons Id \t Current No of Books \t Fine Balane " << endl;
    cout <<"------------------------------------------------------------------"<< endl;
  for (int i=0; i < Patron_count; i++){
  
    
    cout <<left <<setw(20) << Patrons_list[i].getName() << setw(15) << Patrons_list[i].getId() <<setw(22) << Patrons_list[i].getCurr_books() <<setw(20) << Patrons_list[i].getfine() << endl;
  }

      }
   
//////////////////////////////////////////////////////////////////////////////

 int patrons::checkfine(int id){  //function that returns the fine amount of a patron
    bool check =false ;

 for (int i = 0 ; i < Patron_count ; i ++){
         // printapatron(id);  //FIXME
                  if(Patrons_list[i].getId()==id){
                    check = true ;
                    return Patrons_list[i].getfine();
                  }}

                  if(!check){
            cout << "Patron with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  
                  }
return -1;

 }
 ///////////////////////////////////////////////////////////////////////////////

   bool patrons::checkPatron(int id){ // a function that checks whether a patron id exists or not 
     
 for (int i = 0 ; i < Patron_count ; i ++){
        if(Patrons_list[i].getId()==id){
                    return true ;
            }
 }
           
    
  return false;
   }

////////////////////////////////////////////////////////////////////////////////

void patrons::loadPatrons(){   // function that stores the patrons details from  a file to the Patrons_list vector
 
 ifstream fin;

  string name;
  int id;
  int fine;
  int books;
  string line;
  
    fin.open("Patrons.dat");

  fin >> Patron_count;
  fin.ignore();

while (getline(fin, line)){
  //cout << line << endl;
  istringstream cut(line);
  getline(cut ,name , ',' );
  cut >>  id >>  fine >>  books  ;
  patron temp(  name,  id,  fine,  books ) ;
   Patrons_list.push_back(temp);
}

  fin.close();
}
 /* ifstream fin;

  string name;
  int id;
  int fine;
  int books;
  string temp;
  
    fin.open("Patrons.dat");

  fin >> Patron_count;
  fin.ignore();

  for (int i = 0; i < Patron_count; i++)
  {
   fin.clear();
    getline (fin, name ,',');
    fin.clear();
    fin  >>  id >>  fine >>  books  ;
    //fin.ignore(1,'\n');
    //fin >> temp ; 
    cout << name <<" " << id << " " << fine <<" " << books << endl;
    //getline(fin, temp , '\n');   
   // fin.ignore();
       patron temp(  name,  id,  fine,  books ) ;
   Patrons_list.push_back(temp);
      fin.clear();
   
  }

  fin.close();
}
*/
////////////////////////////////////////////////////////////////////////
void patrons::changeBooktoapatron(int id, int num){ //function that changes the no of books borrowed by a patron
   for (int i = 0 ; i < Patron_count ; i ++){
        if(Patrons_list[i].getId()==id){
          Patrons_list[i].setCurr_books(Patrons_list[i].getCurr_books() + num ) ;
}
   }
}

/////////////////////////////////////////////////////////////////////////
void patrons::storePatrons(){  // function that stores the Books_list to a file when called

  ofstream fout;

  fout.open( "Patrons.dat");

      Patron_count = Patrons_list.size();

  fout << Patron_count << endl;

  for (int i=0; i < Patron_count; i++)
  {
   fout << Patrons_list[i].getName() <<", "  << Patrons_list[i].getId()  <<" " << Patrons_list[i].getfine()  <<" " << Patrons_list[i].getCurr_books()<<  endl;
  }

  fout.close();
}


//////////////////////////////////////////////
   patrons::patrons(){
     Patron_count = 0;
   }
   
//////////////////////////////////////////////
 patrons::~patrons(){
    Patrons_list.clear();
  }
//////////////////////////////////////////////
