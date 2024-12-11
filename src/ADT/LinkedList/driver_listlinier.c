#include <stdio.h>
#include "listlinier.h"

int main() {
    List L1, L2, L3;
    infotype X;

    CreateEmpty(&L1);
    CreateEmpty(&L2);
    CreateEmpty(&L3);

    if (IsEmpty(L1)){ // cek L1 kosong
        printf("y\n");
    }

    InsVFirst(&L1, 10);
    InsVLast(&L1, 20);
    InsVFirst(&L1, 5);
    PrintInfo(L1);


    printf("Menghapus elemen pertama dari L1:\n");
    DelVFirst(&L1, &X);
    PrintInfo(L1);

    printf("Menghapus elemen terakhir dari L1:\n");
    DelVLast(&L1, &X);
    PrintInfo(L1);

    printf("Menambahkan elemen langsung dengan alamat:\n");
    address P = Alokasi(30);
    InsertFirst(&L1, P);
    PrintInfo(L1);

    P = Alokasi(40);
    InsertLast(&L1, P);
    PrintInfo(L1);


    printf("Mencari elemen 30 di L1:\n");
    address found = Search(L1, 30);
    if (found != Nil) {
        printf("Elemen ditemukan: %d\n", Info(found));
    } else {
        printf("Elemen tidak ditemukan.\n");
    }


    printf("Elemen maksimum: %d\n", Max(L1));
    printf("Elemen minimum: %d\n", Min(L1));
    printf("Rata-rata elemen: %.2f\n", Average(L1));


    printf("Invers L1:\n");
    InversList(&L1);
    PrintInfo(L1);

    printf("Membuat L2 dan menggabungkan L1 dan L2 ke L3:\n");
    InsVFirst(&L2, 50);
    InsVLast(&L2, 60);
    PrintInfo(L2);

    Konkat1(&L1, &L2, &L3);
    PrintInfo(L3);

    printf("Menghapus semua elemen dari L3:\n");
    while (!IsEmpty(L3)) {
        DelVFirst(&L3, &X);
        printf("Menghapus elemen: %d\n", X);
    }
    PrintInfo(L3);

    return 0;
}