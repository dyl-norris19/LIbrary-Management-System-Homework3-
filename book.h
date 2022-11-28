/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#ifndef Book_h
#define Book_h

#include "libraryItem.h"
#include <iostream>
#include <string>

using namespace std;

class Book : public LibraryItem {
    private:
        string author;
        string title;
        float isbnNum;
        string category;

    public:

        Book(int bNumber);

        string getAuthor();
        void setAuthor(string a);

        string getTitle();
        void setTitle(string t);

        int getISBN();
        void setISBN(float i);

        string getCategory();
        void setCategory(string c);

        //bool operator==(const Book& rhs) const;
};
#endif