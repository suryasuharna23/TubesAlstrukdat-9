#include "store.h"
#include "mesinkata.h"
#include <stdio.h>


void SList(ArrayDinStore *listStore){
    boolean readFile = true;
    if (readFile){

        STARTWORD("list.txt");
        while (!EndWord){
            Word barang = GetWord(CurrentWord, 1);
            Word harga = GetWord(CurrentWord, 2);

            int price = WordToInt(harga); //asumsi list.txt sudah berisikan nama dan harga yang valid
            Barang b = CreateBarang(WordToString(barang), price);

            InsertLast(listStore, b, true);
            ADVWORD();
        }
        readFile = false;
    }

    
    if(IsEmptyArrayDin(*listStore)){
        printf("TOKO KOSONG");
    }

    else{
        printf("List barang yang di toko:\n");
        for (int i=0; i<listStore->Neff; i++){
            printf("-");
            PrintBarang(&listStore->store[i]);
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

    // cek barang ada di toko
    for (int i = 0; i < listStore->Neff && !found; i++) {
        if (WordCompare(req_input, listStore->store[i].name)) {
            printf("Barang dengan nama yang sama sudah ada di toko!\n");
            return;
        }
    }

    // buat request
    int i = 0;
    while (req_input[i] != '\0') {
        newRequest.name[i] = req_input[i];
        i++;
    }
    newRequest.name[i] = '\0';
    newRequest.price = 0;

    // kalo queue kosong, user diminta nambah barang pertama
    if (isEmpty(*req)) {
        enqueue(req, newRequest);
        printf("\nBarang %s berhasil ditambahkan ke dalam antrian!\n", req_input);
        return;
    }


    // cek di antrian ada nama yang sama atau ngga
    i = req->idxHead;
    while (i != ((req->idxTail + 1) % CAPACITY) && !found) {
        if (WordCompare(req_input, req->buffer[i].name)) {
            printf("Barang dengan nama yang sama sudah ada di antrian!\n");
            return;
        }
        i = (i + 1) % CAPACITY;
    }

    // masuk ke queue kalo barang ga di queue/toko
    enqueue(req, newRequest);
    printf("\nBarang %s berhasil ditambahkan ke dalam antrian!\n", req_input);
}


void SSupply(ArrayDinStore *listStore, Queue *req) {
    if (isEmpty(*req)) {
        printf("Tidak ada barang dalam antrian!\n");
        return;
    }

    Barang frontItem = req->buffer[req->idxHead];
    Word input;

    printf("Apakah kamu ingin menambahkan barang %s (terima/tunda/tolak/Purry): ", frontItem.name);
    STARTINPUTWORD();
    input = CurrentWord;

    // konversi lowercase
    for(int i = 0; i < input.Length; i++) {
        if(input.TabWord[i] >= 'A' && input.TabWord[i] <= 'Z') {
            input.TabWord[i] += 32;
        }
    }
    input.TabWord[input.Length] = '\0';

    if (WordCompare("terima", input.TabWord)) {
        printf("Harga barang: ");
        STARTINPUTWORD();
        int harga = WordToInt(CurrentWord);

        if (harga <= 0) {
            printf("Harga tidak valid!\n");
            return;
        }

        // hapus dari antrian dan masuk ke list store
        Barang newItem;
        dequeue(req, &newItem);
        newItem.price = harga;
        InsertLast(listStore, newItem, false);
        printf("\n%s dengan harga %d telah ditambahkan ke toko.\n", newItem.name, harga);
    }
    else if (WordCompare("tunda", input.TabWord)) {
        // barang jadi di idxtail
        Barang temp;
        dequeue(req, &temp);
        enqueue(req, temp);
        printf("\n%s dikembalikan ke antrian.\n", temp.name);
    }
    else if (WordCompare("tolak", input.TabWord)) {
        // hapus dari antrian
        Barang temp;
        dequeue(req, &temp);
        printf("\n%s dihapuskan dari antrian.\n", temp.name);
    }
    else {
        printf("\n< Balik ke menu >\n");
    }
}