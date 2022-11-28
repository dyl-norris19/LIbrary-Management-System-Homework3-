/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#include "book.h"
//#include <iostream>
//#include <string>

using namespace std;

Book::Book(int bNumber) {
    author = "Unknown";
    title = "None";
    isbnNum = 0;
    category = "None";
    setId(264000 + bNumber); //????
    setCost(0);
    setStatus("In");
    setLoanPeriod(0);
}

string Book::getAuthor() {return author;}
void Book::setAuthor(string a) {author = a;}

string Book::getTitle() {return title;}
void Book::setTitle(string t) {title = t;}

int Book::getISBN() {return isbnNum;}
void Book::setISBN(float i) {isbnNum = i;}

string Book::getCategory() {return category;}
void Book::setCategory(string c) {category = c;}

/*bool Book::operator==(const Book& rhs) const {
    if (author == rhs.author && title == rhs.title && 
    isbnNum == rhs.isbnNum && libraryId == rhs.libraryId &&
    cost == rhs.cost && status == rhs.status)
        return true;
    return false;
}*/