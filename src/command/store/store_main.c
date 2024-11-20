#include "store.h"
#include <stdio.h>

//cara ngerun: 
// gcc -I../../ADT/Mesin store_main.c store.c ../../ADT/Mesin/mesinkarakter.c ../../ADT/Mesin/mesinkata.c ../../ADT/Barang/barang.c -o store
int main(){
    ArrayDinStore listStore;
    Barang b;
    Queue req;

    CreateStore(&listStore, 5);
    
    STARTINPUTWORD();

    while (true){
        Word input = GetWord(CurrentWord, 1);
        Word price = GetWord(CurrentWord, 2);

        if(isEqual(input, "quit")){
            break;
        }

        else{
            char *barang = WordToString(input);
            int harga = WordToInt(price);

            if (harga <=0){
                printf("Harga tidak valid\n");
            }
            else{
            b = CreateBarang(barang, harga);
            InsertLast(&listStore, b);
            }

            
            STARTINPUTWORD();
        }
    }


    SList(listStore);

    SRemove(&listStore);

    SList(listStore);

    
    SRequest(&listStore, &req);
    SRequest(&listStore, &req);
    return 0;
}