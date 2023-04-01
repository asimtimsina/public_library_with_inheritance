#ifndef ITEMS_H
#define ITEMS_H


#include <string>
#include <vector>
#include "item.h"
#include "book.h"
#include "audio.h"
#include "dvd.h"
//using namespace std;

class items{
  private:
    vector <item*> item_list;
    int item_count; 

  public :

  // declaration of all functions
      void additem();
      void edititem();
      void searchitem();
      void deleteitem();
      void printbyid(int id);
      void printallitem();
      bool checkitem(int id);
      bool itemin(int id);
      void itemstatuschange(int id , itemstatus status );
      float getcostofitem(int id);
      void storeitems();
      void loaditems();
      int getloantime(int id);

items();
//~items();

};


#endif

