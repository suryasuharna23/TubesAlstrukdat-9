#include <stdio.h>
#include "Start.h"

void start(ArrayDinStore *store, ListUser *listuser, char *filename){
    STARTWORD(filename);

    Word num_items;
    num_items = GetWord(CurrentWord, 1);
    int jum_barang = WordToInt(num_items);
    
    for (int i=0; i<jum_barang; i++){
        // ADV WIRD
        //simpen di int
        // ADV SENTENCE
        //simpen
        
        ADVWORD();
        Word harga = GetWord(CurrentWord, 1);
        int price = WordToInt(harga);

        Word barang = GetSentence(CurrentWord, 1);
        char *nama = WordToString(barang);

        Barang items = CreateBarang(nama, price);
        InsertLast(&store, items, false);
    }

    ADVWORD();
    Word num_user;
    num_user = GetWord(CurrentWord, 1);
    int jum_user = WordToInt(num_user);

    for (int i=0; i<jum_user; i++){
        // ADV WIRD
        //simpen di int
        // ADV SENTENCE
        //simpen
        
        ADVWORD();
        Word uang = GetWord(CurrentWord, 1);
        int money = WordToInt(uang);

        Word nama = GetWord(CurrentWord, 2);
        char *name = WordToString(nama);
        
        Word pass = GetWord(CurrentWord, 3);
        char *password = WordToString(pass);

        User u;
        CreateUser(&u, name, password, money);
        InsertLastUser(listuser, u);
    }


}
