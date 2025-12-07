#ifndef COMPOSER_H_INCLUDED
#define COMPOSER_H_INCLUDED
#include <iostream>
using namespace std;


//ADT composer
typedef struct elemenComposer *adrCom;
struct composer{
    string nama;
    int tahunLahir;
    string genreUtama;
    string negaraAsal;
};
struct elemenComposer {
    composer infoCom;
    adrCom next;
    adrCom prev;
    adrMusic firstMusic;
};
struct listCom {
    adrCom first;
    adrCom last;
};


//ADT music
typedef struct elemenMusic *adrMusic;
struct music{
    string judul;
    string penyanyi;
    string genre;
    int tahunTerbit;
};
struct elemenMusic {
    music infoMusic;
    adrMusic next;
};


void createList(listCom &L);
adrCom createComposer(string nama, int tahun, string genre, string negara);
void insertFirst(listCom &L, adrCom p);
void insertLast(listCom &L, adrCom p);
void insertAfter(listCom &L, adrCom prec, adrCom p);
void viewComNegara(listCom L, string negara);
void deleteFirst(listCom &L, adrCom &p);
void deleteLast(listCom &L, adrCom &p);
void deleteAfter(listCom &L, adrCom q, adrCom &p);
adrCom findComp(listCom L, string namaComp);
void deleteComp(listCom &L, string namaComp);
void viewCompGenre(listCom L, string genre);
#endif // COMPOSER_H_INCLUDED
