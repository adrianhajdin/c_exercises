#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAXR 10
#define MAXS 20

char *pronadji(char (*a)[MAXS], char c, int s){

  int j;

  for(;;++a){
    for(j = 0; j < s; j++){
      if(*(*a+j) == c){
        return *a+j;
      }
    }
  }
  return NULL;
}


char min(char a, char b){
  return a > b ? b : a;
}

char max(char a, char b){
  return a > b ? a : b;
}


void ispisi_podmatricu(char (*a)[MAXS], char *A, char *B){

  int s = sizeof(a[0]) / sizeof(char);
  int iA = min((A-*a) / s, (B-*a) / s);
  int iB = max((A-*a) / s, (B-*a) / s);
  int jA = min((A-*a) % s, (B-*a) % s);
  int jB = max((A-*a) % s, (B-*a) % s);
  int i, j;

  for(i = iA; i <= iB; i++){
    for(j = jA; j <= jB; j++){
      printf("%c", *(*(a+i)+j));
    }
    printf("\n");
  }

}



int main() {
  char a[MAXR][MAXS];
  int R, S;
  scanf("%d%d%*[\r\n]s", &R, &S);
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < S; ++j) {
      scanf("%c ", &a[i][j]);
    }
  }
  ispisi_podmatricu(a, pronadji(a, 'A', S), pronadji(a, 'B', S));
  return 0;
}