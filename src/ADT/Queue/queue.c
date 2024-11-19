#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q)
{
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isFull(Queue q)
{
    return (q.idxHead == 0 && q.idxTail == CAPACITY - 1) || (q.idxTail + 1 == q.idxHead);
}

int length(Queue q) {
    if (isEmpty(q)) {
        return 0;
    } else if (q.idxTail >= q.idxHead) {
        return q.idxTail - q.idxHead + 1;
    } else {
        return CAPACITY - q.idxHead + q.idxTail + 1;
    }
}

void enqueue(Queue *q, Barang val)
{
    if (isFull(*q))
    {
        printf("Antrian penuh!\n");
    }
    if (isEmpty(*q)) {
        q->idxHead = 0;
        q->idxTail = 0;
    } else {
        q->idxTail = (q->idxTail + 1) % CAPACITY;
    }
    q->buffer[q->idxTail] = val;
}

void dequeue(Queue *q, Barang *val)
{
    if (isEmpty(*q))
    {
        printf("Antrian kosong!\n");
        return;
    }
    *val = q->buffer[q->idxHead];
    if (q->idxHead == q->idxTail) {
        q->idxHead = IDX_UNDEF;
        q->idxTail = IDX_UNDEF;
    } else {
        q->idxHead = (q->idxHead + 1) % CAPACITY;
    }
}

void displayQueue(Queue q)
{
    if (isEmpty(q))
    {
        printf("Antrian kosong\n");
    }
    int i = q.idxHead;
    while (i != q.idxTail) {
        printf("%s, %d ", q.buffer[i].name, q.buffer[i].price);
        i = (i + 1) % CAPACITY;
    }
    printf("%s, %d\n", q.buffer[i].name, q.buffer[i ].price);
}