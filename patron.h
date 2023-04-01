#ifndef PATRON_H
#define PATRON_H


#include <string>
using namespace std;

class patron{
//defining all of the data in private
private:
  string Name;
  int Id;
  float Fine_bal;
  int Curr_books;

// functions including accssors and mutators in public
public:
  void setName(string name);
  string getName();
  void setId(int id);
  int getId();
  void setFine(float fine);
  float getfine();
  void setCurr_books(int books);
  int getCurr_books();

 // declaration of default and parametrized constructor
patron();
patron( string name, int id, float fine,int books);

};


#endif