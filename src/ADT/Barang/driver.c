#include <stdio.h>
#include <stdlib.h>
#include "barang.h"

int main(){
    ListDinamicBarang list;
    CreateListDinamicBarang(&list, 5);

    Barang b1 = CreateBarang("kacamata", 500000);
    Barang b2 = CreateBarang("Lego", 1000000);

    PrintBarang(&b1);
    PrintBarang(&b2);

    // menambahkan barang ke list
    list.buffer[list.size++] = b1;
    list.buffer[list.size++] = b2;

    // menampilkan list barang
    printf("\nDaftar barang:\n");
    for (int i=0; i<list.size; i++){
        PrintBarang(&list.buffer[i]);
    }

    free(list.buffer); //dealokasi memori

    return 0;
}