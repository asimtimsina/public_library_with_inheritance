#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "item.h"
#include "items.h"
#include "book.h"
#include "audio.h"
#include "dvd.h"
using namespace std;





items::items(){
  item_count = 0 ;
}


      void items::additem(){
          item *temp;
        cout <<"Enter 1 for a Book , 2 for a Audio CD or 3 for a DVD " ;
        int choice ;
        cin >> choice ;

        if (choice ==1){
          string title, author, isbn, category ; 
          int id, time;
          float cost;
          cout <<"Enter the Id of the Book: " ;
          cin >> id;
          cout <<"Enter the Cost of the Book: ";
          cin >> cost;
          cout <<"Enter the Loan Period of the Book: ";
          cin >> time; 
          cin.ignore();
          cout <<"Enter the Title of the Book: ";
          getline(cin, title);
          cout<<"Enter the Book's author: ";
          getline(cin, author);
          cout <<"Enter the ISBN number of the Book: ";
          cin >> isbn;
          cin.ignore();
          cout <<"Enter the Book's Category: ";
          getline(cin, category);

          temp = new book(id,cost, In, time, author, title, isbn, category);
          cout <<"New Book Record sucessfully added!" << endl;
        }

      else if(choice == 2){
        string artist,title, date,genre ; 
          int id, time , track;
          float cost;
          cout <<"Enter the Id of the Audio CD: " ;
          cin >> id;
          cout <<"Enter the Cost of the Audio CD: ";
          cin >> cost;
          cout <<"Enter the Loan Period of the Audio CD: ";
          cin >> time; 
          cin.ignore();
          cout <<"Enter the Artist: ";
          getline(cin,artist);
          cout <<"Enter the Title: ";
          getline(cin,title);
          cout <<"Emter the Release Date: ";
          getline(cin,date);
          cout <<"Enter the Genre: ";
          getline(cin,genre);
          cout <<"Enter the No of Tracks: ";
          cin >> track;

          temp = new audio( id ,  cost ,  In ,  time,  artist,  title,  track ,  date,  genre);
          cout <<"New Audio CD Record sucessfully added!" << endl;
      }
      else if(choice ==3){
        string title,category, studio,  date ; 
          int id, time , runtime;
          float cost;
          cout <<"Enter the Id of the DVD: " ;
          cin >> id;
          cout <<"Enter the Cost of the DVD: ";
          cin >> cost;
          cout <<"Enter the Loan Period of the DVD: ";
          cin >> time; 
          cin.ignore();
          cout <<"Enter the Title: ";
          getline(cin,title);
          cout <<"Enter the Category: ";
          getline(cin, category);
          cout <<"Enter the Studio: ";
          getline(cin, studio);
          cout <<"Enter the Release Date: ";
          getline(cin, date);
          cout <<"Enter the Run time: ";
          cin >> runtime ;



         temp = new dvd(id, cost, In, time, title, category , runtime, studio, date);
         cout <<"New DVD Record sucessfully added!" << endl;

      }
      item_list.push_back(temp);
      item_count++ ; 


      }
           


/////////////////////////////////////////////

