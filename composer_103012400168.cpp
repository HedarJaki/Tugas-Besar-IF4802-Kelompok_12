#include "header.h"
#include <iostream>

using namespace std;

void deleteFirstCom(listCom &L, adrCom &p){
    p = L.first;
    L.first = p->next;
    p->next = nullptr; 
    if (L.first != nullptr){   
        L.first->prev = nullptr;
    }else {
        L.last = nullptr;
    }
}

void deleteLastCom(listCom &L, adrCom &p){
    p = L.last;
    L.last = p->prev;
    p->prev = nullptr;
    if (L.last != nullptr){
        L.last->next = nullptr;
    }else{
        L.first = nullptr;
    }
}

void deleteAfterCom(listCom &L, adrCom q, adrCom &p){
    p = q->next;
    q->next = p->next;
    if (p->next != nullptr){
        p->next->prev = q;
    }else{
        L.last = q;
    }
    p->next = nullptr;
    p->prev = nullptr;
}

adrCom findComp(listCom L, string namaComp){
    adrCom p = L.first;

    while (p != nullptr && p->infoCom.nama != namaComp){
        p = p->next;
    }
 
    if (p == nullptr || p->infoCom.nama != namaComp){
        return nullptr;
    }else {
        return p;
    }
}

void deleteComp(listCom &L, string nama){
   adrCom  p,q;
    p = findComp(L, nama);
    if (L.first == L.last && p == L.first) {
        q = L.first;
        L.first = nullptr;
        L.last = nullptr;
        delete q;
    }else if (p != nullptr){
        if (p == L.first){
            deleteFirstCom(L, q);
            if (q->firstMusic != nullptr){
                deleteAllMusic(q);
            }
            delete q;
        }else if (p == L.last){
            deleteLastCom(L, q);
            if (q->firstMusic != nullptr){
                deleteAllMusic(q);
            }
            delete q;
        }else{
            deleteAfterCom(L, p->prev, q);
            if (q->firstMusic != nullptr){
                deleteAllMusic(q);
            }
            delete q;
        }
        cout << "berhasil dihapus" << endl;
    } else {
        cout << "composer dengan nama{"<<nama << "} tidak ditemukan"<< endl;
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
        p = p->next;
    }
}

void mostMadeMusic(listCom L){
    adrCom temp = L.first;
    adrMusic tempMusic;
    int Music, maxMusic = 0;
    while (temp != nullptr){
        tempMusic = temp->firstMusic;
        Music = countMusic(temp);
        if (Music > maxMusic){
            maxMusic = Music;
        }
        temp = temp->next;
    }
    
    cout << "Composer dengan music terbanyak: " ;
    temp = L.first;
    while (temp != nullptr){
        tempMusic = temp->firstMusic;
        Music = countMusic(temp);
        if (Music == maxMusic){
            cout << temp->infoCom.nama << ", ";
        }
        temp = temp->next;
    }
    cout <<endl << "Jumlah Music: " << maxMusic << endl;
}

void viewList(listCom L){
    adrCom temp = L.first;
    adrMusic tempMusic;
    int count = 1;

    while (temp != nullptr){
        cout << endl;
        cout << endl;
        cout << "Data ke - " << count;
        cout << endl << "-----------------------------------------" << endl;
        cout << "Nama        : " << temp->infoCom.nama << endl;
        cout << "Tahun Lahir : " << temp->infoCom.tahunLahir << endl;
        cout << "negara asal : " << temp->infoCom.negaraAsal << endl;
        cout << "Genre Utama : " << temp->infoCom.genreUtama << endl;
        cout << "music : " ;
        tempMusic = temp->firstMusic;
        while (tempMusic != nullptr){
            cout << tempMusic->infoMusic.judul ;
            if (tempMusic->next != nullptr){
                cout << ", ";
            }
            tempMusic = tempMusic->next;
        }
        temp = temp->next;
        count++;
        cout << endl << "-----------------------------------------" << endl;
    }
}