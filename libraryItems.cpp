/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#include "libraryItems.h"
#include <vector>
#include <typeinfo>

using namespace std;

LibraryItems::LibraryItems() {}

//loan period?
void LibraryItems::addBook(string a, string t, float isbn, string cat, int id, int c, string s) {
    Book* b = new Book(0);
    b->setAuthor(a);
    b->setTitle(t);
    b->setISBN(isbn);
    b->setCategory(cat);
    b->setId(id);
    b->setCost(c);
    b->setStatus(s);
    items.push_back(b);
}

//loan period?
void LibraryItems::addCD(string a, string t, int n, string d, string g, int id, int c, string s) {
    AudioCD* cd = new AudioCD(0);
    cd->setArtist(a);
    cd->setTitle(t);
    cd->setNumTracks(n);
    cd->setReleaseDate(d);
    cd->setGenre(g);
    cd->setId(id);
    cd->setCost(c);
    cd->setStatus(s);
    items.push_back(cd);
}

//loan period? or maybe in constructor
void LibraryItems::addDVD(string t, string cat, int r, string studio, string d, int id, int c, string s) {
    Dvd* dvd = new Dvd(0);
    dvd->setTitle(t);
    dvd->setCategory(cat);
    dvd->setRunTime(r);
    dvd->setStudio(studio);
    dvd->setReleaseDate(d);
    dvd->setId(id);
    dvd->setCost(c);
    dvd->setStatus(s);
    items.push_back(dvd);
}

void LibraryItems::editCost() {
    int id; cout << "Enter Library Id: "; cin >> id;
    int cost; cout << "Enter new cost"; cin >> cost;
    bool found = false;

    for (int i = 0; i < items.size(); i++) {
        if (items.at(i)->getId() == id) {
            items.at(i)->setCost(cost);
            found = true;
        }
    }

    if (!found)
        cout << "Not found, check id";
}

void LibraryItems::editStatus(int id, string s) {
    for (int i = 0; i < items.size(); i++) 
        if (id == items.at(i)->getId())
            items.at(i)->setStatus(s);
}

void LibraryItems::deleteItem() {
    int id; cout << "Enter Library Id: "; cin >> id;
    bool found = false;
    for (int i = 0; i < items.size(); i++) {
        if (items.at(i)->getId() == id) {
            items.erase(items.begin() + i);
            found = true;
        }
    }
    if (!found)
        cout << "Not found, check id" << endl;
    cout << endl;
}

//return 
LibraryItem LibraryItems::findItem() {
    int id;
    cout << "Enter Library Id: ";
    cin >> id;
    for (int i = 0; i < items.size(); i++)
        if (items.at(i)->getId() == id)
            return *items.at(i);
    return Book(0);
}

//fix!!
void LibraryItems::printItems() {
    cout << "\nItems" << endl;
    if (items.size() != 0) {
        for (auto it = items.begin(); it != items.end(); it++) {
            if (typeid(**it) == typeid(Book)) {
                Book *bruh = dynamic_cast <Book*>(*it);
                cout << bruh->getTitle();
            }
        }
    } else
        cout << "No items!" << endl;
    cout << endl;
}

void LibraryItems::printDetails() {
    int id;
    cout << "Enter library id: ";
    cin >> id;

    for (int i = 0; i < items.size(); i++)
        if (id == items.at(i)->getId())
            cout << "LibraryItem " << i + 1 << " -- " << /*items.at(i)->getTitle() << ", " << items.at(i).getAuthor()
                 <<*/ " " << items.at(i)->getId() << /*" - ISBN: " << items.at(i).getISBN() <<*/ " Cost: "
                 << items.at(i)->getCost() << " Status: " <<  items.at(i)->getStatus() << endl;
}