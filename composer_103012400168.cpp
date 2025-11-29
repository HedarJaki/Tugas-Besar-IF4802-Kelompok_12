#include "composer.h"
#include <iostream>

using namespace std;

void deleteFirst(listCom &L, adrCom &p){
    adrCom p = L.first;
    L.first = p->next;
    p->next = nullptr;
    L.first->prev = nullptr;
}

void deleteLast(listCom &L, adrCom &p){
    adrCom p = L.last;
    L.last = p->prev;
    L.last->next = nullptr;
    p->prev = nullptr;
}

void deleteAfter(listCom &L, adrCom q, adrCom &p){
    p = q->next;
    q->next = p->next;
    p->next->prev = q;
    p->next = nullptr;
    p->prev = nullptr;
}

adrCom findComp(listCom L, string namaComp){
    adrCom p = L.first;

    while (p != nullptr && p->infoCom.nama != namaComp){
        p = p->next;
    }
    
    if (p->infoCom.nama == namaComp){
        return nullptr;
    }else {
        return p;
    }
}

void deleteComp(listCom &L, string namaComp){
    adrCom p = findComp(L, namaComp), q;
    if (p != nullptr) {
        if (p == L.first){
            deleteFirst(L, q);
            delete q;
        }else if (p == L.last){
            deleteLast(L, q);
            delete q;
        }else{
            deleteAfter(L, p->prev, q);
            delete q;
        }

        p = nullptr;
    }
}

void viewCompGenre(listCom L, string genre){
    adrCom p = L.first;
    cout << "data: ";
    while (p != nullptr){
        if (p->infoCom.genreUtama == genre){
            cout << "nama: " << p->infoCom.nama << ", lahir: " << p->infoCom.tahunLahir << "; Asal: " <<p->infoCom.negaraAsal << endl;
        }     
    }
}