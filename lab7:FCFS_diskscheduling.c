#include <stdio.h>
#include <stdlib.h>

int main() {
    int t[100], n, i, tohm[100], tot = 0;
    float avhm;

    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("At least 2 tracks are required.\n");
        return 1;
    }

    printf("Enter the tracks to be traversed: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    // Calculate differences between tracks
    for (i = 0; i < n - 1; i++) {
        tohm[i] = abs(t[i + 1] - t[i]);
        tot += tohm[i];
    }

    avhm = (float)tot / (n - 1);

    printf("\nTracks Traversed\tDifference Between Tracks\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d -> %d\t\t%d\n", t[i], t[i + 1], tohm[i]);
    }

    printf("\nTotal Head Movements: %d", tot);
    printf("\nAverage Head Movements: %.2f\n", avhm);

    return 0;
}
