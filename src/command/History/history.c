#include <stdio.h>
#include "history.h"
#include "../../ADT/Mesin/mesinkata.h"

void AddPurchaseHistory(Stack *history, Purchase purchase) {
    Push(history, purchase);
}

void ShowPurchaseHistory(Stack *history) {
    if (IsEmptyS(*history)) {
        printf("Tidak ada riwayat pembelian.\n");
        return;
    }

    printf("Masukkan jumlah riwayat pembelian yang ingin ditampilkan: ");
    printf("\n>>> ");
    STARTINPUTWORD();
    int n = WordToInt(CurrentWord);

    if (n <= 0) {
        printf("Jumlah riwayat pembelian harus lebih besar dari nol.\n");
        return;
    }

    int count = 0;
    for (int i = history->top; i >= 0 && count < n; i--, count++) {
        printf("+------------------------------------------+\n");
        printf("| Pembelian %d - Total %d                 |\n", count + 1, history->purchases[i].totalCost);
        printf("+------------+----------------+------------+\n");
        printf("| Kuantitas  | Nama           | Total      |\n");
        printf("+------------+----------------+------------+\n");
        for (int j = 0; j < history->purchases[i].count; j++) {
            printf("| %-10d | %-14s | %-10d |\n",
                   history->purchases[i].items[j].quantity,
                   history->purchases[i].items[j].name,
                   history->purchases[i].items[j].total);
        }
        printf("+------------+----------------+------------+\n\n");
    }
}