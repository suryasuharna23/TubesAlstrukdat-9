#include <stdio.h>

// Cek apakah program dijalankan di Windows
#ifdef _WIN32
    #include <windows.h> // untuk fungsi Sleep di Windows
    #define sleep(seconds) Sleep((seconds) * 1000) // Konversi detik ke milidetik
#else
    #include <unistd.h> // untuk fungsi sleep di Linux/macOS
#endif

#include "work.h"

// Daftar pekerjaan dan pendapatannya
typedef struct {
    char jobName[50];
    int salary;
    int duration; // dalam detik
} Job;

Job jobs[] = {
    {"Evil Lab Assistant", 100, 14},
    {"OWCA Hiring Manager", 4200, 21},
    {"Cikapundunginator Caretaker", 7000, 30},
    {"Mewing Specialist", 10000, 22},
    {"Inator Connoisseur", 997, 15}
};

int jobCount = sizeof(jobs) / sizeof(jobs[0]);

// Fungsi WORK
void work(User *user) {
    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < jobCount; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", i + 1, jobs[i].jobName, jobs[i].salary, jobs[i].duration);
    }

    printf("\nMasukkan nomor pekerjaan yang dipilih: ");
    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > jobCount) {
        printf("Pilihan tidak valid!\n");
        return;
    }

    Job selectedJob = jobs[choice - 1];
    printf("\nAnda sedang bekerja sebagai %s... harap tunggu.\n", selectedJob.jobName);

    // Simulasi waktu bekerja dengan fungsi sleep yang kompatibel
    sleep(selectedJob.duration);

    // Menambahkan pendapatan ke saldo user
    AddMoney(user, selectedJob.salary);
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", selectedJob.salary);
}
