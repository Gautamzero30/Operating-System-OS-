#include <stdio.h>

#define MAX 100

int main() {
    int n, i, time_slice;
    int burst[MAX], remaining[MAX];
    int waiting[MAX], turnaround[MAX];
    int completed = 0, current_time = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];  // Initialize remaining times
    }

    printf("Enter the time slice (quantum): ");
    scanf("%d", &time_slice);

    // Initialize waiting times to 0
    for(i = 0; i < n; i++) {
        waiting[i] = 0;
    }

    while(completed < n) {
        int done_in_this_cycle = 0;
        for(i = 0; i < n; i++) {
            if(remaining[i] > 0) {
                if(remaining[i] <= time_slice) {
                    // Process can finish in this time slice
                    current_time += remaining[i];
                    remaining[i] = 0;
                    turnaround[i] = current_time; 
                    waiting[i] = turnaround[i] - burst[i];
                    completed++;
                    done_in_this_cycle = 1;
                } else {
                    // Process not finished yet
                    remaining[i] -= time_slice;
                    current_time += time_slice;
                    done_in_this_cycle = 1;
                }
            }
        }
        // If no process was executed in this cycle, break to avoid infinite loop
        if(!done_in_this_cycle) break;
    }

    // Calculate averages
    float total_waiting = 0, total_turnaround = 0;
    for(i = 0; i < n; i++) {
        total_waiting += waiting[i];
        total_turnaround += turnaround[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround / n);

    return 0;
}
