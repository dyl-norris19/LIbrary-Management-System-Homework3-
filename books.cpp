/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#include "books.h"
//#include <iostream>
//#include <string>

using namespace std;

Books::Books() {}

void Books::addBook(string a, string t, float isbn, int id, int c, string s) {
    Book b = Book(0);
    b.setAuthor(a);
    b.setTitle(t);
    b.setISBN(isbn);
    b.setId(id);
    b.setCost(c);
    b.setStatus(s);
    books.push_back(b);
}

//gets book info, adds it to books vector
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

    cout << "Status: In" << endl; b.setStatus("In");
    
    cout << endl;
    books.push_back(b);
}

//uses id to find book, edits cost,  if not found do nothing and inform user
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

//uses id to find book, sets the status
void Books::editStatus(int id, string s) {
    for (int i = 0; i < books.size(); i++) 
        if (id == books.at(i).getId())
            books.at(i).setStatus(s);
}

//prompts id and uses it to find book and delete from books vector, 
//if not found, do nothing and let user know
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

//finds book using id, if not found, returns default book
Book Books::findBook() {
    int id;
    cout << "Enter Library Id: ";
    cin >> id;
    for (int i = 0; i < books.size(); i++)
        if (books.at(i).getId() == id)
            return books.at(i);
    return Book(0);
}

//prints out books by title, if no books outputs no books
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

//prints all atributes of all books
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

int Books::size() {return books.size();}
Book Books::at(int i) {return books.at(i);}