#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmptyList (List L){
    return (First(L) == Nol);
}

void CreateEmptyList (List *L){
    First(*L) = Nol;
}

address_list Alokasi (infotypes X){
    address_list P = (address_list) malloc (sizeof(ElmtList));
    if (P != Nol){
        Info(P) = X;
        Next(P) = Nol;
    }
    return P;
}

void Dealokasi (address_list *P){
    free (*P);
}

address_list Search (List L, infotypes X){
    address_list P = First(L);

    while (P != Nol && Info(P) != X){
        P = Next(P);
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NolAI ******************/

void InsVFirst (List *L, infotypes X){
    address_list P = Alokasi(X);

    if (P != Nol){
        Next(P) =  First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, infotypes X){
    address_list P = Alokasi(X);
    
    if (P != Nol){
        if (IsEmptyList(*L)){
            First(*L) = P;
        }
        else{
            address_list Last = First(*L);
            while (Next(Last) != Nol){
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}

void DelVFirst (List *L, infotypes *X){
    address_list P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast (List *L, infotypes *X){
    address_list Last = First(*L);
    address_list PrecLast = Nol;

    while (Next(Last)!=Nol){
        PrecLast = Last;
        Last = Next(Last);
    }

    *X = Info(Last);
    if (PrecLast == Nol){
        First(*L) = Nol;
    }
    else{
        Next(PrecLast) = Nol;
    }

    Dealokasi(&Last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/

void InsertFirst (List *L, address_list P){
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address_list P, address_list Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address_list P){
    if (IsEmptyList(*L)){
        InsertFirst(L, P);
    } else {
        address_list Last = First(*L);
        while (Next(Last) != Nol){
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/

void DelFirst (List *L, address_list *P){
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nol; 
}

void DelP (List *L, infotypes X){
    address_list P = First(*L);
    address_list Prec = Nol;
    while (P != Nol && Info(P) != X){
        Prec = P;
        P = Next(P);
    }
    if (P != Nol){
        if (Prec == Nol){
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        Next(P) = Nol;
        Dealokasi(&P);
    }
}

void DelLast (List *L, address_list *P){
    address_list Last = First(*L);
    address_list PrecLast = Nol;
    while (Next(Last) != Nol){
        PrecLast = Last;
        Last = Next(Last);
    }
    *P = Last;
    if (PrecLast == Nol){
        First(*L) = Nol;
    } else {
        Next(PrecLast) = Nol;
    }
}

void DelAfter (List *L, address_list *Pdel, address_list Prec){
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nol;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/

void PrintInfo (List L){
    address_list P = First(L);
    int idx = 1;
    while (P != Nol) {
        printf("%d %s\n", idx, Info(P));
        P = Next(P);
        idx++;
    }
}

int NbElmt (List L){
    address_list P = First(L);
    int count = 0;

    while (P != Nol){
        count++;
        P = Next(P);
    }
    return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotypes Max (List L){
    infotypes max = Info(First(L));
    address_list P = Next(First(L));

    while (P != Nol){
        if (Info(P) > max){
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}

address_list AdrMax (List L){
    address_list P = Next(First(L));
    address_list max = First(L);

    while (P != Nol){
        if (Info(P) > Info(max)){
            max = P;
        }
        P = Next(P);
    }
    return max;
}

infotypes Min (List L){
    infotypes min = Info(First(L));
    address_list P = Next(First(L));

    while (P != Nol){
        if (Info(P) < min){
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}

address_list AdrMin (List L){
    address_list P = Next(First(L));
    address_list min = First(L);

    while (P != Nol){
        if (Info(P) < Info(min)){
            min = P;
        }
        P = Next(P);
    }
    return min;
}

float Average (List L){
    address_list P = First(L);
    float sum = 0;
    int count = 0;

    while (P != Nol){
        sum += Info(P);
        count++;
        P = Next(P);
    }
    return sum / count;
}

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
    address_list P = First(*L);
    address_list Prec = Nol;
    address_list NextP = Nol;

    while (P != Nol){
        NextP = Next(P);
        Next(P) = Prec;
        Prec = P;
        P = NextP;
    }
    First(*L) = Prec;
}

void Konkat1 (List *L1, List *L2, List *L3){
    First(*L3) = First(*L1);
    if (IsEmptyList(*L3)){
        First(*L3) = First(*L2);
    } else {
        address_list Last = First(*L3);
        while (Next(Last) != Nol){
            Last = Next(Last);
        }
        Next(Last) = First(*L2);
    }
    CreateEmptyList(L1);
    CreateEmptyList(L2);
}


