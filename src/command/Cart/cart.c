#include <stdio.h>
#include <stdlib.h>
#include "cart.h"
#include "../../command/History/history.h"
#include "../../ADT/User/user.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Map/map.h"
#include "../../ADT/Mesin/mesinkata.h"

extern Stack purchaseHistory;

void DisplayAvailableItems(ListBarang *listbarang) {
    printf("Barang yang tersedia di toko:\n");
    printf("+----------------------------+------------+\n");
    printf("| Nama                       | Harga      |\n");
    printf("+----------------------------+------------+\n");
    for (int i = 0; i < listbarang->count; i++) {
        printf("| %-26s | %-10d |\n", listbarang->items[i].name, listbarang->items[i].price);
    }
    printf("+----------------------------+------------+\n");
}

void DisplayCartItems(User *CurrentUser, ListBarang *listbarang) {
    if (IsEmpty(CurrentUser->keranjang)) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Berikut adalah isi keranjangmu:\n");
    printf("+------------+----------------+------------+------------+\n");
    printf("| Kuantitas  | Nama           | Harga/unit | Total      |\n");
    printf("+------------+----------------+------------+------------+\n");

    for (int i = 0; i < CurrentUser->keranjang.Count; i++) {
        int key = CurrentUser->keranjang.Elements[i].Key;
        int value = CurrentUser->keranjang.Elements[i].Value;
        int harga = listbarang->items[key].price;
        printf("| %-10d | %-14s | %-10d | %-10d |\n", value, listbarang->items[key].name, harga, value * harga);
    }
    printf("+------------+----------------+------------+------------+\n");
}

void CartAdd(User *CurrentUser, ListBarang *listbarang) {
    while (true) {
        DisplayAvailableItems(listbarang);
        printf("Masukkan perintah: CART ADD <nama barang> <jumlah barang>\n");
        printf(">>> ");
        STARTINPUTWORD();

        /*if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu sebelumnya.\n");
            return;
        }*/

        Word namaBarang = GetWord(CurrentWord, 3);
        Word jumlahBarangWord = GetWord(CurrentWord, 4);
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
                break;
            }
        }

        if (i == listbarang->count) {
            printf("Barang tidak ada di toko!\n");
        }

        free(nama);
        printf("Ketik 'ADD' untuk menambahkan barang lagi atau 'BACK' untuk kembali ke menu utama: \n");
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
        DisplayCartItems(CurrentUser, listbarang);
        printf("Masukkan perintah: CART REMOVE <nama barang> <jumlah barang>\n");
        printf(">>> ");
        STARTINPUTWORD();

        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu sebelumnya.\n");
            return;
        }

        Word namaBarang = GetWord(CurrentWord, 3);
        Word jumlahBarangWord = GetWord(CurrentWord, 4);
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
                    printf("Tidak cukup jumlah %s di keranjang untuk mengurangi!\n", nama);
                }
                break;
            }
        }

        if (i == CurrentUser->keranjang.Count) {
            printf("Barang tidak ada di keranjang belanja!\n");
        }

        free(nama);
        printf("Ketik 'REMOVE' untuk mengurangi barang lagi atau 'BACK' untuk kembali ke menu utama: ");
        printf("\n>>> ");
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
        while (1) {
            printf("Ketik 'BACK' untuk kembali: \n");
            printf(">>> ");
            STARTINPUTWORD();
            char *response = WordToString(CurrentWord);
            if (WordCompare(response, "BACK")) {
                break;
            } else {    
                printf("Input tidak valid. \n");
            }
        }
        return;
    }

    printf("Berikut adalah isi keranjangmu:\n");
    printf("+------------+----------------+------------+------------+\n");
    printf("| Kuantitas  | Nama           | Harga      | Total      |\n");
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
    printf("\n>>> ");

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
    printf("| Kuantitas  | Nama           | Harga      | Total      |\n");
    printf("+------------+----------------+------------+------------+\n");

    int totalBiaya = 0;
    Purchase purchase;
    purchase.count = 0;

    for (int i = 0; i < CurrentUser->keranjang.Count; i++) {
        int key = CurrentUser->keranjang.Elements[i].Key;
        int value = CurrentUser->keranjang.Elements[i].Value;
        int harga = listbarang->items[key].price;
        printf("| %-10d | %-14s | %-10d | %-10d |\n", value, listbarang->items[key].name, harga, value * harga);
        totalBiaya += value * harga;

        PurchaseItem item;
        StringCopy(item.name, listbarang->items[key].name);
        item.quantity = value;
        item.total = value * harga;
        purchase.items[purchase.count++] = item;
    }

    purchase.totalCost = totalBiaya;
    printf("+------------+----------------+------------+------------+\n");
    printf("Total biaya yang harus dikeluarkan adalah %d, apakah jadi dibeli? (Ya/Tidak): ", totalBiaya);
    printf("\n>>> ");

    STARTINPUTWORD();
    if (isEqual(CurrentWord, "Ya"))
    {
        if (CurrentUser->money >= totalBiaya)
        {
            CurrentUser->money -= totalBiaya;
            printf("Selamat kamu telah membeli barang-barang tersebut!\n");

            // Store in user's history instead of global history
            Push(&CurrentUser->riwayat_pembelian, purchase);

            // Clear cart
            CreateEmpty(&CurrentUser->keranjang);
        }
        else
        {
            printf("Uang kamu hanya %d, tidak cukup untuk membeli keranjang!\n", CurrentUser->money);
        }
    }
    else
    {
        printf("Pembelian dibatalkan.\n");
    }

    printf("Ketik 'BACK' untuk kembali ke menu utama: ");
    printf("\n>>> ");
    STARTINPUTWORD();
    if (isEqual(CurrentWord, "BACK")) {
        printf("Kembali ke menu utama.\n");
    }
    
}
