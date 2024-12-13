#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyS(Stack *S) {
    S->top = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS(Stack S) {
    return (S.top == NilStack);
}

boolean IsFullS(Stack S) {
    return (S.top == NMAX - 1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, Purchase X) {
    if (!IsFullS(*S)) {
        S->top++;
        S->purchases[S->top] = X;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, Purchase *X) {
    if (!IsEmptyS(*S)) {
        *X = S->purchases[S->top];
        S->top--;
    }
}