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
    printf("You has %d money.\n", user->money);
    printf("Daftar pekerjaan:\n");
    printf("+----+-----------------------------+-----------+---------+\n");
    printf("| No | Job Name                    | Salary    | Duration|\n");
    printf("+----+-----------------------------+-----------+---------+\n");
    for (int i = 0; i < jobCount; i++) {
        printf("| %-2d | %-27s | %-9d | %-7ds |\n", i + 1, jobs[i].jobName, jobs[i].salary, jobs[i].duration);
    }
    printf("+----+-----------------------------+-----------+---------+\n");
    while (1) {
        printf("Masukkan nama pekerjaan yang dipilih: \n");
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
            continue;
        }

        printf("Anda sedang bekerja sebagai %s... harap tunggu selama %d detik.\n", 
                selectedJob->jobName, selectedJob->duration);
        displayLoadingScreen(selectedJob->duration);
        user->money += selectedJob->salary; 
        printf("Pekerjaan selesai, +%d telah ditambahkan ke akun Anda.\n", selectedJob->salary);
        printf("User %s sekarang memiliki %d.\n", user->name, user->money);
        break;
    }
}
