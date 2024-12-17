#include <stdio.h>
#include "list.h"

int main() {
    ListStatic myList;
    ElType item1 = "Ayam Geprek Bakar Crispy Besthal";
    ElType item2 = "Ayam Mangut Besthal";
    ElType item3 = "Karaage Don";

    myList = MakeListStatic();

    printf("Apakah List Kosong? %s\n", IsListStaticEmpty(myList) ? "Ya" : "Tidak");

    InsertLastListStatic(&myList, item1);
    InsertLastListStatic(&myList, item2);
    InsertLastListStatic(&myList, item3);

    printf("Panjang List: %d\n", LengthListStatic(myList));

    printf("Barang di List:\n");
    for (int i = 0; i < LengthListStatic(myList); i++) {
        printf("Barang %d: %s\n", i + 1, GetListStatic(myList, i));
    }

    printf("Apakah list kosong setelah ditambahkan? %s\n", IsListStaticEmpty(myList) ? "Ya" : "Tidak");

    return 0;
}
