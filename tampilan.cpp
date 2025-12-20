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
            deleteComp(L, nama);
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
    int choice = -1;
    string nama, genre, negara;

    while (choice != 0) {
        cout << "\n======================== USER MENU ========================\n";
        cout << "1. Tampilkan List\n";        
        cout << "2. Tampilkan Data Composer Berdasarkan Genre\n";      
        cout << "3. Tampilkan Data Composer Berdasarkan Negara\n";          
        cout << "4. Tampilkan Semua Data Music Dalam List\n";         
        cout << "5. Tampilkan Data Music Berdasarkan Genre dari Suatu Composer\n";              
        cout << "6. Tampilkan Semua Music dari Suatu Composer\n"; 
        cout << "7. Composer dengan Music Terbanyak\n"; 
        cout << "0. Exit User Selection\n";
        cout << "============================================================\n";
        cout << "Pilih menu: ";
        cin >> choice;
        cout << endl;
    
        switch (choice){
        case 1: {
            viewList(L);
            break;
        }
        case 2: {
            cout << "Masukkan Genre Composer : ";
            cin >> genre;
            viewCompGenre(L, genre);
            break;
        }
        case 3: {
            cout << "Masukkan Negara Composer : ";
            cin >> negara;
            viewComNegara(L, negara);
            break;
        }
        case 4: {
            viewAllMusic(L);
            break;
        }
        case 5:{
            cout << "Masukkan Nama Composer : ";
            cin >> nama;
            adrCom c = findComp(L, nama);
            if (c != nullptr){
                cout << "Masukkan Genre Music: ";
                cin >> genre;
                viewMusicByGenre(c, genre);
            } else {
                cout << "Composer tidak ditemukan.\n";
            }
            break;
        }
        case 6: {
            cout << "Masukkan Nama Composer: ";
            cin >> nama;
            adrCom c = findComp(L, nama);
            if (c != nullptr){
                showAllMusicFromComposer(c);
            } else {
                cout << "Composer tidak ditemukan.\n";
            }
            break;
        }
        case 7: {
            if (L.first != nullptr){
                mostMadeMusic(L);
            }else{
                cout << "tidak ada composer di dalam list";
            }
            break;
        }
        case 0:{
            cout << "Logout User.\n";
            break;
        }
        default:
            cout << "Pilihan tidak valid.\n";
        }
    }
}

void createDataInput(listCom &L){
    adrCom inputCom;
    adrMusic inputMusic;
    music infoMusic;
    string nama, genre, negara;
    int tahunLahir;

    nama = "Hans_Zimmer";
    tahunLahir = 1957;
    negara = "Jerman";
    genre = "Film_Score";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    nama = "Yiruma";
    tahunLahir = 1978;
    negara = "Korea Selatan";
    genre = "Instrumental";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    nama = "Joe_Hisaishi";
    tahunLahir = 1950;
    negara = "Jepang";
    genre = "Orchestral";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    nama = "Alan_Walker";
    tahunLahir = 1997;
    negara = "Norwegia";
    genre = "EDM";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    nama = "Ludovico";
    tahunLahir = 1955;
    negara = "Italia";
    genre = "Classical";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertByNamaCom(L, inputCom);

    

    infoMusic = music{
        "Time", "Hans_Zimmer", "Film_Score", 2010
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Interstellar_Main_Theme", "Hans_Zimmer", "Film_Score", 2014
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);
    infoMusic = music{
        "River_Flows_in_You", "Yiruma", "Instrumental", 2001
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);
    infoMusic = music{
        "One_Summer's_Day", "Joe_Hisaishi", "Orchestral", 2001
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Merry_Go_Round_of_Life", "Joe_Hisaishi", "Orchestral", 2004
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Faded", "Alan_Walker", "EDM", 2015
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);
    infoMusic = music{
        "Alone", "Alan_Walker", "EDM", 2016
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Nuvole_Bianche", "Ludovico", "Classical", 2004
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Cornfield_Chase", "Hans_Zimmer", "Film_Score", 2014
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Now_We_Are_Free", "Hans_Zimmer", "EDM", 2000
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Kiss_the_Rain", "Yiruma", "Instrumental", 2003
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "May_Be", "Yiruma", "Instrumental", 2001
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Path_of_the_Wind", "Joe_Hisaishi", "Orchestral", 1988
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Princess_Mononoke_Theme", "Joe_Hisaishi", "EDM", 1997
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Ashitaka_and_San", "Yiruma", "Instrumental", 1997
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Kids_Return", "Ludovico", "Jazz", 1996
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Time_(Remix_Version)", "Alan_Walker", "Ambient", 2018
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);

    infoMusic = music{
        "Night", "Ludovico", "Minimalist", 2015
    };
    inputMusic = createMusic(infoMusic);
    inputCom = findComp(L, infoMusic.penyanyi);
    insertByTitle(inputCom, inputMusic);
}