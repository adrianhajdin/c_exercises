#include <stdio.h>
#include <stdint.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define SIZE 100

int main() {
  int n, a[SIZE];

  scanf ("%d", &n);

  for (int i = 0; i < n; ++i){
    scanf ("%d", &a[i]);
    
    int j;

    for (j = i; j > 0; j--){
      if (a[j] > a[j-1]){
        int tmp = a[j];
        a[j] = a[j-1];
        a[j-1] = tmp;
      } else {
          break;
      }
    }

    printf("%d\n", j+1);

    for (j = 0; j <= i; ++j){
      printf("%d ", a[j]);
    }

  }

  return 0;
}
