#include "store.h"
#include "mesinkata.h"
#include <stdio.h>

void SList(ArrayDinStore listStore){
    if(IsEmptyArrayDin(listStore)){
        printf("TOKO KOSONG");
    }

    else{
        printf("List barang yang di toko:\n");
        for (int i=0; i<listStore.Neff; i++){
            printf("-");
            PrintBarang(&listStore.store[i]);
        }
    }
}


void SRemove(ArrayDinStore *listStore) {
    Word input;
    boolean found = false;

    printf("Nama barang yang akan dihapus:\n");
    STARTINPUTWORD();
    input = GetWord(CurrentWord, 1);
    char *rem_input = WordToString(input);

    for (int i = 0; i < (*listStore).Neff && !found; i++) {
        if (WordCompare(rem_input, (*listStore).store[i].name)) {
            DeleteAt(listStore, i);
            found = true;
        }
    }
    
    if (!found) {
        printf("Toko tidak menjual %s\n", rem_input);
    }
}