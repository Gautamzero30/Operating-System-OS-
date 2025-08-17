#include <stdio.h>

int main() {
    int ms, bs, nob, ef, n, mp[10], tif = 0, i, p = 0;

    // Input total memory size
    printf("Enter the total memory available (in Bytes) -- ");
    scanf("%d", &ms);

    // Input block size
    printf("Enter the block size (in Bytes) -- ");
    scanf("%d", &bs);

    // Calculate number of blocks
    nob = ms / bs;

    // Calculate external fragmentation
    ef = ms - nob * bs;

    // Input number of processes
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    // Input memory requirements for each process
    for (i = 0; i < n; i++) {
        printf("Enter memory required for process %d (in Bytes) -- ", i + 1);
        scanf("%d", &mp[i]);
    }

    // Display header
    printf("\nNo. of Blocks available in memory -- %d", nob);
    printf("\n\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

    // Allocate memory
    for (i = 0; i < n && p < nob; i++) {
        printf("\n%d\t\t%d", i + 1, mp[i]);

        if (mp[i] > bs) {
            printf("\t\tNO\t\t---");
        } else {
            printf("\t\tYES\t\t%d", bs - mp[i]);
            tif = tif + bs - mp[i];
            p++; // Increment allocated process count
        }
    }

    // If not all processes were allocated
    if (i < n)
        printf("\nMemory is Full, Remaining Processes cannot be accommodated");

    // Final results
    printf("\n\nTotal Internal Fragmentation is %d", tif);
    printf("\nTotal External Fragmentation is %d\n", ef);

    return 0;
}
