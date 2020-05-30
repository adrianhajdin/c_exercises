#include <stdio.h>
#include <string.h>
#include <ctype.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int *naj(int *a, int *b, int *c) {
    if(*a > *b && *a > *c) {
        return a;
    } else if(*b > *a && *b > *c) {
        return b;
    }

    return c;
}

int main() {
    int A, B, C;
    int *pNaj = NULL;

    scanf("%d %d %d", &A, &B, &C);

    pNaj = naj(&A, &B, &C);

    printf("%d\n", *pNaj);
    printf("%d\n", (A + B + C - *pNaj));

    return 0;
}