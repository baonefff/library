#include "phieutramuon.h"


phieutramuon::phieutramuon()
    : dayofrealreturn(0), monthofrealreturn(0), yearofrealreturn(0), giatien(0), isLost("no") {}

phieutramuon::phieutramuon(int dayBorrow, int monthBorrow, int yearBorrow, int dayReturn, int monthReturn, int yearReturn,
    const string& newMaDocGia, const string& newISBN, int price, const string& lostStatus)
    : dayofborrow(dayBorrow), monthofborrow(monthBorrow), yearofborrow(yearBorrow),
    dayofreturn(dayReturn), monthofreturn(monthReturn), yearofreturn(yearReturn),
    MaDocGia(newMaDocGia), ISBN(newISBN), giatien(price), isLost(lostStatus),
    dayofrealreturn(0), monthofrealreturn(0), yearofrealreturn(0) {}


int phieutramuon::getDayOfBorrow() const { return dayofborrow; }
int phieutramuon::getMonthOfBorrow() const { return monthofborrow; }
int phieutramuon::getYearOfBorrow() const { return yearofborrow; }
int phieutramuon::getDayOfReturn() const { return dayofreturn; }
int phieutramuon::getMonthOfReturn() const { return monthofreturn; }
int phieutramuon::getYearOfReturn() const { return yearofreturn; }
int phieutramuon::getDayOfRealReturn() const { return dayofrealreturn; }
int phieutramuon::getMonthOfRealReturn() const { return monthofrealreturn; }
int phieutramuon::getYearOfRealReturn() const { return yearofrealreturn; }
string phieutramuon::getMaDocGia() const { return MaDocGia; }
string phieutramuon::getISBN() const { return ISBN; }
int phieutramuon::getGiatien() const { return giatien; }
string phieutramuon::getIsLost() const { return isLost; }


void phieutramuon::setDayOfBorrow(int day) { dayofborrow = day; }
void phieutramuon::setMonthOfBorrow(int month) { monthofborrow = month; }
void phieutramuon::setYearOfBorrow(int year) { yearofborrow = year; }
void phieutramuon::setDayOfReturn(int day) { dayofreturn = day; }
void phieutramuon::setMonthOfReturn(int month) { monthofreturn = month; }
void phieutramuon::setYearOfReturn(int year) { yearofreturn = year; }
void phieutramuon::setDayOfRealReturn(int day) { dayofrealreturn = day; }
void phieutramuon::setMonthOfRealReturn(int month) { monthofrealreturn = month; }
void phieutramuon::setYearOfRealReturn(int year) { yearofrealreturn = year; }
void phieutramuon::setMaDocGia(const string& newMaDocGia) { MaDocGia = newMaDocGia; }
void phieutramuon::setISBN(const string& newISBN) { ISBN = newISBN; }
void phieutramuon::setGiatien(int price) { giatien = price; }
void phieutramuon::setIsLost(const string& status) { isLost = status; }


double phieutramuon::calculateFine() const {
    if (isLost == "yes") {
        return giatien * 2;  
    }
    int overdueDays = calculateOverdueDays();
    return (overdueDays > 0) ? overdueDays * 5000 : 0.0;  
}


int phieutramuon::calculateOverdueDays() const {
    int daysBorrowed = daysBetween(dayofborrow, monthofborrow, yearofborrow,
        dayofrealreturn, monthofrealreturn, yearofrealreturn);
    return max(0, daysBorrowed - 7);  
}


int phieutramuon::daysBetween(int day1, int month1, int year1, int day2, int month2, int year2) const {
    int date1 = day1 + month1 * 30 + year1 * 360;
    int date2 = day2 + month2 * 30 + year2 * 360;
    return date2 - date1;
}


