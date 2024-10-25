#include <iostream>
#include <vector>
#include <string>
#include "People.h"
#include "book.h"
#include "phieutramuon.h"

using namespace std;




void bookMenu();
void Phieutramuonmenu();
void peopleMenu();

void bookMenu() {
    int n;
    Book* booklist = createBookArray(n); 
    int choice;

    do {
        cout << "\nBook Menu:\n";
        cout << "1. Add more books\n";
        cout << "2. Search for a book\n";
        cout << "3. Delete a book\n";
        cout << "4. Print all books\n";
        cout << "5. Insert a new book\n";
        cout << "6. Edit information of a book\n";
        cout << "7. Return to main menu\n"; 
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createBookArray(n);
            break;
        case 2:
            cout << "Searching for a book is not implemented yet." << endl;
            break;
        case 3:
            deleteBook(booklist, n);
            break;
        case 4:
            cout << "All Books:\n";
            for (int i = 0; i < n; ++i) {
                cout << "Book " << i + 1 << ": " << booklist[i].getTensach() << endl;
            }
            break;
        case 5:
            insertBook(booklist, n);
            break;
        case 6:
            cout << "Edit book information is not implemented yet." << endl;
            break;
        case 7:
            cout << "Returning to main menu." << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
       

    } while (choice != 7); 
    

    delete[] booklist;
}

void Phieutramuonmenu() {
    int n;
    phieutramuon* phieutramuonlist = createPhieuTraMuonArray(n); 
    int choice;

    do {
        cout << "\nPhieu Tram Muon Menu:\n";
        cout << "1. Add new phieu tram muon\n";
        cout << "2. Insert phieu tram muon at specific position\n";
        cout << "3. Delete a phieu tram muon\n";
        cout << "4. Print all phieu tram muon\n";
        cout << "5. Calculate fines for all\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createPhieuTraMuonArray( n);
            break;
        case 2:
            insertPhieuTraMuon(phieutramuonlist, n);
            break;
        case 3:
            deletePhieuTraMuon(phieutramuonlist, n);
            break;
        case 4:
            printforfine(phieutramuonlist, n);
            break;
        case 5:
            printforfine(phieutramuonlist, n); 
            break;
        case 6:
            cout << "Exiting phieu tram muon menu." << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
        

    } while (choice != 6); 

   
    delete[] phieutramuonlist;
}

void peopleMenu() {
    int n;
    People* peoplelist = createarray(n); 
    int choice;

    do {
        cout << "\nPeople Menu:\n";
        cout << "1. Add more people\n";
        cout << "2. Search for a person\n";
        cout << "3. Delete a person\n";
        cout << "4. Print all people\n";
        cout << "5. Insert a new person\n";
        cout << "6. Edit information of a person\n";
        cout << "7. Return to main menu\n"; 
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "You can implement functionality to add more people here." << endl;
            break;
        case 2:
            searching(peoplelist, n);
            break;
        case 3:
            deletion(peoplelist, n);
            break;
        case 4:
            prinf(peoplelist, n);
            break;
        case 5:
            insets(peoplelist, n);
            break;
        case 6:
            edit(peoplelist, n);
            break;
        case 7:
            cout << "Returning to main menu." << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
         

    } while (choice != 7); 

   
    delete[] peoplelist;
}

int main() {
    int choice;

    do {
        cout << "\nMain Menu:\n";
        cout << "1. Manage People\n";
        cout << "2. Manage Books\n";
        cout << "3. Manage Phieu Tram Muon\n";
        cout << "4. Exit\n"; 
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            peopleMenu(); 
            break;
        case 2:
            bookMenu(); 
            break;
        case 3:
            Phieutramuonmenu(); 
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
         

    } while (choice != 4); 

    return 0;
}
