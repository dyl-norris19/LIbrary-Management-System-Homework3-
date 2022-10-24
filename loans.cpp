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

//adds loan to vector with book and patron. if book or patron not found,
//do nothing and let user know
//take loanNumber + 640
void Loans::addLoan(Books books, Patrons patrons, int lNumber) {
    Patron patron = patrons.findPatron();
    if (patron == Patron(0))
        cout << "Patron not found. Check id" << endl;
    else if (patron.getNumBooks() >= 6)
        cout << "Too many books checked out" << endl;
    else {
        Book book = books.findBook();
        if (book == Book(0))
            cout << "Book not found. Check id" << endl;
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
void Loans::renewLoan(Books books, Patrons patrons) {
    Loan loan = findLoan();
    int loanIndex;
    if (!(loan == Loan())) {
        for (int i = 0; i < loans.size(); i++)
            if (loans.at(i).getLoanId() == loan.getLoanId())
                loanIndex = i;
        if (loans.at(loanIndex).getStatus() == "Overdue")
            cout << "Cannot renew overdue book" << endl;
        else
            loans.at(loanIndex).setDueDate(loans.at(loanIndex).getDueDate() + 864000);
    } else
        cout << "Could not find loan" << endl;
}

//deletes loan, if loan not found, do nothing and let user know
void Loans::deleteLoan(Books books, Patrons patrons) { //return book
    Loan loan = findLoan();
    int loanIndex;
    int patronId;
    float fine = 0;
    time_t date = time(0);
    bool found = false;
    for (int i = 0; i < loans.size(); i++) {
        if (loans.at(i).getLoanId() == loan.getLoanId()) {
            found = true;
            loanIndex = i;
            loans.at(loanIndex).updateLoan();
            if (loans.at(loanIndex).getStatus() == "Overdue") {
                patronId = loans.at(loanIndex).getPatronId();           //seconds in a day
                fine = floor((date - loans.at(loanIndex).getDueDate()) / 86400) * .25;
                patrons.addFineBalance(patronId, fine);
            }
        patrons.editNumBooks(patronId, -1);
        books.editStatus(loans.at(loanIndex).getBookId(), "In");
        loans.erase(loans.begin() + loanIndex);
        }
    }
    if (!found)
        cout << "Loan not found. Check Id." << endl;
}

//changes book status, charges patron, and 
//deletes loan. if not found, do thing and let user know
void Loans::reportLost(Books books, Patrons patrons) {
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
            cout << "Patron not found. Check id" << endl;
        else {
            if (book == Book(0))
                cout << "Book not found. Check id" << endl;
            else {
                books.editStatus(book.getId(), "Lost");
                patrons.addFineBalance(patron.getId(), book.getCost());
                loans.erase(loans.begin() + loanIndex);
            }
        } 
    }
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
    for (int i = 0; i < loans.size(); i++)
        cout << "Loan " << i + 1 << " --  Loan ID: " << loans.at(i).getLoanId() << " Book ID: "
             << loans.at(i).getBookId() << " Patron ID: " << loans.at(i).getPatronId() << " Due Date: "
             << loans.at(i).getDueDate() << " Status: " << loans.at(i).getStatus() << endl;
} 

void Loans::printOverdue(Books books, Patrons patrons) {
    for (int i = 0; i < loans.size(); i++) {
        loans.at(i).updateLoan();
        if (loans.at(i).getStatus() == "Overdue") {
            int patronId = loans.at(i).getPatronId();
            patrons.printPatron(patronId);
        }
    }
}