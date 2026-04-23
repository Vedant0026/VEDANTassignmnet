#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, n;

    printf("How many random numbers do you want? ");
    scanf("%d", &n);

    // Seed the random number generator
    srand(time(0));

    printf("Random numbers:\n");

    for(i = 0; i < n; i++) {
        printf("%d ", rand());   // generates random number
    }

    printf("\n");
    return 0;
}