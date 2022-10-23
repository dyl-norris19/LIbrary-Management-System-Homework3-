/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#include "loan.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

Loan::Loan() {
    loanId = 0;
    bookId = 0;
    patronId = 0;
    dueDate = 0;
    status = "Normal";
}

Loan::Loan(int b, int p) {
    loanId = 0; //create random id?
    bookId = b;
    patronId = p;
    dueDate = time(0) + 864000; //set due date (todays date + 10 days)
    status = "Normal";
}

int Loan::getLoanId() {return loanId;}
void Loan::setLoanId(int l) {loanId = l;}

int Loan::getBookId() {return bookId;}
void Loan::setBookId(int b) {bookId = b;}

int Loan::getPatronId() {return patronId;}
void Loan::setPatronId(int p) {patronId = p;}

time_t Loan::getDueDate() {return dueDate;}
void Loan::setDueDate(time_t d) {dueDate = d;}

string Loan::getStatus() {return status;}
void Loan::setStatus(string s) {status = s;}

void Loan::updateLoan() {
    if (dueDate < time(0))
        status = "Overdue";
}
