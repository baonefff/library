#pragma once
#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <string>
using namespace std;

class People {
private:
    string name;
    string MaDocGia;
    string CMND;
    string NgayThangNamSinh;
    string GioiTinh;
    string email;
    string DiaChi;
    int NamLapThe;
    int NamHethanthe;

public:
    People();

    People(string newname, string newMaDocGia, string newCMND, string newNgayThangNamSinh, string newGioiTinh, string newemail, string newDiachi, int newNamlapthe);
        

    string getName() const;
    string getMaDOCGIA() const;
    string getCMND() const;
    string getNgayThangNamSinh() const;
    string getGioiTinh() const;
    string getEmail() const;
    string getDiaCHi() const;
    int getNamlapthe() const;
    int getNamHethanthe() const;

    void setName(const string& newname);
    void setMaDocGia(const string& newMaDocGia);
    void setCMND(const string& newCMND);
    void setNgayThangNamSinh(const string& newNgayThangNamSinh);
    void setGioiTinh(const string& newGioiTinh);
    void setEmail(const string& newEmail);
    void setDiaChi(const string& newDiaChi);
    void setNamLapThe(int newNamlapthe);
};

People* createarray(int& n);

void insets(People*& array, int& n);

People* deletion(People*& array, int& n);
People* searching(People* array, int& n);

People* edit(People* array, int& n);

People* prinf(People* array, int& n);
#endif // !PEOPLE_H
