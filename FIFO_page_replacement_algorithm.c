#include <stdio.h>
#include <conio.h>

int fr[3]; // Frame array

void display() {
    int i;
    printf("\n");
    for (i = 0; i < 3; i++) {
        if (fr[i] != -1)
            printf("%d\t", fr[i]);
        else
            printf("-\t");
    }
}

void main() {
    int i, j;
    int page[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int flag1 = 0, flag2 = 0, pf = 0, frsize = 3, top = 0;

    // Initialize frames with -1 (empty)
    for (i = 0; i < frsize; i++) {
        fr[i] = -1;
    }

    for (j = 0; j < 12; j++) {
        flag1 = 0; 
        flag2 = 0;

        // Check if page is already in a frame
        for (i = 0; i < frsize; i++) {
            if (fr[i] == page[j]) {
                flag1 = 1; // Page found
                flag2 = 1; // No replacement needed
                break;
            }
        }

        // If page not found, place it in empty frame (if available)
        if (flag1 == 0) {
            for (i = 0; i < frsize; i++) {
                if (fr[i] == -1) {
                    fr[i] = page[j];
                    flag2 = 1;
                    pf++;
                    break;
                }
            }
        }

        // If no empty frame, replace using FIFO
        if (flag2 == 0) {
            fr[top] = page[j];
            top = (top + 1) % frsize; // Circular queue
            pf++;
        }

        display(); // Show current frame status
    }

    printf("\nNumber of page faults : %d", pf);
    getch();
}
