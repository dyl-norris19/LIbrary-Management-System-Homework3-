/* Dylan Norris
 * 10/12/22
 * David Keathly
 * 
 */

//#include <iostream>
#include <stdlib.h>
#include <fstream>
//#include <ctime>
//#include <string>
#include "books.h"
#include "patrons.h"
#include "loans.h"

using namespace std;

Books books = Books();
Patrons patrons = Patrons();
Loans loans = Loans();
int bookNumber = 1;
int patronNumber = 1;
int loanNumber = 1;
ifstream input;
ofstream output;

bool isEmpty(ifstream& file);
void printMenu();
void executeMenu();

int main() {
    char type;
    string tempS;
    string tempS2;
    string tempS3;
    int tempI;
    int tempI2;
    int tempI3;
    time_t tempT;
    float tempF;
    
    input.open("data.txt");

    if (!isEmpty(input)) {
        while (input >> type) {
            if (type == 'b') {
                input.ignore();
                getline(input, tempS, '|');
                getline(input, tempS2, '|');
                input >> tempF >> tempI >> tempI2 >> tempS3;
                books.addBook(tempS, tempS2, tempF, tempI, tempI2, tempS3);
                bookNumber++;
            } else if (type == 'p') {
                input.ignore();
                getline(input, tempS, '|');
                input >> tempI >> tempF >> tempI2;
                patrons.addPatron(tempS, tempI, tempF, tempI2);
                patronNumber++;
            } else if (type == 'l') {
                input >> tempI >> tempI2 >> tempI3 >> tempT >> tempS;
                loans.addLoan(tempI, tempI2, tempI3, tempT, tempS);
                loanNumber++;
            }
        }
    }

    input.close();

    executeMenu();
    
    output.open("data.txt");
    for (int i = 0; i < books.size(); i++)
        output << "b|" << books.at(i).getAuthor() << "|" << books.at(i).getTitle()
               << "|" << books.at(i).getISBN() << " " << books.at(i).getId()
               << " " << books.at(i).getCost() << " " << books.at(i).getStatus() << endl;
    for (int i = 0; i < patrons.size(); i++)
        output << "p|" << patrons.at(i).getName() << "|" << patrons.at(i).getId()
               << " " << patrons.at(i).getFine() << " " << patrons.at(i).getNumBooks() << endl;
    for (int i = 0; i < loans.size(); i++)
        if (i < loans.size() - 1)
            output << "l " << loans.at(i).getLoanId() << " " << loans.at(i).getBookId()
                << " " << loans.at(i).getPatronId() << " " << loans.at(i).getDueDate()
                << " " << loans.at(i).getStatus() << endl;
        else
            output << "l " << loans.at(i).getLoanId() << " " << loans.at(i).getBookId()
                << " " << loans.at(i).getPatronId() << " " << loans.at(i).getDueDate()
                << " " << loans.at(i).getStatus();
    output.flush();
    output.close();
    

    return 0;
}

bool isEmpty(ifstream& file) {
    return file.peek() == ifstream::traits_type::eof();
}

void printMenu() {
    cout << "Menu" << endl;
    cout << "b - Add Book" << endl;
    cout << "p - Add Patron" << endl;
    cout << "o - Check Out Book" << endl;
    cout << "i - Check In Book" << endl;
    cout << "r - Renew Book" << endl;
    cout << "f - Pay Fines" << endl;
    cout << "v - View Overdue Books" << endl;
    cout << "t - Report Lost" << endl;
    cout << "k - Print Books" << endl;
    cout << "j - Print Single Book Details" << endl;
    cout << "a - Print Patrons" << endl;
    cout << "s - Print Single Patron Details" << endl;
    cout << "l - Print Loans" << endl;
    cout << "q - Quit" << endl;

    cout << "\nChoose an option: ";
}

void executeMenu() {
    char choice = 'z'; //to start the loop
    while (choice != 'q') {
        printMenu();
        cin >> choice;
        choice = tolower(choice);
        cout << endl;
        if (choice == 'b') 
            books.addBook(bookNumber++);

        else if (choice == 'p')
            patrons.addPatron(patronNumber++);

        else if (choice == 'o')
            loans.addLoan(books, patrons, loanNumber++);

        else if (choice == 'i')
            loans.deleteLoan(books, patrons);

        else if (choice == 'r')
            loans.renewLoan(books, patrons);

        else if (choice == 'f')
            patrons.payFineBalance();

        else if (choice == 'v')
            loans.printOverdue(books, patrons);
        
        else if (choice == 't')
            loans.reportLost(books, patrons);
        else if (choice == 'k')
            books.printBooks();

        else if (choice == 'j')
            books.printDetails();

        else if (choice == 'a')
            patrons.printPatrons();

        else if (choice == 's')
            patrons.printDetails();

        else if (choice == 'l')
            loans.printLoans();

        else if (choice == 'q')
            cout << "Goodbye!" << endl;

        else
            cout << "Input not valid. Please try again." << endl;

    }
}