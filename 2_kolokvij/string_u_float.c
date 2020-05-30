#include <stdio.h>
#include <ctype.h>
#include <math.h>


#ifndef DEBUG
#define DEBUG(...)printf(_VA_ARGS_)
#endif

float stringtofloat(char *str) {
    float k = 1, p = -1, answer = 0;

    while(*str) {
        if(*str == '-') {
            k = -1;
        } else if(*str == '.') {
            p = 0;
        } else if(isdigit(*str)) {
            answer = (answer * 10) + (*str - '0');

            if(p >= 0) {
                p++;
            }
        }

        str++;
    }

    return ((k * answer) / (p >= 0 ? pow(10, p) : 1));
}

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char str[100];

        scanf("%s", str);
        
        printf("%.3f\n", stringtofloat(str));
    }

    return 0;
}