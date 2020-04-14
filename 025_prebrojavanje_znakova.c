#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

typedef struct {
  char ime[127];
  char prezime[127];
  float prosjekOcjena;
} student;

int main() {
  int n, m, sum, ocjena;
  student studenti[10];

  scanf("%d\n", &n);

  for (int i = 0; i < n; i++) {
    ocjena = 0;
    sum = 0;

    scanf("%s %s %d", studenti[i].ime, studenti[i].prezime, &m);

    for (int j = 0; j < m; j++) {
      scanf("%d", &ocjena);

      sum += ocjena;
    }

    studenti[i].prosjekOcjena = sum / m;
  }

  for (int i = 0; i < n; i++) {
    printf("%s ", studenti[i].ime);
    printf("%s ", studenti[i].prezime);
    printf("%f", studenti[i].prosjekOcjena);
  }

  return 0;
}