phieutramuon* createPhieuTraMuonArray(int& n) {
    cout << "How many borrowing records do you want in your array? " << endl;
    cin >> n;

    phieutramuon* array = new phieutramuon[n];
    for (int i = 0; i < n; ++i) {
        int dayBorrow, monthBorrow, yearBorrow, dayReturn, monthReturn, yearReturn, price;
        string MaDocGia, ISBN, lostStatus;

        cout << "Enter details for borrowing record " << i + 1 << ":\n";
        cout << "Enter Day of Borrow: "; cin >> dayBorrow;
        cout << "Enter Month of Borrow: "; cin >> monthBorrow;
        cout << "Enter Year of Borrow: "; cin >> yearBorrow;
        cout << "Enter Day of Return: "; cin >> dayReturn;
        cout << "Enter Month of Return: "; cin >> monthReturn;
        cout << "Enter Year of Return: "; cin >> yearReturn;
        cout << "Enter MaDocGia: "; cin >> MaDocGia;
        cout << "Enter ISBN: "; cin >> ISBN;
        cout << "Enter Price: "; cin >> price;
        cout << "Is the book lost? (yes/no): "; cin >> lostStatus;
        cout << "-------------------------\n";

        array[i] = phieutramuon(dayBorrow, monthBorrow, yearBorrow, dayReturn, monthReturn, yearReturn,
            MaDocGia, ISBN, price, lostStatus);
    }
    return array;
}


void insertPhieuTraMuon(phieutramuon*& array, int& n) {
    phieutramuon* newArray = new phieutramuon[n + 1];

    for (int i = 0; i < n; ++i) {
        newArray[i] = array[i];
    }

    int dayBorrow, monthBorrow, yearBorrow, dayReturn, monthReturn, yearReturn, price;
    string MaDocGia, ISBN, lostStatus;

    cout << "Enter details for the new borrowing record:\n";
    cout << "Enter Day of Borrow: "; cin >> dayBorrow;
    cout << "Enter Month of Borrow: "; cin >> monthBorrow;
    cout << "Enter Year of Borrow: "; cin >> yearBorrow;
    cout << "Enter Day of Return: "; cin >> dayReturn;
    cout << "Enter Month of Return: "; cin >> monthReturn;
    cout << "Enter Year of Return: "; cin >> yearReturn;
    cout << "Enter MaDocGia: "; cin >> MaDocGia;
    cout << "Enter ISBN: "; cin >> ISBN;
    cout << "Enter Price: "; cin >> price;
    cout << "Is the book lost? (yes/no): "; cin >> lostStatus;

    newArray[n] = phieutramuon(dayBorrow, monthBorrow, yearBorrow, dayReturn, monthReturn, yearReturn,
        MaDocGia, ISBN, price, lostStatus);

    delete[] array;
    array = newArray;
    ++n;
}


void deletePhieuTraMuon(phieutramuon*& array, int& n) {
    int index;
    cout << "Enter the index of the record to delete: ";
    cin >> index;

    if (index < 0 || index >= n) {
        cout << "Invalid index!\n";
        return;
    }

    phieutramuon* newArray = new phieutramuon[n - 1];

    for (int i = 0, j = 0; i < n; ++i) {
        if (i != index) {
            newArray[j++] = array[i];
        }
    }

    delete[] array;
    array = newArray;
    --n;
}

void printforfine(phieutramuon* array, int& n) {
    for (int i = 0; i < n; ++i) {
        double fine = array[i].calculateFine();

        cout << "MaDocGia: " << array[i].getMaDocGia() << endl;
        cout << "ISBN: " << array[i].getISBN() << endl;
        cout << "Borrowed on: " << array[i].getDayOfBorrow() << "/"
            << array[i].getMonthOfBorrow() << "/" << array[i].getYearOfBorrow() << endl;
        cout << "Expected return date: " << array[i].getDayOfReturn() << "/"
            << array[i].getMonthOfReturn() << "/" << array[i].getYearOfReturn() << endl;
        cout << "Book Price: " << array[i].getGiatien() << " VND" << endl;
        cout << "Status: " << array[i].getIsLost() << endl;
        cout << "Fine: " << fine << " VND" << endl;
        cout << "------------------------------------------" << endl;
    }
}


