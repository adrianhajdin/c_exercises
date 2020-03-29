#include <stdio.h>

typedef struct {
  int i;
  int j;
  int k;
} vektor;

int main() {
  vektor x, y, z;
  int det;

  scanf("%d %d %d\n", &x.i, &x.j, &x.k);
  scanf("%d %d %d\n", &y.i, &y.j, &y.k);
  scanf("%d %d %d\n", &z.i, &z.j, &z.k);
  
  det = (x.i * y.j * z.k) + (x.k * y.i * z.j) + (x.j * y.k * z.i) - (x.k * y.j * z.i) - (x.i * y.k * z.j) - (x.j * y.i * z.k);
  
  if(det == 0) {
    printf("DA");
  } else {
    printf("NE");
  }

  return 0;
}