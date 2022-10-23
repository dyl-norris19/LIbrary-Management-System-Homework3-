/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#include "book.h"
#include <iostream>
#include <string>

using namespace std;

Book::Book() {
    author = "Unknown";
    title = "None";
    isbnNum = 0;
    libraryId = 0;
    cost = 0;
    status = "In";
}

string Book::getAuthor() {return author;}
void Book::setAuthor(string a) {author = a;}

string Book::getTitle() {return title;}
void Book::setTitle(string t) {title = t;}

int Book::getISBN() {return isbnNum;}
void Book::setISBN(float i) {isbnNum = i;}

int Book::getId() {return libraryId;}
void Book::setId(int i) {libraryId = i;}

int Book::getCost() {return cost;}
void Book::setCost(int c) {cost = c;}

string Book::getStatus() {return status;}
void Book::setStatus(string s) {status = s;}

bool Book::operator==(const Book& rhs) const {
    if (author == rhs.author && title == rhs.title && 
    isbnNum == rhs.isbnNum && libraryId == rhs.libraryId &&
    cost == rhs.cost && status == rhs.status)
        return true;
    return false;
}