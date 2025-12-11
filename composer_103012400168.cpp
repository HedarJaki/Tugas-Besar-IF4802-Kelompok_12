#include "header.h"
#include <iostream>

using namespace std;

void deleteFirstCom(listCom &L, adrCom &p){
    p = L.first;
    L.first = p->next;
    p->next = nullptr;
    L.first->prev = nullptr;
}

void deleteLastCom(listCom &L, adrCom &p){
    p = L.last;
    L.last = p->prev;
    L.last->next = nullptr;
    p->prev = nullptr;
}

void deleteAfterCom(listCom &L, adrCom q, adrCom &p){
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
            deleteFirstCom(L, q);
            delete q;
        }else if (p == L.last){
            deleteLastCom(L, q);
            delete q;
        }else{
            deleteAfterCom(L, p->prev, q);
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
            cout << "nama: " << p->infoCom.nama << endl
            <<  "lahir: " << p->infoCom.tahunLahir << endl
            << "Asal: " <<p->infoCom.negaraAsal << endl
            << endl;
        }
    }
}

adrCom mostMadeMusic(listCom L){
    adrCom temp = L.first, mostMadeMusic = nullptr;
    adrMusic tempMusic;
    int Music, maxMusic = 0;
    while (temp != nullptr){
        tempMusic = temp->firstMusic;
        Music = countMusic(temp);
        if (Music > maxMusic){
            mostMadeMusic = temp;
            maxMusic = Music;
        }
        temp = temp->next;
    }

    return mostMadeMusic;
}

void viewList(listCom L){
    adrCom temp = L.first;
    adrMusic tempMusic;

    while (temp != nullptr){
        cout << "Nama        : " << temp->infoCom.nama << endl;
        cout << "Tahun Lahir : " << temp->infoCom.tahunLahir << endl;
        cout << "negara asal : " << temp->infoCom.negaraAsal << endl;
        cout << "Genre Utama : " << temp->infoCom.genreUtama << endl;
        cout << "music : " << endl;
        tempMusic = temp->firstMusic;
        while (tempMusic != nullptr){
            cout << tempMusic->infoMusic.judul << ", ";
            tempMusic = tempMusic->next;
        }
        temp = temp->next;
        cout << "-----------------------------------------" << endl;
    }
}
