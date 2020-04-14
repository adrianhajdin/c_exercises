#include <stdio.h>
#include <ctype.h>
#include <string.h> 

typedef struct {
    char ime[100];
    int cijena;
} proizvod;
 
int main() {
    int n;
    proizvod proizvodi[100];
    int cijena;
    char kriterij, red;
 
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", proizvodi[i].ime, &proizvodi[i].cijena);
    }

    scanf("%c %c", &kriterij, &red);
 
    for (int i = 0; i < n; i++) {
        /* code */
    }
    
    // printf("%s\t\t%5d\n" ... )

    return 0;
}