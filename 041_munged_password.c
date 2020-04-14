#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char x;
    char y;
}zamjena;

void change(char password[], zamjena zamjena[], int a){
    for(int i = 0; i < strlen(password); i++){
        for(int j = 0; j < a; j++){
            if(password[i] == zamjena[j].x){
                password[i] = zamjena[j].y;
            }
        }
    }
}


int main() {
    char lozinka[128];
    zamjena p[128];
    int x;

    FILE *fp;
    fp = fopen("input.dat", "r");

    scanf("%s", lozinka);
    
    fscanf(fp, "%d ", &x);

    for (int i = 0; i < x; i++){
        fscanf(fp, "%c %c ", &p[i].x, &p[i].y);
    }

    change(lozinka, p, x);

    printf("%s\n", lozinka);

    fclose(fp);
}