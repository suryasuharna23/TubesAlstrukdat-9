#ifndef BARANG_H
#define BARANG_H

#define MAX_LEN 50

#include "boolean.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"

typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

typedef struct
{
    Barang items[MAX_LEN];
    int count;
} listBarang ;

typedef struct {
    Barang *store;
    int Neff;
    int Capacity;
} ArrayDinStore;

typedef int IdxType;

#define A(array) (array).store
#define Neff(array) (array).Neff

// KONSTRUKTOR LIST BARANG
void InitializeListBarang(listBarang *list);

// KONSTRUKTOR BARANG
Barang CreateBarang(const char *name, int price);
void PrintBarang(const Barang *barang);

// KONSTRUKTOR ARRAY DINAMIS
void DeleteAt(ArrayDinStore *array, IdxType i);
void DeleteLast(ArrayDinStore *array);
void DeleteFirst(ArrayDinStore *array);
void ResizeArray(ArrayDinStore *array, int newCapacity);
void InsertLast(ArrayDinStore *array, Barang el, boolean isFromFile);
int Length(ArrayDinStore array);
void DeallocateArrayDinStore(ArrayDinStore *array);
boolean IsEmptyArrayDin(ArrayDinStore array);

#endif 