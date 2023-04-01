#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "item.h"
#include <string>
using namespace std;



class book: public item {
//defining all of the data in private
  private: 
    string Author;
    string Title;
    string ISBN_no;
   string Category;
    
// functions including accssors and mutators in public
  public :
    void setAuthor(string author);
    string getAuthor();
    void setTitle(string title);
    string getTitle();
    void setISBN(string isbn);
    string getISBN();
    void setCategory(string category);
    string getCategory();
   
   void print();
    
    // declaration of default and parametrized constructor
  book();
  book(int id , float cost , itemstatus status, int time, string author, string title, string isbn, string category );

};
#endif