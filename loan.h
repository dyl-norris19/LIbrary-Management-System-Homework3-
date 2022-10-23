/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#ifndef Loan_h
#define Loan_h

#include "books.h"
#include "patrons.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Loan {
    private:
        int loanId;
        int bookId;
        int patronId;
        time_t dueDate;
        string status;

    public:
        Loan();
        Loan(int b, int p);

        int getLoanId();
        void setLoanId(int l);

        int getBookId();
        void setBookId(int b);

        int getPatronId();
        void setPatronId(int p);

        time_t getDueDate();
        void setDueDate(time_t d);

        string getStatus();
        void setStatus(string s);

        void updateLoan();

};
#endif