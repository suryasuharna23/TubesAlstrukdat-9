#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmpty (List L){
    return (First(L) == Nil);
}

void CreateEmpty (List *L){
    First(*L) = Nil;
}

address Alokasi (infotype X){
    address P = (address) malloc (sizeof(ElmtList));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P){
    free (*P);
}

address Search (List L, infotype X){
    address P = First(L);

    while (P != Nil && Info(P) != X){
        P = Next(P);
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/

void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);

    if (P != Nil){
        Next(P) =  First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    
    if (P != Nil){
        if (IsEmpty(*L)){
            First(*L) = P;
        }
        else{
            address Last = First(*L);
            while (Next(Last) != Nil){
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}

void DelVFirst (List *L, infotype *X){
    address P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotype *X){
    address Last = First(*L);
    address PrecLast = Nil;

    while (Next(Last)!=Nil){
        PrecLast = Last;
        Last = Next(Last);
    }

    *X = Info(Last);
    if (PrecLast == Nil){
        First(*L) = Nil;
    }
    else{
        Next(PrecLast) = Nil;
    }

    Dealokasi(&Last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/

void InsertFirst (List *L, address P){
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P){
    if (IsEmpty(*L)){
        InsertFirst(L, P);
    } else {
        address Last = First(*L);
        while (Next(Last) != Nil){
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/

void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil; 
}

void DelP (List *L, infotype X){
    address P = First(*L);
    address Prec = Nil;
    while (P != Nil && Info(P) != X){
        Prec = P;
        P = Next(P);
    }
    if (P != Nil){
        if (Prec == Nil){
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        Next(P) = Nil;
        Dealokasi(&P);
    }
}

void DelLast (List *L, address *P){
    address Last = First(*L);
    address PrecLast = Nil;
    while (Next(Last) != Nil){
        PrecLast = Last;
        Last = Next(Last);
    }
    *P = Last;
    if (PrecLast == Nil){
        First(*L) = Nil;
    } else {
        Next(PrecLast) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/

void PrintInfo (List L){
    address P = First(L);
    int idx = 1;
    while (P != Nil) {
        printf("%d %s\n", idx, Info(P));
        P = Next(P);
        idx++;
    }
}

int NbElmt (List L){
    address P = First(L);
    int count = 0;

    while (P != Nil){
        count++;
        P = Next(P);
    }
    return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
    infotype max = Info(First(L));
    address P = Next(First(L));

    while (P != Nil){
        if (Info(P) > max){
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}

address AdrMax (List L){
    address P = Next(First(L));
    address max = First(L);

    while (P != Nil){
        if (Info(P) > Info(max)){
            max = P;
        }
        P = Next(P);
    }
    return max;
}

infotype Min (List L){
    infotype min = Info(First(L));
    address P = Next(First(L));

    while (P != Nil){
        if (Info(P) < min){
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}

address AdrMin (List L){
    address P = Next(First(L));
    address min = First(L);

    while (P != Nil){
        if (Info(P) < Info(min)){
            min = P;
        }
        P = Next(P);
    }
    return min;
}

float Average (List L){
    address P = First(L);
    float sum = 0;
    int count = 0;

    while (P != Nil){
        sum += Info(P);
        count++;
        P = Next(P);
    }
    return sum / count;
}

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
    address P = First(*L);
    address Prec = Nil;
    address NextP = Nil;

    while (P != Nil){
        NextP = Next(P);
        Next(P) = Prec;
        Prec = P;
        P = NextP;
    }
    First(*L) = Prec;
}

void Konkat1 (List *L1, List *L2, List *L3){
    First(*L3) = First(*L1);
    if (IsEmpty(*L3)){
        First(*L3) = First(*L2);
    } else {
        address Last = First(*L3);
        while (Next(Last) != Nil){
            Last = Next(Last);
        }
        Next(Last) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}


