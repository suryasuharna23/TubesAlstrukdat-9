#include <stdio.h>
#include "map.h"

int main() {
    Map myMap;
    CreateEmpty(&myMap); // map kosong

    // cek apakah map kosong
    printf("Apakah map kosong? %s\n", IsEmpty(myMap) ? "Ya" : "Tidak");

    // Masukkan nilai ke map
    Insert(&myMap, 1, 100);
    Insert(&myMap, 2, 200);
    Insert(&myMap, 3, 300);

    // Tampilkan current state dari map
    printf("Current state dari map:\n");
    for (int i = 0; i < myMap.Count; i++) {
        printf("Key: %d, Value: %d\n", myMap.Elements[i].Key, myMap.Elements[i].Value);
    }

    int keyToCheck = 2;
    printf("Apakah key %d ada di map? %s\n", keyToCheck, IsMember(myMap, keyToCheck) ? "Ya" : "Tidak");

    int value = Value(myMap, keyToCheck);
    if (value != Undefined) {
        printf("Nilai key %d: %d\n", keyToCheck, value);
    } else {
        printf("Key %d tidak ditemukan.\n", keyToCheck);
    }

    // hapus key
    Delete(&myMap, keyToCheck);
    printf("Setelah menghapus key %d:\n", keyToCheck);
    
    // Tampilkan current state yang baru
    for (int i = 0; i < myMap.Count; i++) {
        printf("Key: %d, Nilai: %d\n", myMap.Elements[i].Key, myMap.Elements[i].Value);
    }

    // cek apakah key yang sudah dihapus masih terbaca
    printf("Apakah key %d masih ada? %s\n", keyToCheck, IsMember(myMap, keyToCheck) ? "Ya" : "Tidak");

    return 0;
}
