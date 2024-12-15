#include <stdio.h>
#include "barang.h"

int main() {
    ListBarang listbarang;
    CreateListBarang(&listbarang);

    AddBarang(&listbarang, "Floppy Disk Drive", 500000);
    AddBarang(&listbarang, "Lego", 1000000);
    AddBarang(&listbarang, "Mouse", 150000);
    AddBarang(&listbarang, "Keyboard", 300000);
    AddBarang(&listbarang, "Monitor", 2000000);
    AddBarang(&listbarang, "Printer", 1000000); 

    printf("Jumlah barang: %d\n", CountBarang(&listbarang));

    printf("Sebelum dihapus:\n");
    for (int i = 0; i < CountBarang(&listbarang); i++) {
        PrintBarang(&listbarang.items[i]);
    }

    TakeBarang(&listbarang, "Floppy Disk Drive");

    printf("Setelah dihapus:\n");
    for (int i = 0; i < CountBarang(&listbarang); i++) {
        PrintBarang(&listbarang.items[i]);
    }

    printf("Jumlah barang setelah penghapusan: %d\n", CountBarang(&listbarang));

    return 0;
}