void items::edititem(){

              bool check=false; 
               
              int id ;
              string title , author, isbn ;
              int cost;  
              
              cout <<"Please enter your Item Id: " ; 
              cin >> id;

              for (auto it = item_list.begin(); it !=item_list.end(); ++it){
                  if ((*it)->getLibId() == id){
                      if ( typeid(**it) == typeid(book) ){
                            book *bitem = dynamic_cast<book*> (*it);
                         cout << "Enter the edited Book Name: " ;
                      cin.ignore();
                      getline(cin, title);
                     
                      bitem->setTitle(title);

                      cout <<"Enter the edited authors name : ";
                      getline(cin, author);
                        bitem->setAuthor(author);
                                            
                      cout <<"Enter the edited ISBN Number : ";
                      cin >> isbn;
                       bitem->setISBN(isbn);
                            
                      cout <<"Enter the edited book Price : ";
                      cin >> cost;         
                       bitem->setCost(cost);

                   
                        cout <<"\nYour edited Name has been sucessfully saved in our database" << endl;
                       printbyid(id);

                  }

                  if ( typeid(**it) == typeid(audio) ){


                      string artist,title, date,genre ; 
          int id, time , track;
          float cost;
          audio *bitem = dynamic_cast<audio*> (*it);
          cout <<"Enter the edited Cost of the Audio CD: ";
          cin >> cost;
          bitem->setCost(cost);
          cout <<"Enter the edited Loan Period of the Audio CD: ";
          cin >> time; 
          bitem->setLoanPeriod(time);
          cin.ignore();
          cout <<"Enter the  edited Artist: ";
          getline(cin,artist);
          bitem->setArtist(artist);
          cout <<"Enter the  edited Title: ";
          getline(cin,title);
          bitem->setTitle(title);
          cout <<"Emter the  edited Release Date: ";
          getline(cin,date);
          bitem->setReleasedate(date);
          cout <<"Enter the  edited Genre: ";
          getline(cin,genre);
          bitem->setGenre(genre);
          cout <<"Enter the  edited No of Tracks: ";
          cin >> track;
          bitem->setNooftracks(track);

           cout <<"\nYour edited Name has been sucessfully saved in our database" << endl;
                       printbyid(id);



                  }


         if ( typeid(**it) == typeid(dvd) ){
            dvd *bitem = dynamic_cast<dvd*> (*it);

           string title,category, studio,  date ; 
          int id, time , runtime;
          float cost;
          
          cout <<"Enter the edited Cost of the DVD: ";
          cin >> cost;
          bitem->setCost(cost);
          cout <<"Enter the edited Loan Period of the DVD: ";
          cin >> time;
          bitem->setLoanPeriod(time); 
          cin.ignore();
          cout <<"Enter the edited Title: ";
          getline(cin,title);
          bitem->setTitle(title);
          cout <<"Enter the edited Category: ";
          getline(cin, category);
          bitem->setCategory(category);
          cout <<"Enter the edited Studio: ";
          getline(cin, studio);
          bitem->setStudio(studio);
          cout <<"Enter the edited Release Date: ";
          getline(cin, date);
          bitem->setReleasedate(date);
          cout <<"Enter the edited Run time: ";
          cin >> runtime ;
          bitem->setRuntime(runtime);

          cout <<"\nYour edited Name has been sucessfully saved in our database" << endl;
                       printbyid(id);



         }





}

}
}




////////////////////////////////////////////////


int items::getloantime(int id){
        item* temp;

        
                for (auto it = item_list.begin(); it !=item_list.end(); ++it){
                  if ((*it)->getLibId() == id){
                    temp = *it; 
                    int time = temp->getLoanPeriod();                    
                       
                    return time;
                    
              }
       

      }
}








