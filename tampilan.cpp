#include <iostream>
#include "header.h"
using namespace std;

void adminMenu(listCom &L) {
    int choice = -1;

    while (choice != 0) {
        cout << "\n========= ADMIN MENU =========\n";
        cout << "1. Insert Composer\n";        
        cout << "2. Delete Composer\n";      
        cout << "3. Insert Music\n";          
        cout << "4. Delete Music\n";         
        cout << "5. View Semua Composer\n";              
        cout << "6. Komputasi: Composer Terproduktif\n"; 
        cout << "0. Exit Admin Selection\n";
        cout << "==============================\n";
        cout << "Pilih menu: ";
        cin >> choice;
        cout << endl;
    
        switch (choice){
        case 1: {
            cout << "\n==== Masukkan Data Composer ====\n";

            composer c;
            cout << "Nama Composer: ";
            cin >> c.nama;
            cout << "Tahun Lahir: ";
            cin >> c.tahunLahir;
            cout << "Genre Utama: ";
            cin >> c.genreUtama;
            cout << "Negara Asal: ";
            cin >> c.negaraAsal;

            adrCom p = createComposer(
                c.nama,
                c.tahunLahir,
                c.genreUtama,
                c.negaraAsal
            );

            insertByNamaCom(L, p);
            cout << "Composer berhasil ditambahkan.\n";
            break;
        }
        case 2: {
            string nama;
            cout << "Nama composer yang ingin dihapus: ";
            cin >> nama;
            adrCom c = findComp(L, nama);
            if (c != nullptr){
                deleteComp(L, c);
            }else{
                cout << "Composer tidak ditemukan.\n";
            }
            break;
        }
        case 3: {
            string nama;
            cout << "Nama Composer: ";
            cin >> nama;

            adrCom c = findComp(L, nama);
            if (c == nullptr) {
                cout << "Composer tidak ditemukan.\n";
                break;
            }

            music m;
            cout << "Judul Music: ";
            cin >> m.judul;
            cout << "Penyanyi: ";
            cin >> m.penyanyi;
            cout << "Genre: ";
            cin >> m.genre;
            cout << "Tahun Terbit: ";
            cin >> m.tahunTerbit;

            adrMusic q = createMusic(m);
            insertByTitle(c, q);
            cout << "Music berhasil ditambahkan.\n";
            break;
        }
        case 4: {
            string nama, judul;
            cout << "Nama Composer Penghasil Music: ";
            cin >> nama;
            adrCom c = findComp(L, nama);

            if (c == nullptr) {
                cout << "Composer tidak ditemukan.\n";
                break;
            }

            cout << "Judul Music yang dihapus: ";
            cin >> judul;
            deleteMusicByJudul(c, judul);
            break;
        }
        case 5:{
            viewList(L);
            break;
        }
        case 6: {
            adrCom p = mostMadeMusic(L);
            if (p != nullptr) {
                cout << "Composer dengan music terbanyak:\n";
                cout << "Nama: " << p->infoCom.nama << endl;
                cout << "Jumlah Music: " << countMusic(p) << endl;
            }
            break;
        }
        case 0:{
            cout << "Logout Admin.\n";
            break;
        }
        default:
            cout << "Pilihan tidak valid.\n";
        }
    }
}

void userMenu(listCom &L){
}
