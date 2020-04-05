#include <stdio.h>
#include <math.h>

int main() {
    char line[100], line2[100];
    int mario = 0, princeza = 0;

    scanf("%[^\n]", line);

    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == 'M') {
            mario = i + 1;
        } else if (line[i] == 'P'){
            princeza = i + 1;
        }
    }

    if (mario > princeza){
        printf("Mario\n");
        printf("%d", strlen(line) - mario);
    } else {
        printf("Princeza\n");
        printf("%d", strlen(line) - princeza);
    }

    return 0;
}