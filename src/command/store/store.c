#include "store.h"
#include <stdio.h>
#include <stdlib.h>

// Menghitung panjang string
int StringLength(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}


// Konversi huruf kapital menjadi huruf kecil
void ToLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32; // ASCII konversi
        }
    }
}


void SList(ListBarang *listbarang) {
    // Print items in the store
    if (IsEmptyListBarang(*listbarang)) {
        printf("TOKO KOSONG\n");
    } else {
        printf("List barang yang ada di toko:\n");
        for (int i = 0; i < listbarang->count; i++) {
            printf("- ");
            PrintBarang(&listbarang->items[i]);
        }
    }
}



void SRemove(ListBarang *listbarang) {
    printf("Nama barang yang akan dihapus:\n");
    STARTINPUTWORD();
    char *rem_input = WordToString(CurrentWord);

    if (IsBarangExist(listbarang, rem_input)) {
        TakeBarang(listbarang, rem_input);
        printf("Barang %s berhasil dihapus.\n", rem_input);
    } else {
        printf("Toko tidak menjual %s\n", rem_input);
    }
}

void SRequest(Queue *req, ListBarang *listbarang) {
    printf("Nama barang yang diminta: ");
    STARTINPUTWORD();
    char *req_input = WordToString(CurrentWord);

    // Cek apakah barang ada di toko
    if (IsBarangExist(listbarang, req_input)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
        return;
    }

    // Cek apakah barang sudah ada di antrian
    int i = req->idxHead;
    while (i != ((req->idxTail + 1) % CAPACITY)) {
        if (StringCompare(req_input, req->buffer[i].name)) {
            printf("Barang dengan nama yang sama sudah ada di antrian!\n");
            return;
        }
        i = (i + 1) % CAPACITY;
    }

    // Tambahkan ke antrian
    Barang newRequest;
    StringCopy(newRequest.name, req_input);
    newRequest.price = 0;

    enqueue(req, newRequest);
    printf("\nBarang %s berhasil ditambahkan ke dalam antrian!\n", req_input);
}

void SSupply(Queue *req, ListBarang *listbarang) {
    if (isEmpty(*req)) {
        printf("Tidak ada barang dalam antrian!\n");
        return;
    }

    Barang frontItem = req->buffer[req->idxHead];
    printf("Apakah kamu ingin menambahkan barang %s (terima/tunda/tolak): ", frontItem.name);
    STARTINPUTWORD();
    char *input = WordToString(CurrentWord);

    // Konversi input menjadi huruf kecil
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] += 32;
        }
    }

    if (StringCompare(input, "terima")) {
        printf("Harga barang: ");
        STARTINPUTWORD();
        int harga = WordToInt(CurrentWord);

        if (harga <= 0) {
            printf("Harga tidak valid!\n");
            return;
        }

        // Tambahkan barang ke toko dan hapus dari antrian
        dequeue(req, &frontItem);
        frontItem.price = harga;
        AddBarang(listbarang, frontItem.name, frontItem.price);
        printf("\n%s dengan harga %d telah ditambahkan ke toko.\n", frontItem.name, harga);
    } else if (StringCompare(input, "tunda")) {
        Barang temp;
        dequeue(req, &temp);
        enqueue(req, temp); // Kembalikan ke antrean
        printf("\n%s dikembalikan ke antrian.\n", temp.name);
    } else if (StringCompare(input, "tolak")) {
        Barang temp;
        dequeue(req, &temp);
        printf("\n%s dihapuskan dari antrian.\n", temp.name);
    } else {
        printf("\n< Balik ke menu >\n");
    }
}