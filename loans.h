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

        void addLoan(Books book, Patrons patrons, int lNumber);
        //edit??
        void deleteLoan(Books books, Patrons patrons);
        Loan findLoan();
        void printLoans();



};
#endif