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


/*========== KONSTRUKTOR ==========*/
/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->store terdealokasi
 */
void DeallocateArrayDin(ArrayDinStore *array){
    free((*array).store);
    (*array).Capacity = 0;
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
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
address Get(ArrayDinStore array, int i){
    return (array.store[i]).First;
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDinStore array){
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDinStore *array, address P, int i){
    int j;

    for (j = array->Neff - 1; j >= i; j--){
        array->store[j+1] = array->store[j];
    }
    
    array->store[i].First = P;
    array->Neff += 1;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDinStore *array, address el){
    InsertAt(array, el, Length(*array));
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDinStore *array, address el){
    InsertAt(array, el, 0);
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