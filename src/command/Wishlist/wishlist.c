#include <stdio.h>
#include "wishlist.h"
#include "../../ADT/Mesin/mesinkata.h"

void PrintWishlist(List L) {
    if (IsEmptyList(L)) {
        printf("Wishlist kosong.\n");
    } else {
        printf("Berikut adalah isi wishlist-mu:\n");
        printf("+------------+----------------+\n");
        printf("| No         | Nama Barang    |\n");
        printf("+------------+----------------+\n");
        int i = 1;
        address_list P = First(L);
        while (P != Nol) {
            printf("| %-10d | %-14s |\n", i, Info(P));
            P = Next(P);
            i++;
        }
        printf("+------------+----------------+\n");
    }
}

void wishlistAdd(List *L, ListBarang *listbarang) {
    while (true) {
        PrintWishlist(*L);
        printf("Masukkan nama barang (atau ketik 'BACK' untuk kembali): ");
        STARTINPUTWORD();

        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu sebelumnya.\n");
            return;
        }

        char *barang = WordToString(CurrentWord);

        if (!IsBarangExist(listbarang, barang)) {
            printf("Tidak ada barang dengan nama %s\n", barang);
        } else {
            address_list found = Search(*L, barang);
            if (found != Nol) {
                printf("%s sudah ada di wishlist!\n", barang);
            } else {
                InsVLast(L, barang);
                printf("Berhasil menambahkan %s ke wishlist!\n", barang);
            }
        }

        printf("Ketik 'ADD' untuk menambahkan barang lagi atau 'BACK' untuk kembali ke menu utama: ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu utama.\n");
            return;
        }
    }
}

void wishlistSwap(List *L) {
    while (true) {
        PrintWishlist(*L);
        printf("Masukkan 1 posisi barang (atau ketik 'BACK' untuk kembali): ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu sebelumnya.\n");
            return;
        }
        char *nomor1 = WordToString(CurrentWord);
        int idx1 = *nomor1 - '0';

        printf("Masukkan posisi barang yang ingin ditukar dengan input sebelumnya (atau ketik 'BACK' untuk kembali): ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu sebelumnya.\n");
            return;
        }
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
        } else {
            printf("Indeks tidak valid!\n");
        }

        printf("Ketik 'SWAP' untuk menukar barang lagi atau 'BACK' untuk kembali ke menu utama: ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu utama.\n");
            return;
        }
    }
}

void wishlistRemove(List *L) {
    while (true) {
        if (IsEmptyList(*L)) {
            wishlistShow(*L);
            return;
        } else {
            wishlistShow(*L);

            printf("Pilih metode penghapusan (nomor/nama barang) (atau ketik 'BACK' untuk kembali): ");
            STARTINPUTWORD();

            if (isEqual(CurrentWord, "BACK")) {
                printf("Kembali ke menu sebelumnya.\n");
                return;
            }

            if (isEqual(CurrentWord, "nomor")) {
                printf(">>WISHLIST REMOVE ");
                STARTINPUTWORD();
                if (isEqual(CurrentWord, "BACK")) {
                    printf("Kembali ke menu sebelumnya.\n");
                    return;
                }
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

                if (IsEmptyList(*L)) {
                    printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
                } else {
                    if (nomor > 0 && nomor <= NbElmt(*L)) {
                        address_list P = First(*L);
                        for (int i = 1; i < nomor; i++) {
                            P = Next(P);
                        }
                        DelP(L, Info(P));
                        printf("Berhasil menghapus barang posisi ke-%s dari wishlist!\n", idx);
                    } else if (nomor > NbElmt(*L)) {
                        printf("Penghapusan barang WISHLIST gagal dilakukan, tidak ada Barang di posisi ke-%s!\n", idx);
                    }
                }  
            } else if (isEqual(CurrentWord, "nama barang")) {
                printf("Masukkan nama barang yang akan dihapus (atau ketik 'BACK' untuk kembali): ");
                STARTINPUTWORD();
                if (isEqual(CurrentWord, "BACK")) {
                    printf("Kembali ke menu sebelumnya.\n");
                    return;
                }
                char *barang = WordToString(CurrentWord);
                
                address_list found = Search(*L, barang);
                if (found == Nol) {
                    printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", barang);
                } else {
                    DelP(L, barang);
                    printf("%s berhasil dihapus dari WISHLIST!\n", barang);
                } 
            }

            printf("Ketik 'REMOVE' untuk menghapus barang lagi atau 'BACK' untuk kembali ke menu utama: ");
            STARTINPUTWORD();
            if (isEqual(CurrentWord, "BACK")) {
                printf("Kembali ke menu utama.\n");
                return;
            }
        }
    }
}

void wishlistClear(List *L) {
    while (true) {
        infotypes barang;
        while (!IsEmptyList(*L)) {
            DelVFirst(L, &barang);
        }
        printf("Wishlist telah dikosongkan.\n");

        printf("Ketik 'CLEAR' untuk mengosongkan wishlist lagi atau 'BACK' untuk kembali ke menu utama: ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu utama.\n");
            return;
        }
    }
}

void wishlistShow(List L) {
    PrintWishlist(L);
}