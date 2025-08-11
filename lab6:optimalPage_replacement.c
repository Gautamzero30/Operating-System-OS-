#include <stdio.h>

int fr[10], n, m;

void display() {
    for (int i = 0; i < m; i++) {
        if (fr[i] != -1)
            printf("%d\t", fr[i]);
        else
            printf("-\t");
    }
    printf("\n");
}

int main() {
    int page[50], lg[10], i, j, k, index, found, max;
    int pf = 0; 
    float pr;

    printf("Enter length of the reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter no of frames: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
        fr[i] = -1;

    for (j = 0; j < n; j++) {
        int flag1 = 0, flag2 = 0;

        // Check if page is already in frame
        for (i = 0; i < m; i++) {
            if (fr[i] == page[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        // Empty slot available
        if (flag1 == 0) {
            for (i = 0; i < m; i++) {
                if (fr[i] == -1) {
                    fr[i] = page[j];
                    pf++;
                    flag2 = 1;
                    break;
                }
            }
        }

        // Replacement needed
        if (flag2 == 0) {
            for (i = 0; i < m; i++) {
                lg[i] = 9999; // large value meaning "not found in future"
                for (k = j + 1; k < n; k++) {
                    if (fr[i] == page[k]) {
                        lg[i] = k - j;
                        break;
                    }
                }
            }

            found = 0;
            for (i = 0; i < m; i++) {
                if (lg[i] == 9999) { // page not used again
                    index = i;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                max = lg[0];
                index = 0;
                for (i = 1; i < m; i++) {
                    if (lg[i] > max) {
                        max = lg[i];
                        index = i;
                    }
                }
            }

            fr[index] = page[j];
            pf++;
        }

        display();
    }

    printf("Number of page faults: %d\n", pf);
    pr = (float)pf / n * 100;
    printf("Page fault rate = %.2f%%\n", pr);

    return 0;
}
