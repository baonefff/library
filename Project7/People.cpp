#include "People.h"

People::People() = default;
People::People(string newname, string newMaDocGia, string newCMND, string newNgayThangNamSinh, string newGioiTinh, string newemail, string newDiachi, int newNamlapthe)
    : name(newname), MaDocGia(newMaDocGia), CMND(newCMND), NgayThangNamSinh(newNgayThangNamSinh), GioiTinh(newGioiTinh), email(newemail), DiaChi(newDiachi), NamLapThe(newNamlapthe) {
    NamHethanthe = NamLapThe + 2;
}

string People:: getName() const { return name; }
string People::getMaDOCGIA() const { return MaDocGia; }
string People::getCMND() const { return CMND; }
string People::getNgayThangNamSinh() const { return NgayThangNamSinh; }
string People::getGioiTinh() const { return GioiTinh; }
string People::getEmail() const { return email; }
string People::getDiaCHi() const { return DiaChi; }
int People:: getNamlapthe() const { return NamLapThe; }
int People:: getNamHethanthe() const { return NamHethanthe; }

void People:: setName(const string& newname) { name = newname; }
void People:: setMaDocGia(const string& newMaDocGia) { MaDocGia = newMaDocGia; }
void People:: setCMND(const string& newCMND) { CMND = newCMND; }
void People::setNgayThangNamSinh(const string& newNgayThangNamSinh) { NgayThangNamSinh = newNgayThangNamSinh; }
void People::setGioiTinh(const string& newGioiTinh) { GioiTinh = newGioiTinh; }
void People::setEmail(const string& newEmail) { email = newEmail; }
void People::setDiaChi(const string& newDiaChi) { DiaChi = newDiaChi; }
void People::setNamLapThe(int newNamlapthe) {
    NamLapThe = newNamlapthe;
    NamHethanthe = NamLapThe + 2;
}

People* createarray(int& n) {
    cout << "How many people do you want in your array? " << endl;
    cin >> n;

   
    People* array = new People[n];

    
    for (int i = 0; i < n; ++i) {
        string name, MaDocGia, CMND, NgayThangNamSinh, GioiTinh, email, DiaChi;
        int NamLapThe;

        cout << "Enter details for person " << i + 1 << ":\n";
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter MaDocGia: ";
        cin >> MaDocGia;
        cout << "Enter CMND: ";
        cin >> CMND;
        cout << "Enter NgayThangNamSinh: ";
        cin >> NgayThangNamSinh;
        cout << "Enter GioiTinh: ";
        cin >> GioiTinh;
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter DiaChi: ";
        cin >> DiaChi;
        cout << "Enter NamLapThe: ";
        cin >> NamLapThe;
        cout << "-------------------------\n";

        
        array[i] = People(name, MaDocGia, CMND, NgayThangNamSinh, GioiTinh, email, DiaChi, NamLapThe);
    }

    cout << "Input complete.\n";
    return array;  
}

void insets(People*& array, int& n) {
    People* newarray = new People[n + 1];
    cout << "Please enter position of where you want to add new people (0 to " << n << "): " << endl;
    int posion;
    cin >> posion;

    
    if (posion < 0 || posion > n) {
        cout << "Invalid position. Please enter a value between 0 and " << n << "." << endl;
        delete[] newarray; 
        return;
    }

    string name, MaDocGia, CMND, NgayThangNamSinh, GioiTinh, email, DiaChi;
    int NamLapThe;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter MaDocGia: ";
    cin >> MaDocGia;
    cout << "Enter CMND: ";
    cin >> CMND;
    cout << "Enter NgayThangNamSinh: ";
    cin >> NgayThangNamSinh;
    cout << "Enter GioiTinh: ";
    cin >> GioiTinh;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter DiaChi: ";
    cin >> DiaChi;
    cout << "Enter NamLapThe: ";
    cin >> NamLapThe;

    newarray[posion] = People(name, MaDocGia, CMND, NgayThangNamSinh, GioiTinh, email, DiaChi, NamLapThe);

    for (int i = 0; i < posion; ++i) {
        newarray[i] = array[i];
    }
    for (int i = posion; i < n; ++i) {
        newarray[i + 1] = array[i];
    }

    delete[] array;
    array = newarray;
    ++n;

    cout << "Array after insertion:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Person " << i + 1 << ":\n";
        cout << "Name: " << array[i].getName() << "\n";
        cout << "MaDocGia: " << array[i].getMaDOCGIA() << "\n";
        cout << "CMND: " << array[i].getCMND() << "\n";
        cout << "NgayThangNamSinh: " << array[i].getNgayThangNamSinh() << "\n";
        cout << "GioiTinh: " << array[i].getGioiTinh() << "\n";
        cout << "Email: " << array[i].getEmail() << "\n";
        cout << "DiaChi: " << array[i].getDiaCHi() << "\n";
        cout << "NamLapThe: " << array[i].getNamlapthe() << "\n";
        cout << "NamHethanThe: " << array[i].getNamHethanthe() << "\n";
        cout << "-------------------------\n"; 
    }
}

