#ifndef LOANS_H
#define LOANS_H


#include <string>
#include <vector>
#include "loan.h"
using namespace std;

class loans{
    //private variable to store the data
  private:
      vector <loan> Loans_list;
      int Loan_count;

  public:
    // declaration of all functions
      void Checkout();
      void Checking();
      void recheck (int id);
      void deleteLoan(int id);
      void reportlost();
      void findLoan ();
      void changeLoanStatus();
      void Printalldue();
      void Printaid(int id);
      void Printallloan();
      bool checkLoan(int id);
      void Printapatronloan(int id);
      
      

      void storeLoan();
      void loadLoan();

loans();
~loans();
      
};


#endif