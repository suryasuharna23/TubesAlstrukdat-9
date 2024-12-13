#include <stdio.h>
#include "wishlist.h"
#include "../../ADT/Mesin/mesinkata.h"

void wishlistAdd(List *L, ListBarang *listbarang){
    printf("Masukkan nama barang: ");
    STARTINPUTWORD();

    char *barang = WordToString(CurrentWord);

    if (!IsBarangExist(listbarang, barang)){
        printf("Tidak ada barang dengan nama %s\n", barang);
    }

    else{
        address_list found = Search(*L, barang);
        if (found != Nol){
            printf("%s sudah ada di wishlist!\n", barang);
        }

        else{
            InsVLast(L, barang);
            printf("Berhasil menambahkan %s ke wishlist!\n", barang);
        }
    }
}

void wishlistSwap(List *L){
    Word id1, id2;

    printf("Masukkan 1 posisi barang: ");
    STARTINPUTWORD();
    char *nomor1 = WordToString(CurrentWord);
    int idx1 = *nomor1 - '0';

    printf("Masukkan posisi barang yang ingin ditukar dengan input sebelumnya: ");
    STARTINPUTWORD();
    char *nomor2 = WordToString(CurrentWord);
    int idx2 = *nomor2 - '0';

    if (idx1 > 0 && idx2 > 0 && idx1 <= NbElmt(*L) && idx2 <= NbElmt(*L)) {
        address_list P1 = First(*L);
        address_list P2 = First(*L);
        for (int i = 1; i < idx1; i++) {
            P1 = Next(P1);
        }
        for (int i = 1; i < idx2; i++) {
            P2 = Next(P2);
        }
        infotypes temp = Info(P1);
        Info(P1) = Info(P2);
        Info(P2) = temp;
        printf("Berhasil menukar posisi %d dan %d di wishlist!\n", idx1, idx2);
    }
    else {
        printf("Indeks tidak valid!\n");
    }
}

void wishlistRemove(List *L){
    if (IsEmptyList(*L)){
        wishlistShow(*L);
        return;
    }

    else{
        wishlistShow(*L);

        printf("Pilih metode penghapusan (nomor/nama barang): ");
        STARTINPUTWORD();

        if (isEqual(CurrentWord, "nomor")){
            printf(">>WISHLIST REMOVE ");
            STARTINPUTWORD();
            char *idx = WordToString(CurrentWord);
            
            // cek input valid
            int nomor = 0;
            int isValidNumber = 1;
            for (int i = 0; idx[i] != '\0'; i++) {
                if (idx[i] < '0' || idx[i] > '9') {
                    isValidNumber = 0;
                    break;
                }
                nomor = nomor * 10 + (idx[i] - '0');
            }

            if (!isValidNumber) {
                printf("Input tidak valid! Harap masukkan angka.\n");
                return;
            }

            if (IsEmptyList(*L)){
                printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
            }

            else{
                if (nomor>0 && nomor<=NbElmt(*L)){
                    address_list P = First(*L);
                    for (int i = 1; i < nomor; i++) {
                        P = Next(P);
                    }
                    DelP(L, Info(P));
                    printf("Berhasil menghapus barang posisi ke-%s dari wishlist!\n", idx);
                }

                else if (nomor>NbElmt(*L)){
                    printf("Penghapusan barang WISHLIST gagal dilakukan, tidak ada Barang di posisi ke-%s!\n", idx);
                }
            }  
        }

        else if (isEqual(CurrentWord, "nama barang")){
            printf("Masukkan nama barang yang akan dihapus: ");
            STARTINPUTWORD();
            char *barang = WordToString(CurrentWord);
            
            address_list found = Search(*L, barang);
            if (found == Nol){
                printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!", barang);
            }

            else{
                DelP(L, barang);
                printf("%s berhasil dihapus dari WISHLIST!", barang);
            } 
        }
    }
}

void wishlistClear(List *L){
    infotypes barang;
    while (!IsEmptyList(*L)){
        DelVFirst(L, &barang);
    }
    printf("Wishlist telah dikosongkan.\n");
}

void wishlistShow(List L){
    if (IsEmptyList(L)){
        printf("Wishlist kosong.\n");
    }

    else{
        printf("Berikut adalah isi wishlist-mu:\n");
        PrintInfo(L);
    }
}