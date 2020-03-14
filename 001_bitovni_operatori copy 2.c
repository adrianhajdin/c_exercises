#include <stdio.h>
#include <stdint.h>

void print_binary(uint32_t b, int n) {
    uint32_t p = (1 << (n - 1));

    while(p != 0) {
        printf("%d", b & p ? 1 : 0);

        p >>= 1;
    }

    printf("\n");
}

int main() {
    uint16_t k;
    int n;

    scanf("%hu %d", &k, &n);

    print_binary(k, n);

    return 0;
}