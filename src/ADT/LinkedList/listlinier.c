#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmptyList(List L) {
    return (First(L) == Nol);
}

void CreateEmptyList(List *L) {
    First(*L) = Nol;
}

void PrintInfo(List L) {
    address_list P = First(L);
    int idx = 1;
    while (P != Nol) {
        printf("%d %s", idx, Info(P));
        P = Next(P);
        if (P != Nol) {
            printf("\n");
        }
        idx++;
    }
    printf("\n");
}

address_list Alokasi(infotypes X) {
    address_list P = (address_list) malloc(sizeof(ElmtList));
    if (P != Nol) {
        Info(P) = X;
        Next(P) = Nol;
    }
    return P;
}

void Dealokasi(address_list *P) {
    free(*P);
}

address_list Search(List L, infotypes X) {
    address_list P = First(L);
    while (P != Nol) {
        char *info = Info(P);
        char *x = X;
        int match = 1;
        while (*info && *x) {
            if (*info != *x) {
                match = 0;
                break;
            }
            info++;
            x++;
        }
        if (match && *info == '\0' && *x == '\0') {
            return P;
        }
        P = Next(P);
    }
    return Nol;
}


void InsVLast(List *L, infotypes X) {
    // Alokasi node baru
    address_list P = Alokasi(X); 
    if (P != Nol) {
        InsertLast(L, P); // Masukkan node baru ke akhir list
    }
}

void InsertLast(List *L, address_list P) {
    if (IsEmptyList(*L)) {
        First(*L) = P;
    } else {
        address_list last = First(*L);
        while (Next(last) != Nol) {
            last = Next(last);
        }
        Next(last) = P;
    }
}

void DelP(List *L, infotypes X) {
    address_list P = First(*L);
    address_list prev = Nol;
    while (P != Nol) {
        char *info = Info(P);
        char *x = X;
        int match = 1;
        while (*info && *x) {
            if (*info != *x) {
                match = 0;
                break;
            }
            info++;
            x++;
        }
        if (match && *info == '\0' && *x == '\0') {
            if (prev == Nol) {
                First(*L) = Next(P);
            } else {
                Next(prev) = Next(P);
            }
            Dealokasi(&P);
            return;
        }
        prev = P;
        P = Next(P);
    }
}

void DelVFirst(List *L, infotypes *X) {
    if (!IsEmptyList(*L)) {
        address_list P = First(*L);
        *X = Info(P);
        First(*L) = Next(P);
        Dealokasi(&P);
    }
}

int NbElmt(List L) {
    address_list P = First(L);
    int count = 0;
    while (P != Nol) {
        count++;
        P = Next(P);
    }
    return count;
}

infotypes Max(List L) {
    infotypes max = Info(First(L));
    address_list P = Next(First(L));
    while (P != Nol) {
        if (Info(P) > max) {
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}

address_list AdrMax(List L) {
    address_list maxAdr = First(L);
    address_list P = Next(First(L));
    while (P != Nol) {
        if (Info(P) > Info(maxAdr)) {
            maxAdr = P;
        }
        P = Next(P);
    }
    return maxAdr;
}

infotypes Min(List L) {
    infotypes min = Info(First(L));
    address_list P = Next(First(L));
    while (P != Nol) {
        if (Info(P) < min) {
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}

void InversList(List *L) {
    address_list prev = Nol;
    address_list current = First(*L);
    address_list next = Nol;
    while (current != Nol) {
        next = Next(current);
        Next(current) = prev;
        prev = current;
        current = next;
    }
    First(*L) = prev;
}

void Konkat1(List *L1, List *L2, List *L3) {
    CreateEmptyList(L3);
    address_list P;

    // Copy L1 to L3
    P = First(*L1);
    while (P != Nol) {
        InsVLast(L3, Info(P));
        P = Next(P);
    }

    // Copy L2 to L3
    P = First(*L2);
    while (P != Nol) {
        InsVLast(L3, Info(P));
        P = Next(P);
    }

    // Empty L1 and L2
    CreateEmptyList(L1);
    CreateEmptyList(L2);
}