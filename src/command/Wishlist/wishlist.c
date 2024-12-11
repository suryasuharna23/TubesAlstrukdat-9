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
        address_list found = Search(*L, *barang);
        if (found != Nol){
            printf("%s sudah ada di wishlist!\n", barang);
        }

        else{
            InsVLast(L, *barang);
            printf("Berhasil menambahkan %s ke wishlist!\n", barang);
        }
    }
}

void wishlistSwap(List *L, int idx1, int idx2){
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
    Word CurrentWord;

    wishlistShow(*L);
    printf("Pilih metode penghapusan (nomor/nama barang):");
    STARTINPUTWORD();
    char *metode = WordToString(CurrentWord);

    if (metode == "nomor"){
        printf(">>WISHLIST REMOVE ");
        STARTINPUTWORD();
        char *idx = WordToString(CurrentWord);
        int  nomor = *idx - '0';

        if (IsEmptyList(*L)){
            printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        }

        else{
            if (nomor>0 && nomor<=NbElmt(*L)){
                DelP(L, *idx);
                printf("Berhasil menghapus barang posisi ke-%s dari wishlist!", idx);
            }

            else if (nomor>NbElmt(*L)){
                printf("Penghapusan barang WISHLIST gagal dilakukan, tidak ada Barang di posisi ke-%s!", idx);
            }
    
            else{
                printf("Penghapusan barang WISHLIST gagal dilakukan, input tidak valid!");
            }
        }
        
    }

    else if (metode == "nama barang"){
        printf("Masukkan nama barang yang akan dihapus: ");
        STARTINPUTWORD();
        char *barang = WordToString(CurrentWord);
        
        address_list found = Search(*L, *barang);
        if (found == Nol){
            printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!", barang);
        }

        else{
            DelP(L, *barang);
            printf("%s berhasil dihapus dari WISHLIST!", barang);
        }
    }
}

void wishlistClear(List L, infotypes barang){
    if (!IsEmptyList(L)){
        while (!IsEmptyList(L)){
            DelVFirst(&L, &barang);
        }
        printf("Wishlist telah dikosongkan.\n");
    }
}

void wishlistShow(List L){
    if (IsEmptyList(L)){
        printf("Wishlist kosong.\n");
    }

    else{
        printf("Berikut adalah isi wishlist-mu:\n");
        
        for (int i=0; i<NbElmt(L); i++){
            printf("%d ", i+1);
        }
    }
}