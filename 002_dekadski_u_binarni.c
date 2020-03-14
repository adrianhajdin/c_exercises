#include <stdio.h>
#include <stdint.h>

int main() {
    char c;
    uint16_t a, b;

    scanf("%c", &c);
    scanf("%hi %hi", &a, &b);

    switch (c) {
    case '&':
        printf("%hhu", a & b);
        break;
    case '|':
        printf("%hhu", a | b);
        break;
    case '^':
        printf("%hhu", a ^ b);
        break;
    case '<':
        printf("%hhu", a << b);
        break;
    case '>':
        printf("%hhu", a >> b);
        break;
    default:
        break;
    }

    return 0;
}