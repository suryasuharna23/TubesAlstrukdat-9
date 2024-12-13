#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main() {
    List L;
    infotypes item1 = "Ayam Geprek Bakar Crispy Besthal";
    infotypes item2 = "Ayam Mangut Besthal";
    infotypes item3 = "Karaage Don";
    infotypes item4 = "Torikatsu Don";
    address_list P;

    // Initialize the list
    CreateEmptyList(&L);

    // Add items to the list
    InsVLast(&L, item1);
    InsVLast(&L, item2);
    InsVLast(&L, item3);
    InsVLast(&L, item4);

    // Print the list
    printf("Initial list:\n");
    PrintInfo(L);

    // Search for an item
    P = Search(L, item2);
    if (P != Nol) {
        printf("\nItem '%s' found in the list.\n", Info(P));
    } else {
        printf("\nItem '%s' not found in the list.\n", item2);
    }

    // Remove an item by value
    DelP(&L, item3);
    printf("\nAfter removing '%s':\n", item3);
    PrintInfo(L);

    // Remove the first item
    infotypes removedItem;
    DelVFirst(&L, &removedItem);
    printf("\nAfter removing the first item '%s':\n", removedItem);
    PrintInfo(L);

    // Get the number of elements
    int count = NbElmt(L);
    printf("\nNumber of elements in the list: %d\n", count);

    // Get the maximum element
    infotypes maxItem = Max(L);
    printf("\nMaximum element in the list: %s\n", maxItem);

    // Get the minimum element
    infotypes minItem = Min(L);
    printf("\nMinimum element in the list: %s\n", minItem);

    // Inverse the list
    InversList(&L);
    printf("\nAfter inverting the list:\n");
    PrintInfo(L);

    // Clear the list
    CreateEmptyList(&L);
    printf("\nAfter clearing the list:\n");
    PrintInfo(L);

    return 0;
}