////////////////////////////////////////////////




      
      void items::searchitem(){
        int id; 
          bool check =false ;
          cout <<"Please enter Item Id: " ; 
              cin  >> id ;

              for (auto it = item_list.begin(); it !=item_list.end(); ++it){
                  if ((*it)->getLibId() == id){
                    check = true ;
                       printbyid(id);
                       cout << endl;                       
                       }
              }
        if(!check){
            cout << "Item with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  }

      }
      
      ////////////////////////////////////////////////
      void items::deleteitem(){

        int id; 
          bool check =false ;
          cout <<"Please enter Item Id: " ; 
              cin  >> id ;

              for (auto it = item_list.begin(); it !=item_list.end(); ++it){
                  if ((*it)->getLibId() == id){
                    check = true ;
                     cout << "The following record has been deleted from  our database " << endl;
                    printbyid(id);
                        item_list.erase(it);
                        item_count -- ;
                        
                       }
              }
        if(!check){
            cout << "Item with the Id " <<id <<" not found" << endl;
                    cout << "Returning to the main menu" << endl << endl;
                  }

      }
      
      ////////////////////////////////////////////////
      void items::printbyid(int id){

          for (auto it = item_list.begin(); it !=item_list.end(); ++it){
                if ((*it)->getLibId() == id){
                  if ( typeid(**it) == typeid(book) ){
                         book *bitem = dynamic_cast<book*> (*it);

                    cout <<"Id: " << bitem->getLibId() << endl;
                    cout << "Cost: " << bitem->getCost() <<endl;
                    cout << "Current Status: " << bitem->getitemStatus() <<endl;
                    cout << "Loan Period: " << bitem->getLoanPeriod() << endl;

                    cout <<"Author: " <<bitem->getAuthor() << endl;
                    cout <<"Title: " << bitem->getTitle() << endl;
                    cout <<"ISBN Number: " << bitem->getISBN() << endl;
                    cout <<"Category: " << bitem->getCategory() << endl;
                    cout << endl;

                  }

                  if ( typeid(**it) == typeid(audio) ){
                         audio *bitem = dynamic_cast<audio*> (*it);

                         

                    cout <<"Id: " << bitem->getLibId() << endl;
                    cout << "Cost: " << bitem->getCost() <<endl;
                    cout << "Current Status: " << bitem->getitemStatus() <<endl;
                    cout << "Loan Period: " << bitem->getLoanPeriod() << endl;

                    cout <<"Artist: " << bitem->getArtist() << endl;
                    cout <<"Title: " << bitem->getTitle() << endl;
                    cout <<"No of Tracks: "  << bitem->getNooftracks() << endl;
                    cout <<"Genre: " << bitem->getGenre() << endl;
                    cout << endl;

                  }

                  if ( typeid(**it) == typeid(dvd) ){
                         dvd *bitem = dynamic_cast<dvd*> (*it);

                         

                    cout <<"Id: " << bitem->getLibId() << endl;
                    cout << "Cost: " << bitem->getCost() <<endl;
                    cout << "Current Status: " << bitem->getitemStatus() <<endl;
                    cout << "Loan Period: " << bitem->getLoanPeriod() << endl;

                    
                    cout <<"Title: " << bitem->getTitle() << endl;
                    cout <<"Category: " << bitem->getCategory() << endl;
                    cout <<"Runtime: " << bitem->getRuntime() << endl;
                    cout <<"Studio: " << bitem->getStudio() << endl;
                    cout <<"ReleaseDate: " << bitem->getReleasedate() << endl;
                    cout << endl;

                    

                  }


                }


          }

      }
      ////////////////////////////////////////////////
      void items::printallitem(){
        for (auto it = item_list.begin(); it !=item_list.end(); ++it){
                
                  if ( typeid(**it) == typeid(book) ){
                         book *bitem = dynamic_cast<book*> (*it);

                    cout <<"Id: " << bitem->getLibId() << endl;
                    cout << "Cost: " << bitem->getCost() <<endl;
                    cout << "Current Status: " << bitem->getitemStatus() <<endl;
                    cout << "Loan Period: " << bitem->getLoanPeriod() << endl;

                    cout <<"Author: " <<bitem->getAuthor() << endl;
                    cout <<"Title: " << bitem->getTitle() << endl;
                    cout <<"ISBN Number: " << bitem->getISBN() << endl;
                    cout <<"Category: " << bitem->getCategory() << endl;
                    cout << endl;

                  }

                  if ( typeid(**it) == typeid(audio) ){
                         audio *bitem = dynamic_cast<audio*> (*it);

                         

                    cout <<"Id: " << bitem->getLibId() << endl;
                    cout << "Cost: " << bitem->getCost() <<endl;
                    cout << "Current Status: " << bitem->getitemStatus() <<endl;
                    cout << "Loan Period: " << bitem->getLoanPeriod() << endl;

                    cout <<"Artist: " << bitem->getArtist() << endl;
                    cout <<"Title: " << bitem->getTitle() << endl;
                    cout <<"No of Tracks: "  << bitem->getNooftracks() << endl;
                    cout <<"Genre: " << bitem->getGenre() << endl;
                    cout << endl;

                  }

                  if ( typeid(**it) == typeid(dvd) ){
                         dvd *bitem = dynamic_cast<dvd*> (*it);

                         

                    cout <<"Id: " << bitem->getLibId() << endl;
                    cout << "Cost: " << bitem->getCost() <<endl;
                    cout << "Current Status: " << bitem->getitemStatus() <<endl;
                    cout << "Loan Period: " << bitem->getLoanPeriod() << endl;

                    
                    cout <<"Title: " << bitem->getTitle() << endl;
                    cout <<"Category: " << bitem->getCategory() << endl;
                    cout <<"Runtime: " << bitem->getRuntime() << endl;
                    cout <<"Studio: " << bitem->getStudio() << endl;
                    cout <<"ReleaseDate: " << bitem->getReleasedate() << endl;
                    cout << endl;

                    

                  }


                

          }

      }
      ////////////////////////////////////////////////
      bool items::checkitem(int id){
                  bool check =false ;
          
            for (auto it = item_list.begin(); it !=item_list.end(); ++it){
                  if ((*it)->getLibId() == id){
                    return true ;
                           }
            }
                  return false;
            }
      ////////////////////////////////////////////////
      bool items::itemin(int id){// function to check whether a item is in the library or not in the current time

        for (auto it = item_list.begin(); it !=item_list.end(); ++it){
                  if ((*it)->getLibId() == id){
                      if((*it)->getitemStatus() != In)
                           return true ;
                           }
            }
                  return false;
            
      }
      ////////////////////////////////////////////////
      void items::itemstatuschange(int id , itemstatus status ){}
      ////////////////////////////////////////////////
      float items::getcostofitem(int id){
         for (auto it = item_list.begin(); it !=item_list.end(); ++it){
                  if ((*it)->getLibId() == id){
                    return (*it)->getCost();
      }
         }
      return -1;
       }
      ////////////////////////////////////////////////
      void items::storeitems(){

          ofstream fout;

      fout.open( "item.dat");

      item_count = item_list.size();

  fout << item_count << endl;

item *temp;
 for (auto it = item_list.begin(); it !=item_list.end(); ++it) {
     temp=*it;
     if ( typeid(**it) == typeid(book) ){

       book *bitem = dynamic_cast<book*> (*it);
       fout << 1 <<" " << bitem->getLibId() <<" " << bitem->getCost() <<" " << bitem->getitemStatus() <<" " << bitem->getLoanPeriod() <<" " << bitem->getAuthor() <<"," << bitem->getTitle() <<"," << bitem->getISBN() <<"," << bitem->getCategory() << endl ;
     }

     if ( typeid(**it) == typeid(audio) ){

        audio *aitem = dynamic_cast<audio*> (*it);
         fout << 2 <<" " << aitem->getLibId() <<" " << aitem->getCost() <<" " << aitem->getitemStatus() <<" " << aitem->getLoanPeriod() <<" " << aitem->getArtist() <<"," << aitem->getTitle() <<"," << aitem->getNooftracks() <<" " << aitem->getReleasedate() << "," <<  aitem->getGenre()  << endl ;
  }

  if ( typeid(**it) == typeid(dvd) ){

        dvd *ditem = dynamic_cast<dvd*> (*it);
         fout << 3 <<" " << ditem->getLibId() <<" " << ditem->getCost() <<" " << ditem->getitemStatus() <<" " << ditem->getLoanPeriod() <<" " << ditem->getTitle() <<"," << ditem->getCategory() <<"," << ditem->getRuntime() << " "  << ditem->getStudio() <<"," << ditem->getReleasedate()  << endl ;
  }

  }

  fout.close();

}
      ////////////////////////////////////////////////
      void items::loaditems(){

        ifstream fin;

  int type, id, i1, i2 , i3 ; 
  float cost ;
  string  s1, s2 , s3, s4, s5 , s6 ,s7; 
  itemstatus stat; 
 
  
  fin.open("Books.dat");

  fin >> item_count;
  fin.ignore();
  
  string line ;

while (getline(fin, line)){
  //cout << line << endl;
  istringstream cut(line);
  cut >> type; 


  if (type ==1){

    cut >> id >> cost >> i1 >> i2 ;
    getline(cut, s1);
    getline(cut, s2);
    getline(cut, s3);
    getline(cut, s4);
    
  if (i1 ==0) stat = In;
  if (i1 ==1) stat = Out;
  if (i1 ==2) stat = Repair;
  
    item_list.push_back(new book(id ,cost ,stat,i2,s1,s2,s3,s4));

  }

   if (type ==2){

    cut >> id >> cost >> i1 >> i2 ;
    getline(cut, s1); //artist
    getline(cut, s2); //title
    cut >> i3 ;  // noof tracks
    getline(cut, s3); //Releasedate
    getline(cut, s4); //genre
    
  if (i1 ==0) stat = In;
  if (i1 ==1) stat = Out;
  if (i1 ==2) stat = Repair;
  
    item_list.push_back(new audio(id ,cost ,stat,i2, s1,s2,i3,s3,s4));

  }

  if (type ==3){

    cut >> id >> cost >> i1 >> i2 ;
    getline(cut, s1); //yiylr
    getline(cut, s2); //category
    cut >> i3 ;  // runtime
    getline(cut, s3); //studio
    getline(cut, s4); //release date
    
  if (i1 ==0) stat = In;
  if (i1 ==1) stat = Out;
  if (i1 ==2) stat = Repair;
  
    item_list.push_back(new dvd(id ,cost ,stat,i2, s1,s2,i3,s3,s4));




  }




  }

  }
          ////////////////////////////////////////////////