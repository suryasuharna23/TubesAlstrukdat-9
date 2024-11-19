#ifndef BARANG_H
#define BARANG_H

#define MAX_LEN 100 // Panjang maksimal nama barang

typedef struct {
    char name[MAX_LEN];  // Nama barang
    int price;           // Harga barang
} Barang;

typedef struct {
    Barang *buffer;    // Array dinamis barang untuk digunakan di store
    int capacity;      // Kapasitas maksimum
    int size;          // Jumlah elemen saat ini
} ArrayDinStore;


Barang CreateBarang (const char *name, int price); // membuat barang baru

void CreateListDinamicBarang(ListDinamicBarang *list, int capacity); //alokasi list barang

void PrintBarang (const Barang *barang); // mencetak informasi barang

void CreateStore(ArrayDinStore *array, int capacity); //alokasi array barang



#endif