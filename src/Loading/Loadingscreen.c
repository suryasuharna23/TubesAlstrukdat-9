#include "Loadingscreen.h"

void displayLoadingScreen(int durationInSeconds)
{
    int progress = 0;
    int maxProgress = 100;
    int barWidth = 50;
    time_t startTime, currentTime;

    printf("Work In Progress...\n");

    // Get the start time
    time(&startTime);

    while (progress < maxProgress)
    {
        // Get the current time
        time(&currentTime);

        // Calculate elapsed time
        double elapsedTime = difftime(currentTime, startTime);

        // Calculate progress based on elapsed time
        progress = (elapsedTime / durationInSeconds) * maxProgress;

        // Ensure progress does not exceed maxProgress
        if (progress > maxProgress)
        {
            progress = maxProgress;
        }

        // Display the progress bar
        printf("[");
        int pos = (progress * barWidth) / maxProgress;
        for (int i = 0; i < barWidth; ++i)
        {
            if (i < pos)
                printf("=");
            else if (i == pos)
                printf(">");
            else
                printf(" ");
        }
        printf("] %d %%\r", progress);
        fflush(stdout);

        // Sleep for a short duration to reduce CPU usage
        struct timespec ts;
        ts.tv_sec = 0;
        ts.tv_nsec = 100000000L; // 100 milliseconds
        nanosleep(&ts, NULL);
    }
    printf("\n");
}

void displayLoadingDots(int durationInSeconds)
{
    int maxDots = 10;
    time_t startTime, currentTime;

    printf("Loading");

    // Get the start time
    time(&startTime);

    while (1)
    {
        // Get the current time
        time(&currentTime);

        // Calculate elapsed time
        double elapsedTime = difftime(currentTime, startTime);

        // Break the loop if the duration has passed
        if (elapsedTime >= durationInSeconds)
        {
            break;
        }

        // Display dots based on elapsed time
        int numDots = (int)(elapsedTime * maxDots / durationInSeconds);
        printf("\rLoading");
        for (int i = 0; i < numDots; ++i)
        {
            printf(".");
        }
        fflush(stdout);

        // Sleep for a short duration to reduce CPU usage
        struct timespec ts;
        ts.tv_sec = 0;
        ts.tv_nsec = 500000000L; // 500 milliseconds
        nanosleep(&ts, NULL);
    }
    printf("\n");
}