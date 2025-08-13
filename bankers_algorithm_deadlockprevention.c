#include <stdio.h>

int main() {
    int n, m; // Number of processes and resources
    int alloc[10][10], max[10][10], need[10][10];
    int total[10], avail[10], work[10];
    int finish[10] = {0}; // 0 = not finished, 1 = finished
    int safeSequence[10];
    int count = 0;

    // Input
    printf("Enter number of processes and number of resources: ");
    scanf("%d %d", &n, &m);

    printf("Enter the Max matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the Allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the total resources vector: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &total[i]);

    // Calculate Available resources
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += alloc[i][j];
        avail[j] = total[j] - sum;
        work[j] = avail[j];
    }

    // Calculate Need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's Safety Algorithm
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int canExecute = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = 0;
                        break;
                    }
                }
                if (canExecute) {
                    // Add allocated resources back to work
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("\nSystem is in UNSAFE state!\n");
            return 0;
        }
    }

    // Print results
    printf("\nSystem is in SAFE state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSequence[i]);
    printf("\n");

    return 0;
}
