#include <stdio.h>

int main() {
    int n, i;
    int bt[20], at[20], wt[20], tat[20], ct[20];
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time for Process %d: ", i);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
    }

    // First process calculations
    if (at[0] > 0) {
        ct[0] = at[0] + bt[0];
    } else {
        ct[0] = bt[0];
    }
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    for (i = 1; i < n; i++) {
        if (ct[i - 1] < at[i]) {
            // CPU is idle until process arrives
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
        }
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    for (i = 0; i < n; i++) {
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}
