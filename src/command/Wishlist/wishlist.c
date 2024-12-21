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

            printf("Masukkan perintah: WISHLIST REMOVE <nomor>\n");
            printf(">>> ");
            STARTINPUTWORD();

            if (isEqual(CurrentWord, "BACK")) {
                printf("Kembali ke menu sebelumnya.\n");
                return;
            }

            Word nomorWord = GetWord(CurrentWord, 3);
            int nomor = WordToInt(nomorWord);

            if (nomor < 1 || nomor > NbElmt(*L)) {
                printf("Nomor tidak valid!\n");
            } else {
                address_list P = First(*L);
                for (int i = 1; i < nomor; i++) {
                    P = Next(P);
                }
                DelP(L, Info(P));
                printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", nomor);
            }

            printf("Ketik 'REMOVE' untuk menghapus barang lagi atau 'BACK' untuk kembali ke menu utama: ");
            printf("\n>>> ");
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