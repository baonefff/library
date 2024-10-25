#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string ISBN;
    string tensach;
    string tacgia;
    string nhaxuatban;
    string namxuatban;
    string theloai;
    int giasach;
    int soquyensach;

public:
    Book();

    Book(string newISBN, string newTensach, string newTacgia, string newNhaxuatban, string newNamxuatban, string newTheloai, int newGiasach, int newSoquyensach);

    string getISBN() const;
    string getTensach() const;
    string getTacgia() const;
    string getNhaxuatban() const;
    string getNamxuatban() const;
    string getTheloai() const;
    int getGiasach() const;
    int getSoquyensach() const;

    void setISBN(const string& newISBN);
    void setTensach(const string& newTensach);
    void setTacgia(const string& newTacgia);
    void setNhaxuatban(const string& newNhaxuatban);
    void setNamxuatban(const string& newNamxuatban);
    void setTheloai(const string& newTheloai);
    void setGiasach(int newGiasach);
    void setSoquyensach(int newSoquyensach);
};

Book* createBookArray(int& n);
void insertBook(Book*& array, int& n);
Book* deleteBook(Book*& array, int& n);
Book* searching(Book*& array, int& n);

#endif // BOOK_H
