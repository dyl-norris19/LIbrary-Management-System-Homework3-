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


void Patrons::addPatron(string n, int id, float f, int b) {
    Patron p = Patron(0);
    p.setName(n);
    p.setId(id);
    p.setFine(f);
    p.setNumBooks(b);
    patrons.push_back(p);
}

//adds patron to vector
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

//uses id to find patron, add to the total fine balance
//if not found, do nothing and let user know
void Patrons::addFineBalance(int id, float f) {
    float fine;
    bool found = false;
    for (int i = 0; i < patrons.size(); i++) {
        if (id == patrons.at(i).getId()) {
            found = true;
            fine = patrons.at(i).getFine() + f;
            patrons.at(i).setFine(fine);
        }
    }
    if (!found)
        cout << "Patron not found. Check Id" << endl;
}

//uses find patron to find patron, if not found so nothing and let user know
//subtracts the amount paid from fine. if greater than fine, do nothing and let user know
void Patrons::payFineBalance() {
    Patron patron = findPatron();
    int patronIndex;
    float credit;
    bool found = false;

    for (int i = 0; i < patrons.size(); i++) {
        if (patron.getId() == patrons.at(i).getId()) {
            found = true;
            patronIndex = i;
            cout << "Enter payment amount: "; cin >> credit;
            if (credit > patrons.at(patronIndex).getFine())
                cout << "Payment more than fine. Could not execute" << endl;
            else   
                patrons.at(patronIndex).setFine(patrons.at(patronIndex).getFine() - credit);
        }
    }
    if (!found)
        cout << "Patron not found. Check Id" << endl;
}

//edits num books, in parameter 1 for adding, -1 for subtracting one
//if patron not found, do nothing and let patron know
void Patrons::editNumBooks(int id, int n) {
    bool found = false;
    for (int i = 0; i < patrons.size(); i++) {
        if (id == patrons.at(i).getId()) {
            int num = patrons.at(i).getNumBooks() + n;
            patrons.at(i).setNumBooks(num);
            found = true;
        }
    }
    if (!found)
        cout << "Patron not found. Check Id" << endl;
}

//deletes patron from vector
void Patrons::deletePatron() {
    int id;
    cout << "Patron ID: ";
    cin >> id;
    for (int i = 0; i < patrons.size(); i++)
        if (patrons.at(i).getId() == id)
            patrons.erase(patrons.begin() + i);
}

//finds patron using id, if not found return default patron
Patron Patrons::findPatron() {
    int id;
    cout << "Patron ID: ";
    cin >> id;
    for (int i = 0; i < patrons.size(); i++)
        if (patrons.at(i).getId() == id)
            return patrons.at(i);
    return Patron(0);
}

//prints out all patrons by first name
void Patrons::printPatrons() {
    cout << "\nPatrons" << endl;
    for (int i = 0; i < patrons.size(); i++)
        if (i < patrons.size() - 1)
            cout << patrons.at(i).getName() << ", ";
        else
            cout << patrons.at(i).getName() << endl;
}

//prints out all atributes of one patron using id
void Patrons::printPatron(int id) {
    for (int i = 0; i < patrons.size(); i++)
        if (id == patrons.at(i).getId())
            cout << patrons.at(i).getName() << " " << patrons.at(i).getId() << " $" << 
                    patrons.at(i).getFine() << " " << patrons.at(i).getNumBooks() << endl;
}

//prints out all atributes of all patrons
//Patron {i + 1} -- Name: {name} {id} - Fine Balance: {fineBalance} - Number of books: {numBooks}
void Patrons::printDetails() {
    int id;
    cout << "Patron ID: ";
    cin >> id;
    for (int i = 0; i < patrons.size(); i++)
        if (id == patrons.at(i).getId())
            cout << "Patron " << i + 1 << " -- " << patrons.at(i).getName() << ": "
             << patrons.at(i).getId() << " - Fine Balance: $" << patrons.at(i).getFine()
             << " - Number of books: " << patrons.at(i).getNumBooks() << endl;
}

int Patrons::size() {return patrons.size();}
Patron Patrons::at(int i) {return patrons.at(i);}