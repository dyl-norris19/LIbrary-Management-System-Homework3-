/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

/* check out book (update book and patron info, add a loan)
check in book (check for fines, update patron and book info, delete loan)
list all overdue
list all books for patron
update loan status based on clock
re check a book
edit a loan
report lost (update book and charge patron book cost)
*/

#include "loans.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

Loans::Loans() {}

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
            cout << "Loan Id: " << loans.at(loans.size() - 1).getLoanId() << endl << endl;
        }
    } 
}

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

void Loans::deleteLoan(Books books, Patrons patrons) { //return book
    Loan loan = findLoan();
    int loanIndex;
    int patronId;
    float fine = 0;
    time_t date = time(0);
    for (int i = 0; i < loans.size(); i++)
        if (loans.at(i).getLoanId() == loan.getLoanId())
            loanIndex = i;
    loans.at(loanIndex).updateLoan();
    if (loans.at(loanIndex).getStatus() == "Overdue") {
        patronId = loans.at(loanIndex).getPatronId();           //seconds in a day
        fine = floor((date - loans.at(loanIndex).getDueDate()) / 86400) * .25;
        patrons.addFineBalance(patronId, fine);
    }
    loans.erase(loans.begin() + loanIndex);
}



Loan Loans::findLoan() {
    int id;
    cout << "Enter Loan ID: ";
    cin >> id;
    for (int i = 0; i < loans.size(); i++)
        if (loans.at(i).getLoanId() == id)
            return loans.at(i);
    return Loan();
}

//Loan {i + 1} -- Loan ID: {loanId} BookId: {bookId} PatronId: {patronId} Due date: {dueDate} Status: {status}
void Loans::printLoans() {
    cout << "Loans" << endl;
    for (int i = 0; i < loans.size(); i++)
        cout << "Loan " << i + 1 << " --  Loan ID: " << loans.at(i).getLoanId() << " Book ID: "
             << loans.at(i).getBookId() << " Patron ID: " << loans.at(i).getPatronId() << " Due Date: "
             << loans.at(i).getDueDate() << " Status: " << loans.at(i).getStatus() << endl;
} //fix due date print out!!!!

//print llist of overdue books with patron info, update books and patrons
