#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int *rute_terbaik;
int *rute_sementara;
int *sudah_dikunjungi;
int biaya_terkecil;
Graf *graf_global;

void cariRuteTerbaik(int lokasi_sekarang, int jumlah_terkunjungi, int biaya_sementara) {
    if (jumlah_terkunjungi == graf_global->jumlah_lokasi) {
        biaya_sementara += graf_global->matriks_jarak[lokasi_sekarang][0];
        if (biaya_sementara < biaya_terkecil) {
            biaya_terkecil = biaya_sementara;
            for (int i = 0; i < graf_global->jumlah_lokasi; i++) {
                rute_terbaik[i] = rute_sementara[i];
            }
            rute_terbaik[graf_global->jumlah_lokasi] = 0;
        }
        return;
    }

    for (int lokasi_berikutnya = 0; lokasi_berikutnya < graf_global->jumlah_lokasi; lokasi_berikutnya++) {
        if (!sudah_dikunjungi[lokasi_berikutnya] && graf_global->matriks_jarak[lokasi_sekarang][lokasi_berikutnya] != TAK_TERHINGGA) {
            sudah_dikunjungi[lokasi_berikutnya] = 1;
            rute_sementara[jumlah_terkunjungi] = lokasi_berikutnya;
            cariRuteTerbaik(lokasi_berikutnya, jumlah_terkunjungi + 1, biaya_sementara + graf_global->matriks_jarak[lokasi_sekarang][lokasi_berikutnya]);
            sudah_dikunjungi[lokasi_berikutnya] = 0;
        }
    }
}

Graf* buatGraf(int jumlah_lokasi) {
    Graf *graf = (Graf*) malloc(sizeof(Graf));
    graf->jumlah_lokasi = jumlah_lokasi;
    graf->matriks_jarak = (int**) malloc(jumlah_lokasi * sizeof(int*));
    for (int i = 0; i < jumlah_lokasi; i++) {
        graf->matriks_jarak[i] = (int*) malloc(jumlah_lokasi * sizeof(int));
        for (int j = 0; j < jumlah_lokasi; j++) {
            graf->matriks_jarak[i][j] = (i == j) ? 0 : TAK_TERHINGGA;
        }
    }
    return graf;
}

void tambahJalur(Graf *graf, int lokasi1, int lokasi2, int jarak) {
    graf->matriks_jarak[lokasi1][lokasi2] = jarak;
    graf->matriks_jarak[lokasi2][lokasi1] = jarak;
}

void rutePalingEfektif(Graf *graf) {
    graf_global = graf;
    rute_terbaik = (int*) malloc((graf->jumlah_lokasi + 1) * sizeof(int));
    rute_sementara = (int*) malloc(graf->jumlah_lokasi * sizeof(int));
    sudah_dikunjungi = (int*) calloc(graf->jumlah_lokasi, sizeof(int));
    biaya_terkecil = TAK_TERHINGGA;

    sudah_dikunjungi[0] = 1; 
    rute_sementara[0] = 0;    
    cariRuteTerbaik(0, 1, 0);

    printf("A-ha! Rute paling efektif adalah: ");
    for (int i = 0; i <= graf->jumlah_lokasi; i++) {
        printf("%d", rute_terbaik[i]);
        if (i < graf->jumlah_lokasi) printf("-");
    }
    printf("\nTotal jarak: %d\n", biaya_terkecil);

    free(sudah_dikunjungi);
    free(rute_sementara);
    free(rute_terbaik);
}

void mulaiTSP() {
    int jumlah_lokasi;
    printf("Masukkan jumlah lokasi: ");
    scanf("%d", &jumlah_lokasi);

    Graf *graf = buatGraf(jumlah_lokasi);

    int lokasi1, lokasi2, jarak;
    while (1) {
        printf("Masukkan jalur (lokasi1 lokasi2 jarak), atau -1 untuk selesai: ");
        scanf("%d", &lokasi1);
        if (lokasi1 == -1) break;
        scanf("%d %d", &lokasi2, &jarak);
        tambahJalur(graf, lokasi1, lokasi2, jarak);
    }

    rutePalingEfektif(graf);

    for (int i = 0; i < jumlah_lokasi; i++) {
        free(graf->matriks_jarak[i]);
    }
    free(graf->matriks_jarak);
    free(graf);
}