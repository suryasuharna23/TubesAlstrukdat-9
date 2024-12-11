#include "map.h"
#include "boolean.h"
#include <stdio.h>

void CreateEmpty(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    (*M).Count = Nil;
}

boolean IsEmpty(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return(M.Count == Nil);
}

boolean IsFull(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
    return(M.Count == MaxElMap);
}

valuetype Value(Map M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
    int i = 0;
    boolean found = false;

    while (i < M.Count && !found){
        if (M.Elements[i].Key == k)
        {
            found = true;
        }
        else{
            i++;
        }
    }
    if (found)
    {
        return(M.Elements[i].Value);
    }
    else
    {
        return (Undefined);
    }
}

void Insert(Map *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (!IsMember(*M, k))
    {
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value = v;
        (*M).Count++;
    }
}

void Delete(Map *M, keytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    int i = 0;
    
    if(IsMember(*M, k))
    {
        while ((*M).Elements[i].Key != k)
        {
            i++;
        }
        (*M).Elements[i] = (*M).Elements[(*M).Count-1];
        //(*M).Elements[i].Key = (*M).Elements[i-1].Key;
        //(*M).Elements[i].Value = (*M).Elements[i-1].Value;
      
        (*M).Count--;
    }
}


boolean IsMember(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    int i = 0;
    //boolean found = false;

    while (i < M.Count && M.Elements[i].Key != k)
    {
        i++;
    }
    if (i == M.Count)
    {
        return false;
    }
    else{
        return true;
    }
    //return found;
}