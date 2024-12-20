#include <stdio.h>
#include "history.h"
#include "../../ADT/Mesin/mesinkata.h"

void AddPurchaseHistory(Stack *history, Purchase purchase) {
    Push(history, purchase);
}

void ShowPurchaseHistory(Stack *history)
{
    if (IsEmptyS(*history))
    {
        printf("Tidak ada riwayat pembelian.\n");
        while(1){
            printf("Ketik 'BACK' untuk kembali: \n");
            printf(">>> ");
            STARTINPUTWORD();
            if (isEqual(CurrentWord, "BACK")){
                break;
            } else {
                printf("Input tidak valid. \n");
            }
        }
    }

    printf("Riwayat Pembelian:\n");
    // Start from bottom of stack to show oldest first
    for (int i = 0; i <= history->top; i++)
    {
        Purchase purchase = history->purchases[i];
        if (purchase.count > 0)
        {
            printf("\nTransaksi %d - %d item(s), Total: %d\n",
                   i+1, purchase.count, purchase.totalCost);
            printf("+---------+---------+-----------------------------+\n");
            printf("|  Harga  | Jumlah  | Nama Barang                 |\n");
            printf("+---------+---------+-----------------------------+\n");
            for (int j = 0; j < purchase.count; j++)
            {
                printf("| %7d | %7d | %-27s |\n",
                       purchase.items[j].total / purchase.items[j].quantity,
                       purchase.items[j].quantity,
                       purchase.items[j].name);
            }
            printf("+---------+---------+-----------------------------+\n");
        }
    }
    while(1){
        printf("Ketik 'BACK' untuk kembali: \n");
        printf(">>> ");
        STARTINPUTWORD();
        if (isEqual(CurrentWord, "BACK")){
            break;
        } else {
            printf("Input tidak valid. \n");
        }
    }
}
