#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int pid;
    int burst;          // Total CPU burst time needed
    int remaining;      // Remaining CPU time
    int weight;         // Weight for priority (higher weight = higher priority)
    double vruntime;    // Virtual runtime
} Process;

int main() {
    int n, i;
    Process proc[MAX];
    double current_time = 0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority weight (higher weight means higher priority):\n");
    for(i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &proc[i].burst);
        proc[i].remaining = proc[i].burst;
        printf("Process %d priority weight: ", i + 1);
        scanf("%d", &proc[i].weight);
        proc[i].vruntime = 0.0;
    }

    printf("\nStarting CFS simulation...\n");

    while(1) {
        // Find process with minimum vruntime that is not finished
        int idx = -1;
        double min_vruntime = 1e9;
        for(i = 0; i < n; i++) {
            if(proc[i].remaining > 0 && proc[i].vruntime < min_vruntime) {
                min_vruntime = proc[i].vruntime;
                idx = i;
            }
        }

        if(idx == -1) break; // all processes finished

        // Run the chosen process for 1 unit time (for simplicity)
        proc[idx].remaining--;
        current_time += 1.0;

        // Increase vruntime proportionally (inverse of weight)
        proc[idx].vruntime += (1024.0 / proc[idx].weight);

        // Print info about this scheduling step
        printf("Time %.2f: Running Process %d (Remaining: %d, vruntime: %.2f)\n",
                current_time, proc[idx].pid, proc[idx].remaining, proc[idx].vruntime);
    }

    printf("\nAll processes completed at time %.2f\n", current_time);

    return 0;
}
