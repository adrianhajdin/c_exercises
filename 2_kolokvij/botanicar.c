#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct {
  char plant[MAX][MAX+1];
  int size, flowers;
} plant;

void transform_level(plant *p, char a, char b, int level) {
  for (int j = 0; j < strlen(*(p->plant + level)); ++j) {
    if (*(*(p->plant + level) + j) == a) {
      *(*(p->plant + level) + j) = b;
    } else if (*(*(p->plant + level) + j) == b) {
      *(*(p->plant + level) + j) = a;
    }
  }
}

void transform(plant *p, char a, char b) {
  for (int i = 1; i < p->size; ++i) {
    transform_level(p, a, b, i);
  }
}

void transform_top(plant *p, char a, char b) {
  transform_level(p, a, b, 0);
}

void count_flowers_diff(plant *p) {
  p->flowers = 0;
  for (int i = 1; i < p->size; ++i) {
    for (int j = 0; j < strlen(*(p->plant + i)); ++j) {
      if (*(*(p->plant + i) + j) == '*') p->flowers++;
      if (*(*(p->plant + i) + j) == '-') p->flowers--;
    }
  }
}

int main() {
  plant p = {.size=0};
  int flowers, leaves, days;

  scanf("%d%d%d%*[\r\n]s", &flowers, &leaves, &days);

  do {
    fgets(*(p.plant + p.size), sizeof(p.plant[0]), stdin);
  } while (!strchr(*(p.plant + p.size++), '~'));

  count_flowers_diff(&p);

  if (days % (2*flowers) >= flowers) {
    transform(&p, '*', '-');
    if (p.flowers) {
      transform_top(&p, '*', '-');
    } else {
      transform_top(&p, '{', '}');
    }
  }
  if (days % (2*leaves) >= leaves) {
    transform(&p, '{', '}');
  }
  for (int i = 0; i < p.size; ++i) {
    printf("%s", p.plant[i]);
  }
  return 0;
}