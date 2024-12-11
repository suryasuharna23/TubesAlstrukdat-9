#include <stdio.h>
#include <stdlib.h>
#include "cart.h"
#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Map/map.h"
#include "../../ADT/Mesin/mesinkata.h"

void CartAdd(User *CurrentUser, ListBarang *listbarang) {
    while (true) {
        printf("Masukkan nama barang dan jumlah :)\n");
        printf("[ KETIK 'BACK' UNTUK KEMBALI ]\n");
        printf("Format <NAMABARANG> <KUANTITAS>: \n");
        printf(">>> ");
        STARTINPUTWORD();

        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu sebelumnya.\n");
            return;
        }

        Word namaBarang = GetWord(CurrentWord, 1);
        Word jumlahBarangWord = GetWord(CurrentWord, 2);
        int jumlahBarang = WordToInt(jumlahBarangWord);

        char *nama = WordToString(namaBarang);

        int i;
        for (i = 0; i < listbarang->count; i++) {
            if (WordCompare(listbarang->items[i].name, nama)) {
                if (!IsMember(CurrentUser->keranjang, i)) {
                    Insert(&CurrentUser->keranjang, i, jumlahBarang);
                    printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", jumlahBarang, nama);
                } else {
                    CurrentUser->keranjang.Elements[i].Value += jumlahBarang;
                    printf("Berhasil menambahkan %d %s ke keranjang belanja (jumlah diperbarui).\n", jumlahBarang, nama);
                }
                free(nama);
                break;
            }
        }

        if (i == listbarang->count) {
            printf("Barang tidak ada di toko!\n");
        }

        free(nama);
        printf("Ketik 'ADD' --> Tambah barang lagi.\n");
        printf("Ketik 'BACK' --> Kembali ke menu utama.\n");
        printf(">>> ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu utama.\n");
            return;
        }
    }
}

void CartRemove(User *CurrentUser, ListBarang *listbarang) {
    while (true) {
        printf("Masukkan nama barang dan jumlah :)\n");
        printf("[ KETIK 'BACK' UNTUK KEMBALI ]\n");
        printf("Format <NAMABARANG> <KUANTITAS>: \n");
        printf(">>> ");
        STARTINPUTWORD();

        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu sebelumnya.\n");
            return;
        }

        Word namaBarang = GetWord(CurrentWord, 1);
        Word jumlahBarangWord = GetWord(CurrentWord, 2);
        int jumlahBarang = WordToInt(jumlahBarangWord);

        char *nama = WordToString(namaBarang);

        int i;
        for (i = 0; i < CurrentUser->keranjang.Count; i++) {
            int key = CurrentUser->keranjang.Elements[i].Key;
            if (WordCompare(listbarang->items[key].name, nama)) {
                if (CurrentUser->keranjang.Elements[i].Value >= jumlahBarang) {
                    CurrentUser->keranjang.Elements[i].Value -= jumlahBarang;
                    if (CurrentUser->keranjang.Elements[i].Value == 0) {
                        Delete(&CurrentUser->keranjang, key);
                    }
                    printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", jumlahBarang, nama);
                } else {
                    printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", CurrentUser->keranjang.Elements[i].Value, nama);
                }
                break;
            }
        }

        if (i == CurrentUser->keranjang.Count) {
            printf("Barang tidak ada di keranjang belanja!\n");
        }

        free(nama);
        printf("Ketik 'REMOVE' --> Tambah barang lagi.\n");
        printf("Ketik 'BACK' --> Kembali ke menu utama.\n");
        printf(">>> ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu utama.\n");
            return;
        }
    }
}

void CartShow(User *CurrentUser, ListBarang *listbarang) {
    if (IsEmpty(CurrentUser->keranjang)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Berikut adalah isi keranjangmu:\n");
    printf("+------------+----------------+------------+------------+\n");
    printf("| Kuantitas  | Nama           | Harga/unit | Total      |\n");
    printf("+------------+----------------+------------+------------+\n");

    int totalBiaya = 0;
    for (int i = 0; i < CurrentUser->keranjang.Count; i++) {
        int key = CurrentUser->keranjang.Elements[i].Key;
        int value = CurrentUser->keranjang.Elements[i].Value;
        int harga = listbarang->items[key].price;
        printf("| %-10d | %-14s | %-10d | %-10d |\n", value, listbarang->items[key].name, harga, value * harga);
        totalBiaya += value * harga;
    }
    printf("+------------+----------------+------------+------------+\n");
    printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalBiaya);

    printf("Ketik 'BACK' untuk kembali ke menu utama: ");
    STARTINPUTWORD();
    if (isEqual(CurrentWord, "BACK")) {
        printf("Kembali ke menu utama.\n");
    }
}

void CartPay(User *CurrentUser, ListBarang *listbarang) {
    if (IsEmpty(CurrentUser->keranjang)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Kamu akan membeli barang-barang berikut:\n");
    printf("+------------+----------------+------------+------------+\n");
    printf("| Kuantitas  | Nama           | Harga/unit | Total      |\n");
    printf("+------------+----------------+------------+------------+\n");

    int totalBiaya = 0;
    for (int i = 0; i < CurrentUser->keranjang.Count; i++) {
        int key = CurrentUser->keranjang.Elements[i].Key;
        int value = CurrentUser->keranjang.Elements[i].Value;
        int harga = listbarang->items[key].price;
        printf("| %-10d | %-14s | %-10d | %-10d |\n", value, listbarang->items[key].name, harga, value * harga);
        totalBiaya += value * harga;
    }
    printf("+------------+----------------+------------+------------+\n");
    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalBiaya);

    STARTINPUTWORD();
    if (isEqual(CurrentWord, "Ya")) {
        if (CurrentUser->money >= totalBiaya) {
            CurrentUser->money -= totalBiaya;
            printf("Selamat kamu telah membeli barang-barang tersebut!\n");
            CreateEmpty(&CurrentUser->keranjang); // Kosongkan keranjang setelah pembayaran
        } else {
            printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", CurrentUser->money);
        }
    } else {
        printf("Pembelian dibatalkan.\n");
    }

    printf("Ketik 'BACK' untuk kembali ke menu utama: ");
    STARTINPUTWORD();
    if (isEqual(CurrentWord, "BACK")) {
        printf("Kembali ke menu utama.\n");
    }
}
