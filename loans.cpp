/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

#include "loans.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

Loans::Loans() {}

void Loans::addLoan(int l, int b, int p, time_t d, string s) {
    Loan loan = Loan();
    loan.setLoanId(l);
    loan.setBookId(b);
    loan.setPatronId(p);
    loan.setDueDate(d);
    loan.setStatus(s);
    loans.push_back(loan);
}

//adds loan to vector with book and patron. if book or patron not found,
//do nothing and let user know
//take loanNumber + 640
void Loans::addLoan(Books& books, Patrons& patrons, int lNumber) {
    Patron patron = patrons.findPatron();
    if (patron == Patron(0))
        cout << "Patron not found. Check id" << endl << endl;
    else if (patron.getNumBooks() >= 6)
        cout << "Too many books checked out" << endl << endl;
    else {
        Book book = books.findBook();
        if (book == Book(0))
            cout << "Book not found. Check id" << endl << endl;
        else if (book.getStatus() != "In") 
            cout << "Book is not available for check out. Please choose another." << endl << endl;
        else {
            loans.push_back(Loan(book.getId(), patron.getId(), lNumber));
            patrons.editNumBooks(patron.getId(), 1);
            books.editStatus(book.getId(), "Out");
            cout << "Loan Id: " << loans.at(loans.size() - 1).getLoanId() << endl << endl;
        }
    } 
}

//extends due date by 10 days
//if loan not found, do nothing and let user know
void Loans::renewLoan(Books& books, Patrons& patrons) {
    Loan loan = findLoan();
    int loanIndex;
    if (!(loan == Loan())) {
        for (int i = 0; i < loans.size(); i++)
            if (loans.at(i).getLoanId() == loan.getLoanId()) {
                loanIndex = i;
                loans.at(i).updateLoan();
            }
        if (loans.at(loanIndex).getStatus() == "Overdue")
            cout << "Cannot renew overdue book" << endl;
        else
            loans.at(loanIndex).setDueDate(loans.at(loanIndex).getDueDate() + 864000);
    } else
    cout << "Could not find loan" << endl << endl;
}

//deletes loan, if loan not found, do nothing and let user know
void Loans::deleteLoan(Books& books, Patrons& patrons) { //return book
    Loan loan = findLoan();
    int patronId;
    float fine = 0;
    time_t date = time(0);
    bool found = false;
    for (int i = 0; i < loans.size(); i++) {
        if (loans.at(i).getLoanId() == loan.getLoanId()) {
            found = true;
            loans.at(i).updateLoan();
            patronId = loans.at(i).getPatronId();
            if (loans.at(i).getStatus() == "Overdue") {            //seconds in a day
                fine = floor((date - loans.at(i).getDueDate()) / 86400) * .25;
                patrons.addFineBalance(patronId, fine);
                cout << fine << endl;
            }
            patrons.editNumBooks(patronId, -1);
            books.editStatus(loans.at(i).getBookId(), "In");
            loans.erase(loans.begin() + i);
        }
    }
    if (!found)
        cout << "Loan not found. Check Id." << endl << endl;
    else
        cout << endl;
}

//changes book status, charges patron, and 
//deletes loan. if not found, do thing and let user know
void Loans::reportLost(Books& books, Patrons& patrons) {
    Patron patron = patrons.findPatron();
    Book book = books.findBook();
    Loan loan = findLoan();
    int loanIndex;
    bool found = false;
    for (int i = 0; i < loans.size(); i++) {
        if (loans.at(i).getLoanId() == loan.getLoanId()) {
            found = true;
            loanIndex = i;
        }
    }       
    if (found) {
        if (patron == Patron(0))
            cout << "Patron not found. Check id" << endl << endl;
        else {
            if (book == Book(0))
                cout << "Book not found. Check id" << endl << endl;
            else {
                books.editStatus(book.getId(), "Lost");
                patrons.addFineBalance(patron.getId(), book.getCost());
                loans.erase(loans.begin() + loanIndex);
                cout << endl;
            }
        } 
    } else
        cout << "Loan not found. Check id." << endl << endl;
}

//finds loan using loan id
//if not found, return default loan
Loan Loans::findLoan() {
    int id;
    cout << "Enter Loan ID: ";
    cin >> id;
    for (int i = 0; i < loans.size(); i++)
        if (loans.at(i).getLoanId() == id)
            return loans.at(i);
    return Loan();
}

//prints all loans with all attributes
//Loan {i + 1} -- Loan ID: {loanId} BookId: {bookId} PatronId: {patronId} Due date: {dueDate} Status: {status}
void Loans::printLoans() {
    cout << "Loans" << endl;
    for (int i = 0; i < loans.size(); i++) {
        cout << "Loan " << i + 1 << " --  Loan ID: " << loans.at(i).getLoanId() << " Book ID: "
             << loans.at(i).getBookId() << " Patron ID: " << loans.at(i).getPatronId() << " Due Date: ";
             loans.at(i).printDueDate(); cout << " Status: " << loans.at(i).getStatus() << endl;
    }
    cout << endl;
} 

void Loans::printOverdue(Books& books, Patrons& patrons) {
    for (int i = 0; i < loans.size(); i++) {
        loans.at(i).updateLoan();
        if (loans.at(i).getStatus() == "Overdue") {
            int patronId = loans.at(i).getPatronId();
            patrons.printPatron(patronId);
        }
    }
    cout << endl;
}

int Loans::size() {return loans.size();}
Loan Loans::at(int i) {return loans.at(i);}