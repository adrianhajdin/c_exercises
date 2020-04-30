#include <stdio.h>
#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAXR 10
#define MAXS 20

char *pronadji_adresu(char (*mat)[MAXS], int s){
  for(; ; mat++){
    for(int i = 0; i < s; i++){
      if(*(*mat+i) == 'B'){
        return *mat+i;
      }
    }
  }

  return 0;
}

void ispisi_indeks(char (*mat)[MAXS], char *p){
  int maxs = sizeof(*mat) / sizeof(char);

  printf("%ld %ld\n", (p-*mat) / maxs, (p-*mat) % maxs);
}

int main() {
    int R, S;
    char a[MAXR][MAXS];

    scanf("%d%d", &R, &S);

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < S; ++j) {
            scanf(" %c", *(a+i)+j);
        }
    }

    ispisi_indeks(a, pronadji_adresu(a, S));

    return 0;
}