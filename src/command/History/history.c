#include <stdio.h>
#include "history.h"
#include "../../ADT/Mesin/mesinkata.h"

void AddPurchaseHistory(Stack *history, Purchase purchase) {
    Push(history, purchase);
}

void ShowPurchaseHistory(Stack *history) {
    if (IsEmptyS(*history)) {
        printf("Tidak ada riwayat pembelian.\n");
    } else {
        for (int i = 0; i <= history->top; i++) {
            Purchase purchase = history->purchases[i];
            printf("| Pembelian %d - Total %d                 |\n", i + 1, purchase.totalCost);
            printf("+------------+----------------+------------+\n");
            printf("| Kuantitas  | Nama           | Total      |\n");
            printf("+------------+----------------+------------+\n");
            for (int j = 0; j < purchase.count; j++) {
                printf("| %-10d | %-14s | %-10d |\n",
                       purchase.items[j].quantity,
                       purchase.items[j].name,
                       purchase.items[j].total);
            }
            printf("+------------+----------------+------------+\n\n");
        }
    }
}