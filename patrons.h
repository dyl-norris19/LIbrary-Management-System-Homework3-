/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#ifndef Patrons_h
#define Patrons_h

#include "patron.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Patrons {
    private:
        vector<Patron> patrons;

    public:

        Patrons();

        void addPatron(int pNumber);
        void addFineBalance(int id, float f);
        void payFineBalance();
        void editNumBooks(int id, int n);
        void deletePatron();
        Patron findPatron();
        void printPatrons();
        void printPatron(int id);
        void printDetails();
};
#endif