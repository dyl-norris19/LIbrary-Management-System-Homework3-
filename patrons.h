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

        void addPatron();
        void editFineBalance(int id, float f);
        void editNumBooks(int id);
        void deletePatron();
        Patron findPatron();
        void printPatrons();
        void printDetails();
};
#endif