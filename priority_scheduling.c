#include <stdio.h>

#define MAX 100

int main() {
    int n, i, j;
    int burst[MAX], priority[MAX];
    int waiting[MAX], turnaround[MAX];
    int completed[MAX] = {0};
    int current_time = 0, completed_count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority (lower number means higher priority):\n");
    for(i = 0; i < n; i++) {
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &burst[i]);
        printf("Process %d - Priority: ", i + 1);
        scanf("%d", &priority[i]);
    }

    while(completed_count < n) {
        // Find process with highest priority that is not completed
        int idx = -1;
        int highest_priority = 99999;
        for(i = 0; i < n; i++) {
            if(!completed[i] && priority[i] < highest_priority) {
                highest_priority = priority[i];
                idx = i;
            }
        }

        if(idx != -1) {
            // Execute the process
            waiting[idx] = current_time;
            current_time += burst[idx];
            turnaround[idx] = current_time;
            completed[idx] = 1;
            completed_count++;
        }
    }

    // Calculate averages
    float total_wt = 0, total_tat = 0;
    for(i = 0; i < n; i++) {
        waiting[i] = turnaround[i] - burst[i];  // Recalculate waiting time properly
        total_wt += waiting[i];
        total_tat += turnaround[i];
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst[i], priority[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
