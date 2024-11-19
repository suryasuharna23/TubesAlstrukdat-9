#ifndef BARANG_H
#define BARANG_H

#include "boolean.h"

#define MAX_LEN 100 // Panjang maksimal nama barang
#define InitialSize 10

typedef struct {
    char name[MAX_LEN];  // Nama barang
    int price;           // Harga barang
} Barang;

typedef int IdxType;
typedef int Eltype;
typedef struct {
    Eltype *store;    // Array dinamis barang untuk digunakan di store
    int capacity;      // Kapasitas maksimum
    int Neff;          // Jumlah elemen saat ini
    int Neff;          // Jumlah elemen saat ini
} ArrayDinStore;

void CreateStore(ArrayDinStore *array, int capacity);

Barang CreateBarang (const char *name, int price); // membuat barang baru

void CreateListDinamicBarang(ArrayDinStore *list, int capacity); //alokasi list barang

void PrintBarang (const Barang *barang); // mencetak informasi barang

// KONSTRUKTOR ARRAY DINAMIS
ArrayDinStore MakeArrayDinStore();

void DeallocateArrayDinStore(ArrayDinStore *array);

boolean IsEmptyArrayDin(ArrayDinStore array);

int Length(ArrayDinStore array);

Eltype Get(ArrayDinStore array, IdxType i);

int GetCapacity(ArrayDinStore array);

void InsertAt(ArrayDinStore *array, Eltype P, IdxType i);

void InsertLast(ArrayDinStore *array, Eltype el);

void InsertFirst(ArrayDinStore *array, Eltype el);

void DeleteAt(ArrayDinStore *array, IdxType i);

void DeleteLast(ArrayDinStore *array);

void DeleteFirst(ArrayDinStore *array);









#endif