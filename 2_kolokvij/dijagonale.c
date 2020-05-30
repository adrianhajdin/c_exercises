#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void ucrtaj_dijagonalu(char a[][20], char *p, char c, int dir) {
    int r = ((p - a[0]) / 20);
    int s = ((p - a[0]) % 20);

    while(r > 0 && (dir == 1 || s > 0) && (dir == -1 || s < 20 - 1)) {
        r--;
        s += dir;
    }

    while(r < 10 && s >= 0 && s < 20){
        a[r][s] = c;
        r++;
        s -= dir;
    }
}

int main() {
  int n;
  char a[10][20];
  memset(a, '.', sizeof(a));

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int r, s, d;
    char c;

    scanf("%d%d %c%d", &r, &s, &c, &d);
    ucrtaj_dijagonalu(a, &a[r][s], c, d);
  }

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 20; ++j) {
      printf("%c", a[i][j]);
    }

    printf("\n");
  }

  printf("\n");
  return 0;
}