People* deletion(People*& array, int& n) {
    cout << "Please enter the position of the person to delete (0 to " << n - 1 << "): " << endl;
    int posi;
    cin >> posi;

    // Validate position
    if (posi < 0 || posi >= n) {
        cout << "Invalid position. Please enter a valid index." << endl;
        return array; 
    }

    People* newarray = new People[n - 1];

    for (int i = 0; i < posi; ++i) {
        newarray[i] = array[i];
    }
    for (int i = posi + 1; i < n; ++i) {
        newarray[i - 1] = array[i];
    }

    delete[] array;
    array = newarray;
    --n;

    cout << "Array after deletion:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Person " << i + 1 << ":\n";
        cout << "Name: " << array[i].getName() << "\n";
        cout << "MaDocGia: " << array[i].getMaDOCGIA() << "\n";
        cout << "CMND: " << array[i].getCMND() << "\n";
        cout << "NgayThangNamSinh: " << array[i].getNgayThangNamSinh() << "\n";
        cout << "GioiTinh: " << array[i].getGioiTinh() << "\n";
        cout << "Email: " << array[i].getEmail() << "\n";
        cout << "DiaChi: " << array[i].getDiaCHi() << "\n";
        cout << "NamLapThe: " << array[i].getNamlapthe() << "\n";
        cout << "NamHethanThe: " << array[i].getNamHethanthe() << "\n";
        cout << "-------------------------\n"; 
    }

    return array; 
}
People* searching(People* array, int& n) {
    string name;
    cin >> name;
    for (int i = 0; i < n; ++i) {
        if (array[i].getName() == name) {
            cout << " Found!!!!" << endl;
            cout << "Person " << i + 1 << ":\n";
            cout << "Name: " << array[i].getName() << "\n";
            cout << "MaDocGia: " << array[i].getMaDOCGIA() << "\n";
            cout << "CMND: " << array[i].getCMND() << "\n";
            cout << "NgayThangNamSinh: " << array[i].getNgayThangNamSinh() << "\n";
            cout << "GioiTinh: " << array[i].getGioiTinh() << "\n";
            cout << "Email: " << array[i].getEmail() << "\n";
            cout << "DiaChi: " << array[i].getDiaCHi() << "\n";
            cout << "NamLapThe: " << array[i].getNamlapthe() << "\n";
            cout << "NamHethanThe: " << array[i].getNamHethanthe() << "\n";
            cout << "-------------------------\n";
        }
        else {
            cout << "Please type again" << endl;
        }
    }
    return array;
}

People* edit(People* array, int& n) {
    string name;
    cin >> name;
    string newName, newMaDocGia, newCMND, newNgayThangNamSinh, newGioiTinh, newEmail, newDiaChi;
    int newNamLapThe;
    cout << " Please enter the people you want to edit " << endl;
    for (int i = 0; i < n; ++i) {
        if (array[i].getName() == name) {
            cout << "Enter new Name (current: " << array[i].getName() << "): ";
            cin >> newName;
            cout << "Enter new MaDocGia (current: " << array[i].getMaDOCGIA() << "): ";
            cin >> newMaDocGia;
            cout << "Enter new CMND (current: " << array[i].getCMND() << "): ";
            cin >> newCMND;
            cout << "Enter new NgayThangNamSinh (current: " << array[i].getNgayThangNamSinh() << "): ";
            cin >> newNgayThangNamSinh;
            cout << "Enter new GioiTinh (current: " << array[i].getGioiTinh() << "): ";
            cin >> newGioiTinh;
            cout << "Enter new Email (current: " << array[i].getEmail() << "): ";
            cin >> newEmail;
            cout << "Enter new DiaChi (current: " << array[i].getDiaCHi() << "): ";
            cin >> newDiaChi;
            cout << "Enter new NamLapThe (current: " << array[i].getNamlapthe() << "): ";
            cin >> newNamLapThe;

            array[i].setName(newName);
            array[i].setMaDocGia(newMaDocGia);
            array[i].setCMND(newCMND);
            array[i].setNgayThangNamSinh(newNgayThangNamSinh);
            array[i].setGioiTinh(newGioiTinh);
            array[i].setEmail(newEmail);
            array[i].setDiaChi(newDiaChi);
            array[i].setNamLapThe(newNamLapThe);
            cout << "-------------------------\n";
        }
        else {
            cout << "Please type again" << endl;
        }

    }return array;
}

People* prinf(People* array, int& n) {
    for (int i = 0; i < n; ++i) {
        cout << "Person " << i + 1 << ":\n";
        cout << "Name: " << array[i].getName() << "\n";
        cout << "MaDocGia: " << array[i].getMaDOCGIA() << "\n";
        cout << "CMND: " << array[i].getCMND() << "\n";
        cout << "NgayThangNamSinh: " << array[i].getNgayThangNamSinh() << "\n";
        cout << "GioiTinh: " << array[i].getGioiTinh() << "\n";
        cout << "Email: " << array[i].getEmail() << "\n";
        cout << "DiaChi: " << array[i].getDiaCHi() << "\n";
        cout << "NamLapThe: " << array[i].getNamlapthe() << "\n";
        cout << "NamHethanThe: " << array[i].getNamHethanthe() << "\n";
        cout << "-------------------------\n";

    }
    return array;
}