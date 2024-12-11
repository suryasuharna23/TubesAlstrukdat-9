#ifndef STACK_H
#define STACK_H

#include "boolean.h"

#define NMAX 100
#define NilStack -1

typedef struct {
    char name[50];
    int quantity;
    int total;
} PurchaseItem;

typedef struct {
    PurchaseItem items[NMAX];
    int count;
    int totalCost;
} Purchase;

typedef struct {
    Purchase purchases[NMAX];
    int top;
} Stack;

/* *** Konstruktor/Kreator *** */
void CreateEmptyS(Stack *S);
/* Membuat sebuah stack S yang kosong berkapasitas NMAX */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS(Stack S);
/* Mengirim true jika Stack kosong */
boolean IsFullS(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, Purchase X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru, TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, Purchase *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif