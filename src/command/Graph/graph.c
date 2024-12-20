#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Untuk INT_MAX
#include "graph.h"
#include "../../ADT/Mesin/mesinkata.h"
#include "../../ADT/Mesin/mesinkarakter.h"

int *rute_terbaik;
int *rute_sementara;
int *sudah_dikunjungi;
int biaya_terkecil;

// Fungsi untuk Mencari Rute Terbaik
void cariRuteTerbaik(Graf *graf, int lokasi_sekarang, int jumlah_terkunjungi, int biaya_sementara) {
    if (jumlah_terkunjungi == graf->jumlah_lokasi) {
        if (biaya_sementara < biaya_terkecil) {
            biaya_terkecil = biaya_sementara;
            for (int i = 0; i < graf->jumlah_lokasi; i++) {
                rute_terbaik[i] = rute_sementara[i];
            }
        }
        return;
    }

    for (int lokasi_berikutnya = 0; lokasi_berikutnya < graf->jumlah_lokasi; lokasi_berikutnya++) {
        if (!sudah_dikunjungi[lokasi_berikutnya] && graf->matriks_jarak[lokasi_sekarang][lokasi_berikutnya] != TAK_TERHINGGA) {
            sudah_dikunjungi[lokasi_berikutnya] = 1;
            rute_sementara[jumlah_terkunjungi] = lokasi_berikutnya;
            cariRuteTerbaik(graf, lokasi_berikutnya, jumlah_terkunjungi + 1, biaya_sementara + graf->matriks_jarak[lokasi_sekarang][lokasi_berikutnya]);
            sudah_dikunjungi[lokasi_berikutnya] = 0;
        }
    }
}

// Fungsi Membuat Graf
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

// Fungsi Menambahkan Jalur
void tambahJalur(Graf *graf, int lokasi1, int lokasi2, int jarak) {
    graf->matriks_jarak[lokasi1][lokasi2] = jarak;
    graf->matriks_jarak[lokasi2][lokasi1] = jarak;
}

// Fungsi Mencari Rute Paling Efektif
void rutePalingEfektif(Graf *graf) {
    rute_terbaik = (int*) malloc(graf->jumlah_lokasi * sizeof(int));
    rute_sementara = (int*) malloc(graf->jumlah_lokasi * sizeof(int));
    sudah_dikunjungi = (int*) calloc(graf->jumlah_lokasi, sizeof(int));
    biaya_terkecil = TAK_TERHINGGA;

    sudah_dikunjungi[0] = 1;
    rute_sementara[0] = 0;
    cariRuteTerbaik(graf, 0, 1, 0);

    printf("A-ha! Rute paling efektif adalah ");
    for (int i = 0; i < graf->jumlah_lokasi; i++) { // Tidak mencetak node kembali
        printf("%d", rute_terbaik[i]);
        if (i < graf->jumlah_lokasi - 1) printf("-");
    }
    printf(" dengan total jarak %d.\n", biaya_terkecil);

    free(sudah_dikunjungi);
    free(rute_sementara);
    free(rute_terbaik);
}

void mulaiTSP() {
    int jumlah_lokasi, jumlah_rute;
    printf("Masukkan jumlah lokasi pengiriman (node): ");
    scanf("%d", &jumlah_lokasi);

    Graf *graf = buatGraf(jumlah_lokasi);

    printf("Masukkan jumlah rute (edge): ");
    scanf("%d", &jumlah_rute);

    printf("Masukkan jarak antarlokasi (weight):\n");
    for (int i = 0; i < jumlah_rute; i++) {
        int lokasi1, lokasi2, jarak;
        scanf("%d %d %d", &lokasi1, &lokasi2, &jarak);
        tambahJalur(graf, lokasi1, lokasi2, jarak);
    }

    printf("\nData diterima, silakan tunggu.\n");
    rutePalingEfektif(graf);

    for (int i = 0; i < jumlah_lokasi; i++) {
        free(graf->matriks_jarak[i]);
    }
    free(graf->matriks_jarak);
    free(graf);
    
    while (1) {
        printf("Ketik 'OPTIMASIRUTE' untuk menganalisis lagi atau 'BACK' untuk kembali: \n");
        printf(">>> ");
        STARTINPUTWORD();
        
        if (isEqual(CurrentWord, "BACK")) {
            printf("Kembali ke menu utama.\n");
            return;
        } else if (isEqual(CurrentWord, "OPTIMASIRUTE")) {
            mulaiTSP();
        } else {
            printf("Perintah tidak dikenal. Silakan coba lagi.\n");
        }
    }

}