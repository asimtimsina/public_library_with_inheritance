#ifndef LOAN_H
#define LOAN_H


#include <string>
using namespace std;

enum LoanStatus { Overdue , Normal};

class loan{
//defining all of the data in private
  private:
    int Loan_Id;
    int Book_Id;
    int Patron_Id;
    int Due_Date;
    bool Renew; 
    LoanStatus Status;

  public:
  // functions including accssors and mutators in public
    void setLoan_id(int loanid);
    int getLoan_id();
    void setBook_id(int bookid);
    int getBook_id();
    void setPatron_id(int patronid);
    int getPatron_id();
    void setDuedate(int duedate);
    int getDuedate();
    void setRenew(bool renew);
    bool getRenew();
    void setLoanStatus(LoanStatus status);
    LoanStatus getLoanStatus();
    
     
    
 // declaration of default and parametrized constructor
    loan();
    loan(int loanid, int bookid, int patronid, int duedate,bool renew, LoanStatus status);
        
      


};

#endif