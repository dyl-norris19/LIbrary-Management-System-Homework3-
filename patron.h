/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */


#ifndef Patron_h
#define Patron_h

#include <iostream>
#include <string>

using namespace std;

class Patron {
    private:
        string name;
        int id;
        float fineBalance;
        int numBooks;

    public:

        Patron(int pNumber);
        Patron(string n, int id, int f, int num, int pNumber);

        std::string getName();
        void setName(string n);

        int getId();
        void setId(int i);

        float getFine();
        void setFine(int f);

        int getNumBooks();
        void setNumBooks(int num);

        bool operator==(const Patron& rhs) const;
};
#endif