/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#include "libraryItem.h"

using namespace std;

LibraryItem::LibraryItem() {
    id = 0;
    cost = 0;
    status = "In";
    loanPeriod = 10;
}

int LibraryItem::getId() {return id;}
void LibraryItem::setId(int i) {id = i;}

int LibraryItem::getCost() {return cost;}
void LibraryItem::setCost(int c) {cost = c;}

string LibraryItem::getStatus() {return status;}
void LibraryItem::setStatus(string s) {status = s;}

int LibraryItem::getLoanPeriod() {return loanPeriod;}
void LibraryItem::setLoanPeriod(int l) {loanPeriod = l;}

string LibraryItem::getTitle() {
    return "";
}