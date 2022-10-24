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

void Patrons::addPatron(int pNumber) {
    Patron patron = Patron(pNumber); string tempS; int tempI;
    cin.ignore();
    //name
    cout << "Name: "; getline(cin, tempS); patron.setName(tempS);

    //id
    cout << "Patron ID: " << patron.getId() << endl;

    //fine balance
    cout << "Fine Balance: $0" << endl; patron.setFine(0);

    //num books
    cout << "Number of Books checked out: 0" << endl << endl; patron.setNumBooks(0);

    patrons.push_back(patron);
}

void Patrons::addFineBalance(int id, float f) {
    float fine;
    for (int i = 0; i < patrons.size(); i++) {
        if (id == patrons.at(i).getId()) {
            fine = patrons.at(i).getFine() + f;
            patrons.at(i).setFine(fine);
        }
    }
        
}

void Patrons::payFineBalance() {
    Patron patron = findPatron();
    int patronIndex;
    float credit;
    cout << "Enter payment amount: "; cin >> credit;

    for (int i = 0; i < patrons.size(); i++)
        if (patron.getId() == patrons.at(i).getId())
            patronIndex = i;
    
    if (credit > patrons.at(patronIndex).getFine())
        cout << "Payment more than fine. Could not execute" << endl;
    else   
        patrons.at(patronIndex).setFine(patrons.at(patronIndex).getFine() - credit);
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
    return Patron(0);
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
