#ifndef GRAPH_H
#define GRAPH_H

#define TAK_TERHINGGA 1000000

typedef struct {
    int jumlah_lokasi;
    int **matriks_jarak;
} Graf;

Graf* buatGraf(int jumlah_lokasi);
void tambahJalur(Graf *graf, int lokasi1, int lokasi2, int jarak);
void rutePalingEfektif(Graf *graf);
void mulaiTSP();

#endif