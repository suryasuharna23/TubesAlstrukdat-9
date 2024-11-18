#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Mesin/mesinkata.h"

int main() {
    Queue q;
    Barang barang1 = {"AK47", 100};
    Barang barang2 = {"Sticky Web Gun", 500};
    Barang barang3 = {"Inator Neutralizer", 1000};
    Barang barang4 = {"Glock 9000", 1200};
    CreateQueue(&q);

    enqueue(&q, barang1);
    enqueue(&q, barang2);
    enqueue(&q, barang3);
    enqueue(&q, barang4);
    displayQueue(q);

    Barang barang;
    dequeue(&q, &barang);
    printf("Queue setelah dequeue AK47: ");
    displayQueue(q);

    // Dequeue sisa barang
    dequeue(&q, &barang);
    printf("Elemen yang dikeluarkan: %s, %d\n", barang.name, barang.price);
    dequeue(&q, &barang);
    printf("Elemen yang dikeluarkan: %s, %d\n", barang.name, barang.price);
    printf("Queue setelah tiga kali dequeue: ");
    displayQueue(q);
    dequeue(&q, &barang);
    printf("Elemen yang dikeluarkan: %s, %d\n", barang.name, barang.price);
    printf("Queue setelah empat kali dequeue: ");
    displayQueue(q);

    if (isEmpty(q)) {
        printf("Queue kosong.\n");
    } else {
        printf("Queue tidak kosong.\n");
    }

    // Enqueue hingga antrian penuh
    for (int i = 0; i < CAPACITY; i++) {
        char name[20];
        sprintf(name, "Item %d", i + 1);
        Barang newBarang;
        CopyWord(newBarang.name, name, MAX_LEN);
        newBarang.price = i + 1;
        enqueue(&q, newBarang);
    }
    printf("Queue setelah penuh: ");
    displayQueue(q);

    // Cek jika queue penuh
    if (isFull(q)) {
        printf("Queue sudah penuh.\n");
    }

    return 0;
}