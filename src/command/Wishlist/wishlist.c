#include <stdio.h>
#include "wishlist.h"
#include "../../ADT/Mesin/mesinkata.h"

void wishlistAdd(List *L, ListBarang *listbarang){
    printf("Masukkan nama barang: ");
    STARTINPUTWORD();
    Word CurrentWord;

    char barang = WordToString(CurrentWord);

    if (!IsBarangExist(listbarang, &barang)){
        printf("Tidak ada barang dengan nama %s\n", barang);
    }

    else{
        address found = Search(*L, &barang);
        if (found == Nil){
            printf("%s sudah ada di wishlist!\n", barang);
        }

        else{
            InsVLast(L, &barang);
            printf("Berhasil menambahkan %s ke wishlist!\n", barang);
        }
    }
}

void wishlistSwap(List *L, int idx1, int idx2){

}

void wishlistRemove(List *L){
    Word CurrentWord;

    wishlistShow(*L);
    printf("Pilih metode penghapusan (nomor/nama barang):");
    STARTINPUTWORD();
    char metode = WordToString(CurrentWord);

    if (metode == "nomor"){
        printf(">>WISHLIST REMOVE ");
        STARTINPUTWORD();
        char idx = WordToString(CurrentWord);
        int  nomor = idx - '0';

        if (IsEmpty(*L)){
            printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        }

        else{
            if (nomor>0 && nomor<=NbElmt(*L)){
                DelP(L, idx);
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
        char barang = WordToString(CurrentWord);
        
        address found = Search(*L, &barang);
        if (found == Nil){
            printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!", barang);
        }

        else{
            DelP(L, &barang);
            printf("%s berhasil dihapus dari WISHLIST!", barang);
        }
    }
}

void wishlistClear(List L, infotype barang){
    if (!IsEmpty(L)){
        while (!IsEmpty(L)){
        DelVFirst(&L, &barang);
        }
        printf("Wishlist telah dikosongkan.\n");
    }
}

void wishlistShow(List L){
    if (IsEmpty(L)){
        printf("Wishlist kosong.\n");
    }

    else{
        printf("Berikut adalah isi wishlist-mu:\n");
        
        for (int i=0; i<NbElmt(L); i++){
            printf("%d ", i+1);
        }
    }
}