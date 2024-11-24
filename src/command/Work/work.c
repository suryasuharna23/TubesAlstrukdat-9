#include <stdio.h>
#include "work.h"
// Cek  program dijalankan di Windows
#ifdef _WIN32
    #include <windows.h> // untuk fungsi Sleep di Windows
    #define sleep(seconds) Sleep((seconds) * 1000) // konversi detik ke milidetik
#else
    #include <unistd.h> // untuk fungsi sleep di Linux/macOS
#endif
typedef struct {
    char jobName[50];
    int salary;
    int duration; 
} Job;

Job jobs[] = {
    {"Evil Lab Assistant", 100, 14},
    {"OWCA Hiring Manager", 4200, 21},
    {"Cikapundunginator Caretaker", 7000, 30},
    {"Mewing Specialist", 10000, 22},
    {"Inator Connoisseur", 997, 15}
};

int jobCount = sizeof(jobs) / sizeof(jobs[0]);

// cocokin nama pekerjaan
boolean compareJobName(Word input, char *jobName) {
    int i;
    // panjang nama pekerjaan
    int jobNameLength = 0;
    while (jobName[jobNameLength] != '\0') {
        jobNameLength++;
    }

    // panjang input dan nama pekerjaan harus sama untuk cocok
    if (input.Length != jobNameLength) {
        return false;
    }

    for (i = 0; i < input.Length; i++) {
        if (input.TabWord[i] != jobName[i]) {
            return false; 
        }
    }
    return true;
}

// Fungsi WORK
void work(User *user) {
    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < jobCount; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", i + 1, jobs[i].jobName, jobs[i].salary, jobs[i].duration);
    }

    printf("\nMasukkan nama pekerjaan yang dipilih: ");
    STARTINPUTWORD(); 

    Job *selectedJob = NULL; // pointer ke pekerjaan yang dipilih
    for (int i = 0; i < jobCount; i++) {
        if (compareJobName(CurrentWord, jobs[i].jobName)) {
            selectedJob = &jobs[i];
            break;
        }
    }

    if (selectedJob == NULL) {
        printf("Pilihan pekerjaan tidak valid!\n");
        return;
    }
    printf("\nAnda sedang bekerja sebagai %s... harap tunggu.\n", selectedJob->jobName);
    sleep(selectedJob->duration);
    AddMoney(user, selectedJob->salary);
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", selectedJob->salary);
}
