#include <stdio.h>
#include <string.h>

int main() {
    char job[10][10]; // Job names
    int time[10];     // Resource requirements
    int avail;        // Available resources
    int order[10];    // Job order after sorting
    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter job name and time: ");
        scanf("%s %d", job[i], &time[i]);
        order[i] = i; // Keep track of original index
    }

    printf("Enter available resources: ");
    scanf("%d", &avail);

    // Sort jobs by time (smallest requirement first)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (time[order[i]] > time[order[j]]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    // Try executing jobs
    int safeSeq[10], safeCount = 0;
    for (int i = 0; i < n; i++) {
        int idx = order[i];
        if (time[idx] <= avail) {
            avail -= time[idx]; // Deduct resources (or add back if modeling release)
            safeSeq[safeCount++] = idx;
        } else {
            printf("\nNo safe sequence possible.\n");
            return 0;
        }
    }

    // Print safe sequence
    printf("\nSafe sequence is: ");
    for (int i = 0; i < safeCount; i++) {
        printf("%s (%d) ", job[safeSeq[i]], time[safeSeq[i]]);
    }
    printf("\n");

    return 0;
}
