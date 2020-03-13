#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define A 2476367552
#define C 2326331526
#define M 4294967295
#define G 10

typedef unsigned long long big;
big lcg(big v, big a, big c, big m) {
    return (a*v + c) % m;
}

void main() {
    srand(time(NULL));

    big current = rand();
    big guess;
    unsigned opt;
    unsigned count = 0;

    printf("Welcome to the most secure PRNG.\n");
    while (1) {
        printf(
            "Guessed %d/%d\n(1) Guess 10 numbers\n(2) Give me the next\n",
            count, G
        );
        scanf("%d", &opt);

        if (opt == 1) {
            printf("Enter your guess:\n");
            scanf("%llu", &guess);

            if (guess != current) {
                printf("Goodbye.\n");
                exit(0);
            } else {
                count++;
                if (count == G){
                    printf("ALEXCTF{f0cfad89693ec6787a75fa4e53d8bdb5}\n");
                    exit(0);
                }
            }
        } else {
            printf("%llu\n", current);
        }

        current = lcg(current, A, C, M);
    }
}
