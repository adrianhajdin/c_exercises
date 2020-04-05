#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line[100];
    int length, mario = 0, princeza = 0;

    scanf("%[^\n]", line);

    length = strlen(line);

    for (int i = 0; i < length; i++) {
        if (line[i] == 'M') {
            mario = i + 1;
        } else if (line[i] == 'P'){
            princeza = i + 1;
        }
    }

    if (mario > princeza){
        printf("Mario\n");
        printf("%d", length - mario);
    } else {
        printf("Princeza\n");
        printf("%d", length - princeza);
    }

    return 0;
}