#include <stdio.h>

int main() {
    int ms, bs, nob, ef, n, mp[50], tif = 0;
    int i, p = 0;

    // Input total memory size
    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &ms);

    // Input block size
    printf("Enter the block size (in Bytes): ");
    scanf("%d", &bs);

    // Calculate number of blocks and external fragmentation
    nob = ms / bs;
    ef = ms - nob * bs;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input memory requirement for each process
    for (i = 0; i < n; i++) {
        printf("Enter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &mp[i]);
    }

    // Display header
    printf("\nNo. of Blocks available in memory: %d", nob);
    printf("\n\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");

    // Allocate memory to processes
    for (i = 0; i < n && p < nob; i++) {
        printf("\nP%d\t\t%d", i + 1, mp[i]);

        if (mp[i] > bs) {
            printf("\t\tNO\t\t---");
        } else {
            printf("\t\tYES\t\t%d", bs - mp[i]);
            tif += (bs - mp[i]);
            p++; // Increase allocated process count
        }
    }

    // If there are processes left after blocks are filled
    if (i < n)
        printf("\nMemory is Full, Remaining Processes cannot be accommodated");

    // Display fragmentation results
    printf("\n\nTotal Internal Fragmentation = %d Bytes", tif);
    printf("\nTotal External Fragmentation = %d Bytes\n", ef);

    return 0;
}
