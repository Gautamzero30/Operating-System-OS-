#include<stdio.h>
#include<stdlib.h>

int main() {
    int t[50], atr[50], d[50], h, tot, n, i, j, temp, p, sum = 0;
    float avg;

    printf("Enter the number of track requests: ");
    scanf("%d", &n);
    printf("Enter the position of the head: ");
    scanf("%d", &h);
    printf("Enter the total number of tracks: ");
    scanf("%d", &tot);

    // Include lowest track, head, highest track
    t[0] = 0;
    t[1] = h;
    t[2] = tot - 1;

    printf("Enter the track requests: ");
    for (i = 3; i < n + 3; i++) {
        scanf("%d", &t[i]);
    }

    // Sort all track positions
    for (i = 0; i < n + 3; i++) {
        for (j = 0; j < n + 2 - i; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find head position
    int k = 0;
    for (i = 0; i < n + 3; i++) {
        if (t[i] == h) {
            k = i;
            break;
        }
    }

    // C-SCAN order: head → end → start → just before head
    p = 0;
    for (i = k; i < n + 3; i++) atr[p++] = t[i];
    for (i = 0; i < k; i++) atr[p++] = t[i];

    // Calculate total movement
    for (i = 0; i < p - 1; i++) {
        d[i] = abs(atr[i + 1] - atr[i]);
        sum += d[i];
    }

    avg = (float)sum / n;

    // Output
    printf("\nTracks traversed in C-SCAN order:\n");
    for (i = 0; i < p; i++) {
        printf("%d ", atr[i]);
    }
    printf("\nTotal head movements: %d", sum);
    printf("\nAverage head movement: %.2f\n", avg);

    return 0;
}
