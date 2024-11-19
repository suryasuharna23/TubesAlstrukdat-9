#include <stdio.h>
#include <stdlib.h>
#include "barang.h"
#include "boolean.h"

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


void PrintBarang (const Barang *barang) { // Mencetak informasi barang
    printf("Nama Barang: %s\n", barang->name);
    printf("Harga: Rp %d\n", barang->price);
}


/*========== KONSTRUKTOR ==========*/
/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->store terdealokasi
 */
void AddBarang (ArrayDinStore *array, int i, Barang barang){
    if (!SearchBarangStore(array->store[i], barang.name)){
        InsVLast(&(array->store[i]), barang);
    }
}

void DeallocateArrayDin(ArrayDinStore *array){
    free((*array).store); // flag
    (*array).capacity = 0;
    (*array).Neff=0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmptyArrayDin(ArrayDinStore array){
    return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDinStore array){
    return array.Neff;
}


/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDinStore array){
    return array.capacity;
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDinStore *array, int i){
    
    int j;
    for (j=i;j<array->Neff; j++){
        array->store[j] = array->store[j+1];
    }
    array->Neff -= 1;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDinStore *array){
    DeleteAt(array, Length(*array)-1);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDinStore *array){
    DeleteAt(array, 0);
}