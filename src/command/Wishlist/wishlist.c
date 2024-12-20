#include <stdio.h>
#include "wishlist.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/User/user.h"
#include "../../command/Store/store.h"

extern ListUser users;

void PrintWishlist(List L)
{
    if (IsEmptyList(L))
    {
        printf("Wishlist kosong.\n");
        return;
    }

    printf("+----+-----------------------------+\n");
    printf("| No | Nama Barang                 |\n");
    printf("+----+-----------------------------+\n");

    address_list P = First(L);
    int no = 1;
    while (P != Nol) {
        printf("| %-2d | %-27s |\n", no, Info(P));
        P = Next(P);
        no++;
    }

    printf("+----+-----------------------------+\n");
    printf("\n");
}

void wishlistAdd(List *L, ListBarang *listbarang) {
    while (true) {
        DisplayBarang(listbarang);
        printf("Masukkan nama barang (atau ketik 'BACK' untuk kembali): ");
        printf("\n>>> ");
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
        printf("\n>>> ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu utama.\n");
            return;
        }
    }
}

void wishlistSwap(List *L) {
    while (true) {
        printf("Masukkan perintah: WISHLIST SWAP <indeks barang 1> <indeks barang 2>\n");
        printf(">> ");
        STARTINPUTWORD();
        Word num1Word = GetWord(CurrentWord, 3);
        Word num2Word = GetWord(CurrentWord, 4);

        int idx1 = WordToInt(num1Word);
        int idx2 = WordToInt(num2Word);

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
            PrintWishlist(*L);
        } else {
            printf("Indeks tidak valid!\n");
        }

        printf("Ketik 'SWAP' untuk menukar barang lagi atau 'BACK' untuk kembali ke menu utama: ");
        printf("\n>>> ");
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
            PrintWishlist(*L);
            return;
        } else {
            PrintWishlist(*L);

            printf("Pilih metode penghapusan (nomor/nama barang) (atau ketik 'BACK' untuk kembali): ");
            printf("\n>>> ");
            STARTINPUTWORD();

            if (isEqual(CurrentWord, "BACK")) {
                printf("Kembali ke menu sebelumnya.\n");
                return;
            }

            if (isEqual(CurrentWord, "nomor")) {
                printf("Masukkan nomor barang yang akan dihapus (atau ketik 'BACK' untuk kembali): \n");
                printf(">>> ");
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
    PrintWishlist(*L);

    printf("Apakah anda yakin ingin menghapus semua barang di wishlist? (YES/BACK): \n");
    boolean validInput = false; 
    while (!validInput) { 
        printf(">>> ");
        STARTINPUTWORD(); 

        if (isEqual(CurrentWord, "YES")) {
            infotypes barang;
            while (!IsEmptyList(*L)) {
                DelVFirst(L, &barang);
            }
            printf("Wishlist telah dikosongkan.\n");
            validInput = true; 
        } else if (isEqual(CurrentWord, "BACK")) {
            printf("Penghapusan wishlist dibatalkan.\n");
            validInput = true; 
        } else {
            printf("Input tidak valid. Harap masukkan YES atau BACK.\n");
        }
    }

    while (true) {
        printf("Ketik 'BACK' untuk kembali ke menu utama: \n");
        printf(">>> ");
        STARTINPUTWORD(); 

        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu utama.\n");
            return; 
        } else {
            printf("Input tidak valid. Harap ketik 'BACK'.\n");
        }
    }
}

void wishlistShow(List L) {
    PrintWishlist(L);
    while(1){
        printf("Ketik 'BACK' untuk kembali: \n");
        printf(">>> ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK")){
            break;
        } else {
            printf("Input tidak valid. \n");
        }
    }
}