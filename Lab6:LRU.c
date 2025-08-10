
#include <stdio.h>
#include <conio.h>

int fr[3]; // Frames

void display(int frsize) {
    int i;
    printf("\n");
    for (i = 0; i < frsize; i++) {
        if (fr[i] != -1)
            printf("%d\t", fr[i]);
        else
            printf("-\t");
    }
}

void main() {
    int p[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int fs[3], frsize = 3;
    int i, j, k, l, index = 0;
    int flag1, flag2, pf = 0;

    // Initialize frames
    for (i = 0; i < frsize; i++)
        fr[i] = -1;

    for (j = 0; j < 12; j++) {
        flag1 = flag2 = 0;

        // Check if page is already in frame
        for (i = 0; i < frsize; i++) {
            if (fr[i] == p[j]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        // If not found, put it in empty frame
        if (flag1 == 0) {
            for (i = 0; i < frsize; i++) {
                if (fr[i] == -1) {
                    fr[i] = p[j];
                    flag2 = 1;
                    pf++;
                    break;
                }
            }
        }

        // If no empty frame, replace LRU page
        if (flag2 == 0) {
            for (i = 0; i < frsize; i++)
                fs[i] = 0;

            // Look back in history
            for (k = j - 1, l = 1; l <= frsize - 1; l++, k--) {
                for (i = 0; i < frsize; i++) {
                    if (fr[i] == p[k])
                        fs[i] = 1;
                }
            }

            // Find the page that was least recently used
            for (i = 0; i < frsize; i++) {
                if (fs[i] == 0) {
                    index = i;
                    break;
                }
            }

            fr[index] = p[j];
            pf++;
        }

        display(frsize);
    }

    printf("\nNumber of page faults: %d", pf);
    getch();
}
