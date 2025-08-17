#include <stdio.h>

int main() {
    char job[10][10];   // Array to store job names
    int time[10];       // Resource requirements for each job
    int avail, temp[10], index[10]; 
    int safe[10];       // Safe sequence
    int i, j, n, t, ind = 0;

    // Input number of jobs
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    // Input job names and their requirements
    for (i = 0; i < n; i++) {
        printf("Enter job name and time: ");
        scanf("%s %d", job[i], &time[i]);
    }

    // Input available resources
    printf("Enter the available resources: ");
    scanf("%d", &avail);

    // Copy data into temporary arrays
    for (i = 0; i < n; i++) {
        temp[i] = time[i];
        index[i] = i;
    }

    // Sort jobs based on resource requirement
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                // Swap resource requirements
                t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;

                // Swap job indices
                t = index[i];
                index[i] = index[j];
                index[j] = t;
            }
        }
    }

    // Find safe sequence
    printf("\nSafe sequence is: ");
    for (i = 0; i < n; i++) {
        int q = index[i];
        if (time[q] <= avail) {
            safe[ind++] = q;
            avail -= time[q];
            printf("%s ", job[q]);
        } else {
            printf("\nNo safe sequence possible!\n");
            return 0; // Exit if any job cannot be allocated
        }
    }

    // Print details of safe sequence
    printf("\n\nJobs in safe sequence with time:\n");
    for (i = 0; i < ind; i++) {
        printf("%s (%d)  ", job[safe[i]], time[safe[i]]);
    }

    printf("\n");
    return 0;
}
