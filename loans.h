#ifndef Loans_h
#define Loans_h

#include "loan.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Loans {
    private:
        vector<Loan> loans;

    public:
        Loans();

        void addLoan(int l, int b, int p, time_t d, string s);
        void addLoan(Books& book, Patrons& patrons, int lNumber);
        void renewLoan(Books& book, Patrons& patrons);
        void deleteLoan(Books& books, Patrons& patrons);
        Loan findLoan();
        void reportLost(Books& books, Patrons& patrons);
        void printLoans();
        void printOverdue(Books& books, Patrons& patrons);
        int size();
        Loan at(int i);
};
#endif