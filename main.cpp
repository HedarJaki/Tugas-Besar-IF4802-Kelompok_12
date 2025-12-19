#include <iostream>
#include "header.h"
#include "tampilan.cpp"
using namespace std;

int main(){
    listCom L;
    adrCom inputCom; // menyimpan alamat elemen composer baru atau hasil pencarian
    adrMusic inputMusic; // menyimpan alamat elemen composer baru atau hasil pencarian
    music infoMusic; // data music yang ingin di input
    createListCom(L);
    bool isDone; // kondisi berhenti loop
    string nama, negara, genre, judulMusic; //univarsal
    int tahunLahir;
    
    nama = "afi";
    tahunLahir = 2000;
    negara = "cirebon";
    genre = "swiss";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    nama = "felly";
    tahunLahir = 1999;
    negara = "Amerika Serikat";
    genre = "jazz";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    nama = "hapiz";
    tahunLahir = 1980;
    negara = "Uganda";
    genre = "rock";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    nama = "aga";
    tahunLahir = 2000;
    negara = "Indonesia";
    genre = "rock";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    nama = "radit";
    tahunLahir = 1970;
    negara = "India";
    genre = "pop";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);
    



    int mainChoice = -1;
    while (mainChoice != 0) {
        cout << "\n========= MAIN MENU =========\n";
        cout << "1. Login as Admin\n";
        cout << "2. Login as User\n";
        cout << "0. Exit\n";
        cout << "=============================\n";
        cout << "Pilih menu: ";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            adminMenu(L);
            break;
        case 2:
            userMenu(L);
            break;
        case 0:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    // viewList(L);
    return 0;
    }
}