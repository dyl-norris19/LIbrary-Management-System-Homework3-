/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#include "books.h"
#include <iostream>
#include <string>

using namespace std;

Books::Books() {}

void Books::addBook(int bNumber) {
    Book b = Book(bNumber); int tempI; float tempF; 
    char tempC; string tempS; bool valid = false;

    cin.ignore();
    //prompts and stores author
    cout << "Author: "; getline(cin, tempS); b.setAuthor(tempS);

    //prompts and stores title
    cout << "Title: "; getline(cin, tempS); b.setTitle(tempS);

    //prompts and stores isbn
    cout << "ISBN: "; cin >> tempF; b.setISBN(tempF);

    //create random libraryId!!!!
    cout << "Library ID: "  << b.getId() << endl;

    //prompt and store cost
    cout << "Cost: "; cin >> tempI; b.setCost(tempI);

    //prompt and store status if valid
    while (!valid) {
        cout << "Status: ";
        cin >> tempC;
        switch (tempC) {
            case 'i': {
                b.setStatus("In"); valid = true;
                break;
            }
            case 'o': {
                b.setStatus("Out"); valid = true;
                break;
            }
            case 'r': {
                b.setStatus("Repair"); valid = true;
                break;
            }
            case 'l': {
                b.setStatus("Lost"); valid = true;
                break;
            }
            default:
                cout << "Input invalid. i - In, o - Out, r - Repair, l - Lost" << endl;
                break;
        }
    }   
    //change to enum? ^
    cout << endl;
    books.push_back(b);
}

//Q: edit?? A: the cost
void Books::editCost() {
    int id; cout << "Enter Library Id: "; cin >> id;
    int cost; cout << "Enter new cost"; cin >> cost;
    bool found = false;

    for (int i = 0; i < books.size(); i++) {
        if (books.at(i).getId() == id) {
            books.at(i).setCost(cost);
            found = true;
        }
    }

    if (!found)
        cout << "Not found, check id";
}

void Books::deleteBook() {
    int id; cout << "Enter Library Id: "; cin >> id;
    bool found = false;
    for (int i = 0; i < books.size(); i++) {
        if (books.at(i).getId() == id) {
            books.erase(books.begin() + i);
            found = true;
        }
    }
    if (!found)
        cout << "Not found, check id" << endl;
    cout << endl;
}

//if not found, returns 1st book
Book Books::findBook() {
    int id;
    cout << "Enter Library Id: ";
    cin >> id;
    for (int i = 0; i < books.size(); i++)
        if (books.at(i).getId() == id)
            return books.at(i);
    return Book(0);
}

//Book {i + 1} -- {title}, {author} {libraryId} - ISBN: {isbnNum} Cost: {cost} Status: {status}
void Books::printBooks() {
    cout << "\nBooks" << endl;
    if (books.size() != 0) {
        for (int i = 0; i < books.size(); i++)
            if (i < books.size() - 1)
                cout <<  books.at(i).getTitle() << ", ";
            else
                cout << books.at(i).getTitle() << endl;
    } else
        cout << "No books!" << endl;
    cout << endl;
}

void Books::printDetails() {
    int id;
    cout << "Enter library id: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++)
        if (id == books.at(i).getId())
            cout << "Book " << i + 1 << " -- " << books.at(i).getTitle() << ", " << books.at(i).getAuthor()
                 << " " << books.at(i).getId() << " - ISBN: " << books.at(i).getISBN() << " Cost: "
                 << books.at(i).getCost() << " Status: " <<  books.at(i).getStatus() << endl;
}


