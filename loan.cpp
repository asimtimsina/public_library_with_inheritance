#include <iostream>
#include <string>
#include "loan.h"
using namespace std;



// defination of accessors and mutators
    void loan:: setLoan_id(int loanid){Loan_Id = loanid;  }
    int loan::getLoan_id(){return Loan_Id;}

    void loan::setBook_id(int bookid){ Book_Id = bookid ;}
    int loan::getBook_id() {return Book_Id ;}

    void  loan::setPatron_id(int patronid){Patron_Id = patronid ;}
    int  loan::getPatron_id(){return Patron_Id ;}

    void  loan::setDuedate(int duedate){Due_Date = duedate ; }
    int  loan::getDuedate(){return Due_Date;}

    void loan::setRenew(bool renew){Renew = renew;}
    bool loan::getRenew(){return Renew;}

    void  loan::setLoanStatus(LoanStatus status){Status = status;}
    LoanStatus  loan::getLoanStatus(){return Status ; }
    
     
    
  
    //default constructor
    loan:: loan(){
       Loan_Id = 0;
       Book_Id = 0;
       Patron_Id= 0;
       Due_Date= 0;
       Renew = false;
       Status = Normal;
    }

  //parametarized constructor
    loan::loan(int loanid, int bookid, int patronid, int duedate,bool renew, LoanStatus status){
       Loan_Id = loanid;
       Book_Id = bookid;
       Patron_Id= patronid;
       Due_Date= duedate;
       Renew = false;
       Status = status;
    }

