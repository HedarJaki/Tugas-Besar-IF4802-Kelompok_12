#include <iostream>
#include "header.h"
#include "tampilan.cpp"
using namespace std;

int main()
{
    listCom L;
    adrCom inputCom;
    adrMusic inputMusic;
    music infoMusic;
    createListCom(L);
    string nama, negara, genre;
    int tahunLahir;
    menuAdmin();
    nama = "afi";
    tahunLahir = 2000;
    negara = "cirebon";
    genre = "pop";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertFirstCom(L, inputCom);

    nama = "felly";
    tahunLahir = 1999;
    negara = "purbalingga";
    genre = "jazz";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertFirstCom(L, inputCom);

    nama = "hapiz";
    tahunLahir = 1980;
    negara = "malang";
    genre = "rock";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertLastCom(L, inputCom);

    nama = "aga";
    tahunLahir = 2000;
    negara = "garut";
    genre = "rock";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertLastCom(L, inputCom);

    nama = "radit";
    tahunLahir = 1970;
    negara = "bali";
    genre = "pop";
    inputCom = createComposer(nama, tahunLahir, genre, negara);
    insertAfterCom(L, L.first, inputCom);
    
    viewList(L);
    return 0;
}
