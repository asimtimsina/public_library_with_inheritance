#include <iostream>
#include <string>
#include "book.h"
#include "item.h"
using namespace std;

// defination of accessors and mutators
void book:: setAuthor(string author){Author = author;}
    string book:: getAuthor(){return Author;}

    void book::setTitle(string title){Title = title;}
    string book::getTitle(){return Title;}

    void book::setISBN(string isbn){ISBN_no = isbn;}
    string book::getISBN(){return ISBN_no;}

    void book::setCategory(string category){Category = category ;}
    string book::getCategory(){return Category;}

   //default constructor
  book:: book(): item(){
      Author = "None";
     Title= "None";
     ISBN_no = "None";
     Category = "None";
  }

  //parametarized constructor
  book:: book(int id , float cost , itemstatus status, int time, string author, string title, string isbn,string category ):item( id ,  cost ,  status,  time){
    Author = author;
     Title= title;
     ISBN_no = isbn;
     Category = "None";
  }


  void book::print() {
    item::print();
    cout <<"Author: " <<Author << endl;
    cout <<"Title: " << Title << endl;
    cout <<"ISBN Number: " << ISBN_no << endl;
    cout <<"Category: " << Category << endl;
    cout << endl;
}
