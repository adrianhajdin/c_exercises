#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...)printf(__VA_ARGS__)
#endif

int main() {
    int n, maxR = 1, maxS = 1;
    char **matrica; // pointer na pointer zvan matrica

    matrica = malloc(sizeof(char *) * maxR); // alociranje redova matrice 
    matrica[0] = malloc(sizeof(char) * maxS); // alocirajne stupaca matrice
    memset(matrica[0], ' ', maxS * sizeof(char)); // postavljanje vrijednosti elemenata matrice

    scanf("%d", &n);

    for (int x = 0; x < n; x++) {
        int r, s;
        char c;
        scanf("%d %d %c", &r, &s, &c);

        r++; // zbog nul terminatora
        s++; // zbog nul terminatora

        if(r > maxR){
            matrica = realloc(matrica, r * sizeof(char *));
            for(int i = maxR; i < r; i++){
                matrica[i] = malloc(maxS * sizeof(char));
                memset(matrica[i], ' ', maxS * sizeof(char));
            }
            maxR = r;
        }

        if(s > maxS){
            for(int i = 0; i < maxR; i++){
                matrica[i] = realloc(matrica[i], s * sizeof(char));
                memset(matrica[i] + maxS, ' ', (s - maxS) * sizeof(char));
            }
            maxS = s;
        }

        matrica[--r][--s] = c;
    }
    
    for (int i = 0; i < maxR; ++i) {
        for (int j = 0; j < maxS; ++j) {
            printf("%c", matrica[i][j]);
        }
        
        printf("\n");
    }
  
    return 0;
}