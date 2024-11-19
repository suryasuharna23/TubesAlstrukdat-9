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

    printf("%d\n", list.Capacity); // Kapasitas bernilai 5

    InsertLast(&list, b1);
    InsertLast(&list, b2);
    InsertLast(&list, b3);
    InsertLast(&list, b4);
    InsertLast(&list, b5);
    InsertLast(&list, b6); // Tambah kapasitas list dari 5 menjadi 10
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