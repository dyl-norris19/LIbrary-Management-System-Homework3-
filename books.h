/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#ifndef Books_h
#define Books_h

#include "book.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Books {
    private:
        vector<Book> books;

    public:

        Books();

        void addBook(string a, string t, float isbn, int id, int c, string s);
        void addBook(int bNumber);
        void editCost();
        void editStatus(int id, string s);
        void deleteBook();
        Book findBook();
        void printBooks();
        void printDetails();
        int size();
        Book at(int i);

};
#endif