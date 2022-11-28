/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#ifndef libraryItems_h
#define libraryItems_h

#include "book.h"
#include "cd.h"
#include "dvd.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LibraryItems {
    private:
        vector<LibraryItem*> items;

    public:
        LibraryItems();

        void addBook(string a, string t, float isbn, string cat, int id, int c, string s);
        void addCD(string a, string t, int n, string d, string g, int id, int c, string s);
        void addDVD(string t, string cat, int r, string studio, string d, int id, int c, string s);

        void editCost();
        void editStatus(int id, string s);

        void deleteItem();
        LibraryItem findItem();
        void printItems();
        void printDetails();
};

#endif