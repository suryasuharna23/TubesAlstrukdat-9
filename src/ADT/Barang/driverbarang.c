#include "barang.h"
#include <stdio.h>

int main() {
    ArrayDinStore list;
    CreateStore(&list, 5);

    Barang b1 = CreateBarang("Floppy Disk Drive", 500000);
    Barang b2 = CreateBarang("Lego", 1000000);
    Barang b3 = CreateBarang("Mouse", 150000);
    Barang b4 = CreateBarang("Keyboard", 300000);
    Barang b5 = CreateBarang("Monitor", 2000000);
    Barang b6 = CreateBarang("Printer", 1000000);

    printf("%d\n", list.Capacity); // capacity bernilai 5

    InsertLast(&list, b1, false);
    InsertLast(&list, b2, false);
    InsertLast(&list, b3, false);
    InsertLast(&list, b4, false);
    InsertLast(&list, b5, false);
    InsertLast(&list, b6, false); // tambah kapasitas list dari 5 menjadi 10
    printf("%d\n", list.Capacity);

    printf("Sebelum dihapus:\n");
    for (int i = 0; i < list.Neff; i++) {
        PrintBarang(&list.store[i]);
    }

    DeleteFirst(&list);

    printf("Setelah dihapus:\n");
    for (int i = 0; i < list.Neff; i++) {
        PrintBarang(&list.store[i]);
    }

    printf("%d\n", list.Capacity);

    return 0;
}