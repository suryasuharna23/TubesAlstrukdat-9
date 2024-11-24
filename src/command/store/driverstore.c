#include "store.h"
#include <stdio.h>

int main() {
    ArrayDinStore listStore;
    Queue req;
    Word command;
    char *file = "list.txt";
    boolean running = true;
    
    CreateStore(&listStore, 10);
    CreateQueue(&req);

    while (running) {
        printf("\nMasukkan command (add/list/remove/request/supply/quit): ");
        STARTINPUTWORD();

        
        if (CurrentWord.Length == 0) {
            printf("Command tidak boleh kosong!\n");
            continue;
        }

        command = CurrentWord;
        
        // konversi ke lowercase
        for(int i = 0; i < command.Length; i++) {
            if(command.TabWord[i] >= 'A' && command.TabWord[i] <= 'Z') {
                command.TabWord[i] += 32;
            }
        }
        
        // penerimaan command diakhiri dengan null
        command.TabWord[command.Length] = '\0';

        if (WordCompare("quit", command.TabWord)) {
            running = false;
            printf("Terima kasih telah menggunakan program ini!\n");
            break;
        }
        else if (WordCompare("add", command.TabWord)) { //menambahkan barang ke store
            printf("Nama barang dan harga: ");
            STARTINPUTWORD();
            if (CurrentWord.Length < 2) { //kalau user ga masukin nama barang/harga
                printf("Input tidak valid! Format: <nama_barang> <harga>\n");
                continue;
            }
            Word barang = GetWord(CurrentWord, 1);
            Word price = GetWord(CurrentWord, 2);
            int harga = WordToInt(price);

            if (harga <= 0) {
                printf("Harga tidak valid!\n");
            } else {
                Barang b = CreateBarang(WordToString(barang), harga);
                InsertLast(&listStore, b, false);
            }
        }
        else if (WordCompare("list", command.TabWord)) {
            SList(&listStore);
        }
        else if (WordCompare("remove", command.TabWord)) {
            SRemove(&listStore);
        }
        else if (WordCompare("request", command.TabWord)) {
            SRequest(&listStore, &req);
        }

        else if (WordCompare("supply", command.TabWord)) {
            SSupply(&listStore, &req);
        }

        else {
            printf("Command tidak valid! Pilih: add/list/remove/request/supply/quit\n");
        }
    }

    DeallocateArrayDinStore(&listStore);
    return 0;
}