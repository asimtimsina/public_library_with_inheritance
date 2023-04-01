#include <iostream>
#include <string>
#include "item.h"
using namespace std;

// defination of accessors and mutators

  void item::setLibId(int id){Id = id;}
    int item::getLibId(){return Id;}
    void item::setCost(float cost){Cost = cost;} 
    float item::getCost(){return Cost;}
    void item::setitemStatus(itemstatus status){Status = status ; }
    itemstatus item::getitemStatus(){return Status;}
    void item::setLoanPeriod(int time){LoanPeriod = time;}
    int item::getLoanPeriod(){return LoanPeriod;}

     void item::print(){
       cout <<"Id: " << Id << endl;
       cout << "Cost: " << Cost <<endl;
       cout << "Current Status: " << Status <<endl;
       cout << "Loan Period: " << LoanPeriod << endl;
     }

     
    // ~item() {}

    item::item(){
      Id = 0;
      Cost = 0;
      Status = In;
      LoanPeriod = 0;
    }
    item::item(int id , float cost , itemstatus status, int time){
      Id = id;
      Cost = cost;
      Status = status;
      LoanPeriod = time;
    }
