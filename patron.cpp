/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

//pay fines

#include "patron.h"
#include <iostream>
#include <string>

using namespace std;

Patron::Patron() {
    name = "None";
    id = 0;
    fineBalance = 0;
    numBooks = 0;
}

Patron::Patron(string n, int i, int f, int num) {
    name = n;
    id = i;
    fineBalance = f;
    numBooks = num;
}

std::string Patron::getName() {return name;}
void Patron::setName(string n) {name = n;}

int Patron::getId() {return id;}
void Patron::setId(int i) {id = i;}

int Patron::getFine() {return fineBalance;}
void Patron::setFine(int f) {fineBalance = f;}

int Patron::getNumBooks() {return numBooks;}
void Patron::setNumBooks(int num) {numBooks = num;}

bool Patron::operator==(const Patron& rhs) const {
    if (name == rhs.name && id == rhs.id && 
        fineBalance == rhs.fineBalance && numBooks == rhs.numBooks)
        return true;
    return false;
}