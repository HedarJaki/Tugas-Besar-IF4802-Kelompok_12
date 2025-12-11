#include <iostream>
#include "header.h"
using namespace std;

void createListCom(listCom &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrCom createComposer(string nama, int tahun, string genre, string negara){
    adrCom p = new elemenComposer;

    p->infoCom.nama = nama;
    p->infoCom.tahunLahir = tahun;
    p->infoCom.genreUtama = genre;
    p->infoCom.negaraAsal = negara;

    p->next = nullptr;
    p->prev = nullptr;
    p->firstMusic = nullptr;

    return p;
}

void insertFirstCom(listCom &L, adrCom p){
    if (L.first == nullptr){
        L.first = p;
        L.last = p;
    }else{
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertLastCom(listCom &L, adrCom p){
    if (L.first == nullptr){
        L.first = p;
        L.last = p;
    }else{
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

void insertAfterCom(listCom &L, adrCom prec, adrCom p){
    if (prec->next == nullptr){
        insertLastCom(L, p);
    }else{
        p->next = prec->next;
        p->prev = prec;
        prec->next->prev = p;
        prec->next = p;
    }
}

void insertByNamaCom(listCom &L, adrCom p){
    if (L.first == nullptr){
        L.first = p;
        L.last = p;
    }else if (p->infoCom.nama < L.first->infoCom.nama){
        insertFirstCom(L, p);
    }else if (p->infoCom.nama > L.last->infoCom.nama){
        insertLastCom(L, p);
    }else{
        adrCom q = L.first;
        while (q->next != NULL && q->next->infoCom.nama < p->infoCom.nama) {
        q = q->next;
       }
       insertAfterCom(L, q, p);
    }
}

void viewComNegara(listCom L, string negara){
    adrCom p = L.first;
    bool found = false;

     cout << "Daftar Composer dari negara " << negara << ": " <<endl;
     cout << "-----------------------------------------" << endl;

     while (p != nullptr){
        if (p->infoCom.negaraAsal == negara){
            found = true;
            cout << "Nama        : " << p->infoCom.nama << endl;
            cout << "Tahun Lahir : " << p->infoCom.tahunLahir << endl;
            cout << "Genre Utama : " << p->infoCom.genreUtama << endl;
            cout << "-----------------------------------------" << endl;
        }
        p = p->next;
     }

     if (!found){
        cout << "Tidak ada composer dari negara tersebut" << endl;
     }
}

int totalMusic(listCom L) {
    adrCom p = L.first;
    int total = 0;
    while (p != nullptr) {
        total += countMusic(p);
        p = p->next;
    }
    return total;
}