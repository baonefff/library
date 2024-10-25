#include "Book.h"


Book::Book() = default;


Book::Book(string newISBN, string newTensach, string newTacgia, string newNhaxuatban, string newNamxuatban, string newTheloai, int newGiasach, int newSoquyensach)
    : ISBN(newISBN), tensach(newTensach), tacgia(newTacgia), nhaxuatban(newNhaxuatban), namxuatban(newNamxuatban), theloai(newTheloai), giasach(newGiasach), soquyensach(newSoquyensach) {}


string Book::getISBN() const { return ISBN; }
string Book::getTensach() const { return tensach; }
string Book::getTacgia() const { return tacgia; }
string Book::getNhaxuatban() const { return nhaxuatban; }
string Book::getNamxuatban() const { return namxuatban; }
string Book::getTheloai() const { return theloai; }
int Book::getGiasach() const { return giasach; }
int Book::getSoquyensach() const { return soquyensach; }


void Book::setISBN(const string& newISBN) { ISBN = newISBN; }
void Book::setTensach(const string& newTensach) { tensach = newTensach; }
void Book::setTacgia(const string& newTacgia) { tacgia = newTacgia; }
void Book::setNhaxuatban(const string& newNhaxuatban) { nhaxuatban = newNhaxuatban; }
void Book::setNamxuatban(const string& newNamxuatban) { namxuatban = newNamxuatban; }
void Book::setTheloai(const string& newTheloai) { theloai = newTheloai; }
void Book::setGiasach(int newGiasach) { giasach = newGiasach; }
void Book::setSoquyensach(int newSoquyensach) { soquyensach = newSoquyensach; }


Book* createBookArray(int& n) {
    cout << "How many books do you want in your array? " << endl;
    cin >> n;

    Book* array = new Book[n];

    for (int i = 0; i < n; ++i) {
        string ISBN, tensach, tacgia, nhaxuatban, namxuatban, theloai;
        int giasach, soquyensach;

        cout << "Enter details for book " << i + 1 << ":\n";
        cout << "Enter ISBN: ";
        cin >> ISBN;
        cout << "Enter Title (tensach): ";
        cin >> tensach;
        cout << "Enter Author (tacgia): ";
        cin >> tacgia;
        cout << "Enter Publisher (nhaxuatban): ";
        cin >> nhaxuatban;
        cout << "Enter Publication Year (namxuatban): ";
        cin >> namxuatban;
        cout << "Enter Genre (theloai): ";
        cin >> theloai;
        cout << "Enter Price (giasach): ";
        cin >> giasach;
        cout << "Enter Number of Copies (soquyensach): ";
        cin >> soquyensach;
        cout << "-------------------------\n";

        array[i] = Book(ISBN, tensach, tacgia, nhaxuatban, namxuatban, theloai, giasach, soquyensach);
    }

    cout << "Input complete.\n";
    return array;
}


void insertBook(Book*& array, int& n) {
    Book* newArray = new Book[n + 1];
    cout << "Please enter the position where you want to add the new book (0 to " << n << "): " << endl;
    int position;
    cin >> position;

    if (position < 0 || position > n) {
        cout << "Invalid position. Please enter a value between 0 and " << n << "." << endl;
        delete[] newArray;
        return;
    }

    string ISBN, tensach, tacgia, nhaxuatban, namxuatban, theloai;
    int giasach, soquyensach;

    cout << "Enter ISBN: ";
    cin >> ISBN;
    cout << "Enter Title (tensach): ";
    cin >> tensach;
    cout << "Enter Author (tacgia): ";
    cin >> tacgia;
    cout << "Enter Publisher (nhaxuatban): ";
    cin >> nhaxuatban;
    cout << "Enter Publication Year (namxuatban): ";
    cin >> namxuatban;
    cout << "Enter Genre (theloai): ";
    cin >> theloai;
    cout << "Enter Price (giasach): ";
    cin >> giasach;
    cout << "Enter Number of Copies (soquyensach): ";
    cin >> soquyensach;

    newArray[position] = Book(ISBN, tensach, tacgia, nhaxuatban, namxuatban, theloai, giasach, soquyensach);

    for (int i = 0; i < position; ++i) {
        newArray[i] = array[i];
    }
    for (int i = position; i < n; ++i) {
        newArray[i + 1] = array[i];
    }

    delete[] array;
    array = newArray;
    ++n;

    cout << "Array after insertion:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Book " << i + 1 << ":\n";
        cout << "ISBN: " << array[i].getISBN() << "\n";
        cout << "Title (tensach): " << array[i].getTensach() << "\n";
        cout << "Author (tacgia): " << array[i].getTacgia() << "\n";
        cout << "Publisher (nhaxuatban): " << array[i].getNhaxuatban() << "\n";
        cout << "Publication Year (namxuatban): " << array[i].getNamxuatban() << "\n";
        cout << "Genre (theloai): " << array[i].getTheloai() << "\n";
        cout << "Price (giasach): " << array[i].getGiasach() << "\n";
        cout << "Number of Copies (soquyensach): " << array[i].getSoquyensach() << "\n";
        cout << "-------------------------\n";
    }
}


Book* deleteBook(Book*& array, int& n) {
    cout << "Please enter the position of the book to delete (0 to " << n - 1 << "): " << endl;
    int position;
    cin >> position;

    if (position < 0 || position >= n) {
        cout << "Invalid position. Please enter a valid index." << endl;
        return array;
    }

    Book* newArray = new Book[n - 1];

    for (int i = 0; i < position; ++i) {
        newArray[i] = array[i];
    }
    for (int i = position + 1; i < n; ++i) {
        newArray[i - 1] = array[i];
    }

    delete[] array;
    array = newArray;
    --n;

    cout << "Array after deletion:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Book " << i + 1 << ":\n";
        cout << "ISBN: " << array[i].getISBN() << "\n";
        cout << "Title (tensach): " << array[i].getTensach() << "\n";
        cout << "Author (tacgia): " << array[i].getTacgia() << "\n";
        cout << "Publisher (nhaxuatban): " << array[i].getNhaxuatban() << "\n";
        cout << "Publication Year (namxuatban): " << array[i].getNamxuatban() << "\n";
        cout << "Genre (theloai): " << array[i].getTheloai() << "\n";
        cout << "Price (giasach): " << array[i].getGiasach() << "\n";
        cout << "Number of Copies (soquyensach): " << array[i].getSoquyensach() << "\n";
        cout << "-------------------------\n";
    }

    return array;
}


