#include <stdio.h>
#include "history.h"
#include "../../ADT/Mesin/mesinkata.h"

void AddPurchaseHistory(Stack *history, Purchase purchase) {
    Push(history, purchase);
}

void ShowPurchaseHistory(Stack *history)
{
    printf("Format masukkan: HISTORY <banyak riwayat yang ditampilkan>\n");
    printf(">>> ");
    
    char input[100];
    fgets(input, sizeof(input), stdin);  
    
    int count = 0;
    // Mencoba untuk membaca input dengan format "HISTORY <angka>"
    if (sscanf(input, "HISTORY %d", &count) == 1) {  
        if (count <= 0) {
            printf("Jumlah riwayat yang ditampilkan harus lebih dari 0.\n");
            return;
        }

        if (IsEmptyS(*history)) {
            printf("Tidak ada riwayat pembelian.\n");
            while (1) {
                printf("Ketik 'BACK' untuk kembali: \n");
                printf(">>> ");
                STARTINPUTWORD();
                if (isEqual(CurrentWord, "BACK")) {
                    break;
                } else {
                    printf("Input tidak valid.\n");
                }
            }
            return;
        }

        printf("Riwayat Pembelian:\n");
        // Menampilkan riwayat sebanyak 'count' yang diminta
        for (int i = history->top; i >= 0 && count > 0; i--, count--) {
            Purchase purchase = history->purchases[i];
            if (purchase.count > 0) {
                printf("\nTransaksi %d - %d item(s), Total: %d\n",
                       history->top - i + 1, purchase.count, purchase.totalCost);
                printf("+---------+---------+-----------------------------+\n");
                printf("|  Harga  | Jumlah  | Nama Barang                 |\n");
                printf("+---------+---------+-----------------------------+\n");
                for (int j = 0; j < purchase.count; j++) {
                    printf("| %7d | %7d | %-27s |\n",
                           purchase.items[j].total / purchase.items[j].quantity,
                           purchase.items[j].quantity,
                           purchase.items[j].name);
                }
                printf("+---------+---------+-----------------------------+\n");
            }
        }

        while (1) {
            printf("Ketik 'BACK' untuk kembali: \n");
            printf(">>> ");
            STARTINPUTWORD();
            if (isEqual(CurrentWord, "BACK")) {
                break;
            } else {
                printf("Input tidak valid.\n");
            }
        }
    } else if (sscanf(input, "HISTORY") == 0) {
        printf("Input tidak valid. Silakan masukkan perintah yang sesuai.\n");
        while (true) {
            printf("Ketik 'BACK' untuk kembali ke menu utama: \n");
            printf(">>> ");
            STARTINPUTWORD();
            if (isEqual(CurrentWord, "BACK")) {
                printf("Kembali ke menu utama.\n");
                return;
            } else {
                printf("Input tidak valid. Harap ketik 'BACK'.\n");
            }
        }
    } else {
        printf("Input tidak valid. Silakan masukkan perintah yang sesuai.\n");
        while (true) {
            printf("Ketik 'HISTORY' untuk melihat riwayat atau 'BACK' untuk kembali.\n");
            printf(">>> ");
            STARTINPUTWORD();
            if (isEqual(CurrentWord, "BACK")) {
                printf("Kembali ke menu utama.\n");
                return;
            } else if (isEqual(CurrentWord, "HISTORY")) {
                ShowPurchaseHistory(history);
                return;
            }
            else {
                printf("Input tidak valid. Harap ketik 'BACK'.\n");
            }
        }
    }
}