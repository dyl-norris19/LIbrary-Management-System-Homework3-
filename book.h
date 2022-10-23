/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#ifndef Book_h
#define Book_h

#include <iostream>
#include <string>

using namespace std;

class Book {
    private:
        string author;
        string title;
        float isbnNum;
        int libraryId;
        int cost;
        string status;

    public:

        Book();

        string getAuthor();
        void setAuthor(string a);

        string getTitle();
        void setTitle(string t);

        int getISBN();
        void setISBN(float i);

        int getId();
        void setId(int i);

        int getCost();
        void setCost(int c);

        string getStatus();
        void setStatus(string s);

        bool operator==(const Book& rhs) const;
};
#endif