#include "barang.h"
#include <stdlib.h>
#include <stdio.h>
#include "mesinkata.h"
// KONSTRUKTOR STORE
void CreateStore(ArrayDinStore *list, int capacity) {
    if (capacity > 0) {
        list->store = (Barang *)malloc((unsigned int)capacity * sizeof(Barang));
        list->Neff = 0;
        list->Capacity = capacity;
    } else {
        list->store = NULL;
        list->Neff = 0;
        list->Capacity = 0;
    }
}

// KONSTRUKTOR BARANG
Barang CreateBarang(const char *name, int price) { // membuat barang baru
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

void PrintBarang(const Barang *barang) {
    printf("%s\n", barang->name);
}

// KONSTRUKTOR ARRAY DINAMIS

void DeleteAt(ArrayDinStore *array, IdxType i) {
    for (int j = i; j < Length(*array) - 1; j++) {
        A(*array)[j] = A(*array)[j + 1];
    }
    Neff(*array) -= 1;
}

void DeleteLast(ArrayDinStore *array) {
    DeleteAt(array, Length(*array) - 1);
}

void DeleteFirst(ArrayDinStore *array) {
    DeleteAt(array, 0);
}

void ResizeArray(ArrayDinStore *array, int newCapacity) {
    Barang *newStore = (Barang *)malloc((unsigned int)newCapacity * sizeof(Barang));
    for (int i = 0; i < array->Neff; i++) {
        newStore[i] = array->store[i];
    }
    free(array->store);
    array->store = newStore;
    array->Capacity = newCapacity;
}

void InsertLast(ArrayDinStore *array, Barang el) {
    // Jika barang sudah ada di toko
    for (int i = 0; i < Neff(*array); i++) {
        if (WordCompare(A(*array)[i].name, el.name)) {
            printf("Barang %s sudah ada di toko!\n", el.name);
            return;
        }
    }
    
    // validasi jika harga barang valid
    if (el.price <= 0) {
        printf("Barang tidak valid! Harga harus lebih dari 0\n");
        return;
    }
    
    // Jika barang belum ada, maka akan ditambahkan
    if (Neff(*array) >= array->Capacity) {
        ResizeArray(array, array->Capacity * 2); 
    }
    A(*array)[Neff(*array)] = el;
    Neff(*array)++;
    printf("Barang %s berhasil ditambahkan ke toko!\n", el.name);
}

int Length(ArrayDinStore array) {
    return Neff(array);
}

void DeallocateArrayDinStore(ArrayDinStore *array) {
    free(array->store);
    array->store = NULL;
    array->Neff = 0;
    array->Capacity = 0;
}

boolean IsEmptyArrayDin(ArrayDinStore array) {
    return array.Neff == 0;
}