#include "barang.h"
#include <stdlib.h>
#include <stdio.h>

ListBarang barangs;

void Stringcopy(char *dest, const char *src) {
    while ((*dest++ = *src++));
}

boolean Wordcompare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return false;
        }
        str1++;
        str2++;
    }
    return *str1 == *str2;
}

// KONSTRUKTOR STORE
void CreateListBarang(ListBarang *listbarang) {
    listbarang->count = 0;
}

int CountBarang(ListBarang *listbarang) {
    return listbarang->count;
}

int IndexBarang(ListBarang *listbarang, char *name){
    int i = 0;
    while (i < listbarang->count && !Wordcompare(listbarang->items[i].name, name)) {
        i++;
    }
    if (i < listbarang->count) {
        return i;
    } else {
        return -1;
    }
}

void AddBarang(ListBarang *listbarang, char *name, int price) {
    if (listbarang->count < MAX_LEN) {
        listbarang->items[listbarang->count].price = price;
        Stringcopy(listbarang->items[listbarang->count].name, name);
        listbarang->count++;
    }
}

void TakeBarang(ListBarang *listbarang, char *name) {
    int i = IndexBarang(listbarang, name);
    if (i != -1) {
        for (int j = i; j < listbarang->count - 1; j++) {
            listbarang->items[j] = listbarang->items[j + 1];
        }
        listbarang->count--;
    }
}

boolean IsBarangExist(ListBarang *listbarang, char *name) {
    return IndexBarang(listbarang, name) != -1;
}

boolean IsEmptyListBarang(ListBarang list) {
    return list.count == 0;
}

void PrintBarang(Barang *barang) {
    printf("%s, %d\n", barang->name, barang->price);
}


boolean StringCompare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return false;
        }
        str1++;
        str2++;
    }
    return *str1 == *str2;
}