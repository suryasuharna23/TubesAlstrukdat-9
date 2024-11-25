#include <stdio.h>
#include "list.h"

/* ********** KONSTRUKTOR ********** */
ListStatic MakeListStatic()
/* Konstruktor: create list statis yang kosong */
/* I.S. sembarang */
/* F.S. Terbentuk list L statis kosong dengan kapasitas MaxEl */
{
    ListStatic L;
	L.Neff = 0;
	return L;
}


/* ********** TEST KOSONG/PENUH ********** */
boolean IsListStaticEmpty(ListStatic L)
/* *** Test list statis kosong *** */
/* Mengirimkan true jika list statis L kosong, mengirimkan false jika tidak */

{
    return (L.Neff == 0);
}


/* ********** SELEKTOR ********** */
int LengthListStatic(ListStatic L)
/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
{
    return (L.Neff);
}


ElType GetListStatic(ListStatic L, int i)
/* *** Menghasilkan sebuah elemen *** */
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */
{
	return L.A[i];
}


void InsertLastListStatic(ListStatic *L, ElType X)
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
{
    int i = LengthListStatis(*L);
	L->A[i] = X;
	L->Neff ++;
}