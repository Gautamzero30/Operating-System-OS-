#include <stdio.h>
#include <stdlib.h>

int main() {
    int t[50], atr[50], h, n, i, j, temp, k, p, sum = 0;
    int d[50];
    float avg;
    int disk_size, direction;

    printf("Enter total number of tracks on disk: ");
    scanf("%d", &disk_size);

    printf("Enter the number of track requests: ");
    scanf("%d", &n);

    printf("Enter the position of the head: ");
    scanf("%d", &h);

    printf("Enter the tracks: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

    // Add head position
    t[n] = h;
    n++;

    // If moving left, add 0; if moving right, add disk_size-1
    if (direction == 0)
        t[n++] = 0;
    else
        t[n++] = disk_size - 1;

    // Sort the array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find head position
    for (i = 0; i < n; i++) {
        if (t[i] == h) {
            k = i;
            break;
        }
    }

    p = 0;
    if (direction == 0) {
        // Moving left
        for (j = k; j >= 0; j--)
            atr[p++] = t[j];
        for (j = k + 1; j < n; j++)
            atr[p++] = t[j];
    } else {
        // Moving right
        for (j = k; j < n; j++)
            atr[p++] = t[j];
        for (j = k - 1; j >= 0; j--)
            atr[p++] = t[j];
    }

    // Calculate differences
    for (i = 0; i < p - 1; i++) {
        d[i] = abs(atr[i + 1] - atr[i]);
        sum += d[i];
    }

    avg = (float)sum / (p - 1);

    printf("\nTracks traversed in SCAN order:\n");
    for (i = 0; i < p; i++)
        printf("%d ", atr[i]);

    printf("\nTotal head movements: %d", sum);
    printf("\nAverage head movements: %.2f\n", avg);

    return 0;
}
