#ifndef PATRONS_H
#define PATRONS_H


#include <string>
#include <vector>
#include "patron.h"
using namespace std;

class patrons{
    //private variable to store the data
  private:
      vector <patron> Patrons_list;
      int Patron_count;

  public:

//  // declaration of all functions
      void addPatron();
      void editPatron();
      void changefineBal(int id , float amount);
      void deletePatron();
      void payfine();
      void printapatron(int id);
      void printallpatron();
      void storePatrons();
      void loadPatrons();
      int getNoofBooks(int id);
      int checkfine(int id);
      bool checkPatron(int id);
      void changeBooktoapatron(int id, int num);
      

      patrons();
     ~patrons();

    
};


#endif