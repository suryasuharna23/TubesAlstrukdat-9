#ifndef BARANG_H
#define BARANG_H

#define MAX_LEN 100 // Panjang maksimal nama barang

typedef struct {
    char name[MAX_LEN];  // Nama barang
    int price;           // Harga barang
} Barang;

typedef struct {
    Barang *store;    // Array dinamis barang untuk digunakan di store
    int capacity;      // Kapasitas maksimum
    int Neff;          // Jumlah elemen saat ini
} ArrayDinStore;

Barang CreateBarang (const char *name, int price); // membuat barang baru
void PrintBarang (const Barang *barang); // INI PERLU DIHANDLE
void CreateStore(ArrayDinStore *array, int capacity); //alokasi array barang
void AddBarang (ArrayDinStore *array, int i, Barang barang);

#endif