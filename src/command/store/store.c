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

void SRequest(ArrayDinStore *listStore, Queue *req) {
    Word input;
    boolean found = false;
    Barang newRequest;

    printf("Nama barang yang diminta: ");
    STARTINPUTWORD();
    input = GetWord(CurrentWord, 1);
    char *req_input = WordToString(input);


    for (int i = 0; i < listStore->Neff && !found; i++) {
        if (WordCompare(req_input, listStore->store[i].name)) {
            printf("Barang dengan nama yang sama sudah ada di toko!\n");
            return;
        }
    }

    
    if (!isEmpty(*req)) {
        int i = req->idxHead;
        while ((i != ((req->idxTail + 1) % CAPACITY)) && !found) {
            if (WordCompare(req_input, req->buffer[i].name)) { //endless loop tapi wordcompare udh bener return nya di atas
                printf("Barang dengan nama yang sama sudah ada di antrian!\n");
                return;
            }
            printf("sebelum keluar loop\n");
            i = ((i + 1) % CAPACITY);
        }
        printf("keluar dari loop\n");
        
    }

    int i = 0;
    while (req_input[i] != '\0') {
        newRequest.name[i] = req_input[i];
        i++;
    }
    newRequest.name[i] = '\0';
    newRequest.price = 0; 
    printf("selesai\n");

    enqueue(req, newRequest);
}