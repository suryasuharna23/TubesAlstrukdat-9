#include "mesinkata.h"
#include "../ADT/Barang/barang.h"
#include "../ADT/User/user.h"
#include <stdio.h>

void LOAD(Barang *listbarang, User *listuser, char *filename) {
    // mulai baca file
    STARTWORD(filename);
    if (EndWord) {
        printf("File konfigurasi tidak ditemukan atau kosong. \n");
        return;
    }

    //baca jumlah barang 
    int jumlahBarang = 0;
    for (int i = 0; i < CurrentWord.Length; i++) {
        jumlahBarang = jumlahBarang * 10 + (CurrentWord.TabWord[i] - '0');
    }
    ADVWORD();

    //baca barang
    for (int i = 0; i < jumlahBarang; i++) {
        Word hargaWord, namaBarang;
        int hargaBarang = 0;

        // baca harga barang
        hargaWord = CurrentWord;
        for (int j = 0; j < hargaWord.Length; j++) {
            hargaBarang = hargaBarang * 10 + (hargaWord.TabWord[j] -  '0');
        }
        ADVWORD();

        // baca nama barang
        namaBarang = CurrentWord;
        ADVWORD();

        // tambah barang ke list
        Barang b;
        CreateBarang(&b, &namaBarang, hargaBarang);
        AddBarang(listbarang, b);
    }

    // baca jumlah user
    int jumlahUser = 0;
    for (int i = 0; i < CurrentWord.Length; i++) {
        jumlahUser = jumlahUser * 10 + (CurrentWord.TabWord[i] - '0');
    }
    ADVWORD();

    // baca jumlah user
    int jumlahUser = 0;
    for (int i = 0; i < CurrentWord.Length; i++) {
        jumlahUser = jumlahUser * 10 + (CurrentWord.TabWord[i] - '0');
    }
    ADVWORD();

    // baca data pengguna
    for (int i = 0; i < jumlahUser; i++) {
        Word uangWord, username, password;
        int uangUser = 0;

        // baca uang pengguna
        uangWord = CurrentWord;
        for (int j = 0; j < uangWord.Length; j++) {
            uangUser = uangUser * 10 + (uangWord.TabWord[j] - '0');
        }
        ADVWORD();

        username = CurrentWord;
        ADVWORD();

        password = CurrentWord;
        ADVWORD();

        User u;
        CreateUser(&u, &username, &password, uangUser);
        AddUser(listuser, u);
        }

        printf("konfigurasi berhasil dimuat dari file: %s\n", filename);
    
    }