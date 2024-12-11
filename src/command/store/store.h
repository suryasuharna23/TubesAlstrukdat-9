#ifndef __STORE_H__
#define __STORE_H__

#include "../../Boolean/boolean.h"
#include "../../ADT/Mesin/mesinkarakter.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/Barang/barang.h"
#include "../../ADT/Queue/queue.h"

void SList(ListBarang *listbarang); //menampilkan barang di list store
void SRemove(ListBarang *listbarang); //mengahpus barang dari list store
void SRequest(Queue *req, ListBarang *listbarang); //meminta barang ke list store
void SSupply(Queue *req, ListBarang *listbarang); //menambahkan barang ke list store dari store request

#endif