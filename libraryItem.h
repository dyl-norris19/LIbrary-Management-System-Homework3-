/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#ifndef libraryItem_h
#define libraryItem_h

#include <iostream>
#include <string>

using namespace std;

class LibraryItem {
    private:
        int id;
        int cost;
        string status;
        int loanPeriod;

    public:
        LibraryItem();

        int getId();
        void setId(int i);

        int getCost();
        void setCost(int c);

        string getStatus();
        void setStatus(string s);

        int getLoanPeriod();
        void setLoanPeriod(int l);

        virtual string getTitle();
};

#endif