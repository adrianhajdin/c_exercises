#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void swap(int *x, int *y) {
    int tmp = *x;

    *x = *y;
    *y = tmp;
}

int main() {
    int glasses[3], n;

    for (int i = 0; i < 3; i++) {
        scanf("%d", glasses + i);
    }
    
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        int x, y;

        scanf("%d %d", &x, &y);

        swap(glasses + x - 1, glasses + y - 1);
    }

     for (int i = 0; i < 3; ++i) {
        if (*(glasses+i)) printf("%d", i+1); //ako bi pisali (glass+1) provjerava da li postoji pointer i vraća 123
    }

    return 0;
}