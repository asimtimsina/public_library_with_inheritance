#include <iostream>
#include <string>
#include "patron.h"
using namespace std;


// defination of accessors and mutators
  void patron:: setName(string name){Name= name;}
  string patron::getName(){return Name;}

  void patron::setId(int id){Id= id;}
  int patron::getId(){return Id;}

  void patron::setFine(float fine){Fine_bal = fine;}
  float patron::getfine(){return Fine_bal;}
  
  void patron::setCurr_books(int books){Curr_books = books ; }
  int patron::getCurr_books(){return Curr_books ; }


   //default constructor
patron::patron(){
      Name = "None";
      Id = 0;
      Fine_bal= 0 ;
      Curr_books=0;
}

  //parametarized constructor
patron:: patron(string name, int id, float fine, int books){
    Name = name;
    Id = id;
    Fine_bal= fine ;
    Curr_books=books;


}