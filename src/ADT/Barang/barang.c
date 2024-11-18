#include <stdio.h>
#include <stdlib.h>
#include "barang.h"

Barang CreateBarang (const char *name, int price){ // membuat barang baru
 
    Barang barang;
    int i = 0;
    while (name[i] != '\0' && i < MAX_LEN - 1) {
        barang.name[i] = name[i];
        i++;
    }
    barang.name[i] = '\0';

    barang.price = price;
    return barang;
}


void CreateListDinamicBarang(ListDinamicBarang *list, int capacity) {
    list->buffer = (Barang *)malloc(capacity * sizeof(Barang)); // Alokasi memori
    list->capacity = capacity;
    list->size = 0;
}

void PrintBarang (const Barang *barang) { // Mencetak informasi barang
    printf("Nama Barang: %s\n", barang->name);
    printf("Harga: Rp %d\n", barang->price);
}


