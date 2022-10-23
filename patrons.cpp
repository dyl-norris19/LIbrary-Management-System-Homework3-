/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#include "patrons.h"
#include <iostream>
#include <string>

using namespace std;

Patrons::Patrons() {}

void Patrons::addPatron() {
    Patron patron = Patron(); int id = 0; string tempS; int tempI;
    //name
    cout << "Name: "; cin >> tempS; patron.setName(tempS);

    //id
    id = patrons.size(); cout << "Patron ID: " << id << endl; patron.setId(id);

    //fine balance
    cout << "Fine Balance: $0" << endl; patron.setFine(0);

    //num books
    cout << "Number of Books checked out: 0" << endl; patron.setNumBooks(0);

    patrons.push_back(patron);
}

void Patrons::editFineBalance(int id, float f) {
    float fine;
    for (int i = 0; i < patrons.size(); i++) {
        if (id == patrons.at(i).getId()) {
            fine = patrons.at(i).getFine() + f;
            patrons.at(i).setFine(fine);
        }
    }
        
}

void Patrons::editNumBooks(int id) {
    int n; cout << "Num books: "; cin >> n;
    for (int i = 0; i < patrons.size(); i++) 
        if (id == patrons.at(i).getId())
            patrons.at(i).setNumBooks(n);
}

void Patrons::deletePatron() {
    int id;
    cout << "Patron ID: ";
    cin >> id;
    for (int i = 0; i < patrons.size(); i++)
        if (patrons.at(i).getId() == id)
            patrons.erase(patrons.begin() + i);
}

Patron Patrons::findPatron() {
    int id;
    cout << "Patron ID: ";
    cin >> id;
    for (int i = 0; i < patrons.size(); i++)
        if (patrons.at(i).getId() == id)
            return patrons.at(i);
    return Patron();
}

//Patron {i + 1} -- Name: {name} {id} - Fine Balance: {fineBalance} - Number of books: {numBooks}
void Patrons::printPatrons() {
    cout << "\nPatrons" << endl;
    for (int i = 0; i < patrons.size(); i++)
        if (i < patrons.size() - 1)
            cout << patrons.at(i).getName() << ", ";
        else
            cout << patrons.at(i).getName() << endl;
}

void Patrons::printDetails() {
    int id;
    cout << "Patron ID: ";
    cin >> id;
    for (int i = 0; i < patrons.size(); i++)
        if (id == patrons.at(i).getId())
            cout << "Patron " << i + 1 << " -- " << patrons.at(i).getName() << ": "
             << patrons.at(i).getId() << " - Fine Balance: " << patrons.at(i).getFine()
             << " - Number of books: " << patrons.at(i).getNumBooks() << endl;
}
