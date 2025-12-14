#include <iostream>
#include "header.h"
#include "tampilan.cpp"
using namespace std;

int main()
{
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
    genre = "pop";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    nama = "felly";
    tahunLahir = 1999;
    negara = "purbalingga";
    genre = "jazz";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    nama = "hapiz";
    tahunLahir = 1980;
    negara = "malang";
    genre = "rock";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    nama = "aga";
    tahunLahir = 2000;
    negara = "garut";
    genre = "rock";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    nama = "radit";
    tahunLahir = 1970;
    negara = "bali";
    genre = "pop";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);
    
    // cin >> nama;
    // inputCom = findComp(L, nama);
    // cout << inputCom->infoCom.nama;
    viewList(L);
    int mainChoice = -1;
    while (true)
    {
        cout << "\n======= MAIN MENU =======\n";
        cout << "1. Login as Admin\n";
        cout << "2. Login as User\n";
        cout << "0. Exit\n";
        cout << "==========================\n";
        cout << "Pilih Opsi: ";
        cin >> mainChoice;
        cout << endl;
        switch (mainChoice)
        {
        case 1:
            isDone = true;
            while (isDone)
            {            
                mainChoice = -1;
                cout << "\n========= ADMIN =========\n";
                cout << "1. insert composer\n";
                cout << "2. insert music\n";
                cout << "3. delete composer\n";
                cout << "4. delete music\n";
                cout << "0. Exit Admin section\n";
                cout << "===========================\n";
                cout << "Pilih Opsi: ";
                cin >> mainChoice;
                cout << endl;
                switch (mainChoice)
                {
                case 1:
                    cout << "nama :";
                    cin >> nama;
                    cout << "tahun lahir : ";
                    cin >> tahunLahir;
                    cout << "asal negara :";
                    cin >> negara;
                    cout << "genre utama : ";
                    cin >> genre;
                    inputCom = createComposer(nama, tahunLahir, genre, negara);
                    insertByNamaCom(L, inputCom);
                    cout << endl;
                case 2:
                    cout << "judul :";
                    cin >> infoMusic.judul;
                    cout << "penyanyi : ";
                    cin >> infoMusic.penyanyi;
                    cout << "genre :";
                    cin >> infoMusic.genre;
                    cout << "tahun terbit : ";
                    cin >> infoMusic.tahunTerbit;
                    cout << endl;
                    inputMusic = createMusic(infoMusic);
                    cout << "nama composer : ";
                    cin >> nama;
                    inputCom = findComp(L, nama);
                    if (inputCom != nullptr){
                        insertByTitle(inputCom, inputMusic);
                    }else{
                        cout << "tidak ada composer dengan nama '" << nama <<"'.\n"; 
                    }
                case 3:
                    cout << "input nama composer yang ingin di hapus : ";
                    cin >> nama;
                    inputCom = findComp(L, nama);
                    if (inputCom != nullptr){
                        deleteComp(L, inputCom);
                    }else{
                        cout << "tidak ada composer dengan nama '" << nama <<"'.\n"; 
                    }
                case 4:
                    cout << "input judul music yang ingin di hapus : ";
                    cin >> judulMusic;
                    cout << "nama composer penghasil music : ";
                    cin >> nama;
                    inputCom = findComp(L, nama);
                    cout << "p\n";
                    if (inputCom != nullptr){
                        deleteMusicByJudul(inputCom, judulMusic);
                    }else{
                        cout << "tidak ada composer dengan nama '" << nama <<"'.\n"; 
                    }
                case 0:
                    isDone = false;
                default:
                    cout << "input tidak valid";
                }
            }
        case 2:
            mainChoice = -1;
            cout << "\n==================== USER ====================\n";
            cout << "1. Menampilkan seluruh list\n";
            cout << "2. menampilkan composer berdasarkan genre utama\n";
            cout << "3. menampilkan composer berdasarkan negara asal\n";
            cout << "4. menampilkan music berdasarkan genre \n";
            cout << "================================================\n";
            cout << "Pilih Opsi: ";
            cin >> mainChoice;
            cout << endl;
        case 0:
            return 0;
        default:
            cout << "Input tidak valid\n";
        }
    }
}
