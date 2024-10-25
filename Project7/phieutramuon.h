#pragma once
#ifndef PHIEUTRAMUON_H
#define PHIEUTRAMUON_H

#include <iostream>
#include <string>

using namespace std;

class phieutramuon {
private:
    int dayofborrow, monthofborrow, yearofborrow;
    int dayofreturn, monthofreturn, yearofreturn;
    int dayofrealreturn, monthofrealreturn, yearofrealreturn;
    string MaDocGia, ISBN;
    int giatien;
    string isLost;  

public:
    // Constructor declarations
    phieutramuon();
    phieutramuon(int dayBorrow, int monthBorrow, int yearBorrow, int dayReturn, int monthReturn, int yearReturn,
        const string& newMaDocGia, const string& newISBN, int price, const string& lostStatus);

    // Getters
    int getDayOfBorrow() const;
    int getMonthOfBorrow() const;
    int getYearOfBorrow() const;
    int getDayOfReturn() const;
    int getMonthOfReturn() const;
    int getYearOfReturn() const;
    int getDayOfRealReturn() const;
    int getMonthOfRealReturn() const;
    int getYearOfRealReturn() const;
    string getMaDocGia() const;
    string getISBN() const;
    int getGiatien() const;
    string getIsLost() const;

    
    void setDayOfBorrow(int day);
    void setMonthOfBorrow(int month);
    void setYearOfBorrow(int year);
    void setDayOfReturn(int day);
    void setMonthOfReturn(int month);
    void setYearOfReturn(int year);
    void setDayOfRealReturn(int day);
    void setMonthOfRealReturn(int month);
    void setYearOfRealReturn(int year);
    void setMaDocGia(const string& newMaDocGia);
    void setISBN(const string& newISBN);
    void setGiatien(int price);
    void setIsLost(const string& status);

    
    double calculateFine() const;

    
    int calculateOverdueDays() const;

private:
    
    int daysBetween(int day1, int month1, int year1, int day2, int month2, int year2) const;
};


phieutramuon* createPhieuTraMuonArray(int& n);
void insertPhieuTraMuon(phieutramuon*& array, int& n);
void deletePhieuTraMuon(phieutramuon*& array, int& n);
void printforfine(phieutramuon* array, int& n);

#endif // PHIEUTRAMUON_H
