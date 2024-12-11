#include <stdio.h>
#include <stdlib.h>
#include "cart.h"
#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Map/map.h"
#include "../../ADT/Mesin/mesinkata.h"

void CartAdd(User *CurrentUser, ListBarang *listbarang) {
    printf("Masukkan nama barang dan jumlah: ");
    STARTINPUTWORD();
    Word namaBarang = GetWord(CurrentWord, 1);
    Word jumlahBarangWord = GetWord(CurrentWord, 2);
    int jumlahBarang = WordToInt(jumlahBarangWord);

    char *nama = WordToString(namaBarang);

    int i;
    for (i = 0; i < listbarang->count; i++) {
        if (WordCompare(listbarang->items[i].name, nama)) {
            if (IsMember(CurrentUser->keranjang, i)) {
                Insert(&CurrentUser->keranjang, i, Value(CurrentUser->keranjang, i) + jumlahBarang);
            } else {
                Insert(&CurrentUser->keranjang, i, jumlahBarang);
            }
            printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", jumlahBarang, nama);
            free(nama);
            return;
        }
    }
    printf("Barang tidak ada di toko!\n");
    free(nama);
}

void CartRemove(User *CurrentUser, ListBarang *listbarang) {
    printf("Masukkan nama barang dan jumlah: ");
    STARTINPUTWORD();
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
            free(nama);
            return;
        }
    }
    printf("Barang tidak ada di keranjang belanja!\n");
    free(nama);
}

void CartShow(User *CurrentUser, ListBarang *listbarang) {
    if (IsEmpty(CurrentUser->keranjang)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Berikut adalah isi keranjangmu.\n");
    printf("Kuantitas  Nama    Total\n");

    int totalBiaya = 0;
    for (int i = 0; i < CurrentUser->keranjang.Count; i++) {
        int key = CurrentUser->keranjang.Elements[i].Key;
        int value = CurrentUser->keranjang.Elements[i].Value;
        printf("%-10d %-7s %-5d\n", value, listbarang->items[key].name, value * listbarang->items[key].price);
        totalBiaya += value * listbarang->items[key].price;
    }
    printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalBiaya);
}

void CartPay(User *CurrentUser, ListBarang *listbarang) {
    if (IsEmpty(CurrentUser->keranjang)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Kamu akan membeli barang-barang berikut.\n");
    printf("Kuantitas  Nama    Total\n");

    int totalBiaya = 0;
    for (int i = 0; i < CurrentUser->keranjang.Count; i++) {
        int key = CurrentUser->keranjang.Elements[i].Key;
        int value = CurrentUser->keranjang.Elements[i].Value;
        printf("%-10d %-7s %-5d\n", value, listbarang->items[key].name, value * listbarang->items[key].price);
        totalBiaya += value * listbarang->items[key].price;
    }
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
}