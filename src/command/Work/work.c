#include <stdio.h>
#include "work.h"

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
    int jobNameLength = 0;
    while (jobName[jobNameLength] != '\0') {
        jobNameLength++;
    }

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


void Work(User *user) {
    printf("User %s now has %s as password.\n", user->name, user->password);
    printf("User %s now has %d money.\n", user->name, user->money);
    printf("Daftar pekerjaan:\n");
    printf("+----+-----------------------------+-----------+---------+\n");
    printf("| No | Job Name                    | Salary    | Duration|\n");
    printf("+----+-----------------------------+-----------+---------+\n");
    for (int i = 0; i < jobCount; i++) {
        printf("| %-2d | %-27s | %-9d | %-7ds |\n", i + 1, jobs[i].jobName, jobs[i].salary, jobs[i].duration);
    }
    printf("+----+-----------------------------+-----------+---------+\n");

    printf("\nMasukkan nama pekerjaan yang dipilih: \n");
    printf(">>> ");
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

    printf("\nAnda sedang bekerja sebagai %s... harap tunggu selama %d detik.\n", 
            selectedJob->jobName, selectedJob->duration);
    displayLoadingScreen(selectedJob->duration);
    user->money += selectedJob->salary; 
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", selectedJob->salary);

    printf("User %s now has %d money.\n", user->name, user->money);
}
