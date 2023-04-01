#ifndef ITEM_H
#define ITEM_H


#include <string>
using namespace std;

enum itemstatus {In , Out , Repair, Lost };

class item{

  private:
    int Id;
    float Cost;
    itemstatus Status;
    int LoanPeriod;

  public:

    void setLibId(int id);
    int getLibId();
    void setCost(float cost); 
    float getCost();
    void setitemStatus(itemstatus status);
    itemstatus getitemStatus();
    void setLoanPeriod(int time);
    int getLoanPeriod();

    virtual void print();
    virtual ~item() {}

    item();
    item(int id , float cost , itemstatus status, int time);



};


#endif