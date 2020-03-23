#include <stdio.h>
#include <stdint.h>

#define SIZE 10

void bubble_sort (int a1[SIZE], int a2[SIZE]){
  for (int i = 0; i < SIZE; ++i){
    for (int j = 1; j < SIZE; ++j){
      if (a1[j - 1] < a1[j]){
        int tmp = a1[j - 1];
        a1[j - 1] = a1[j];
        a1[j] = tmp;

        tmp = a2[j - 1];
        a2[j - 1] = a2[j];
        a2[j] = tmp;
      }
    }
  }
}


int main(){
  int promet[SIZE] = {0}, kol[SIZE] = {0}, n;

  scanf("%d ", &n);

  while(n > 0) {
    kol[n - 1]++;
    scanf("%d ", &n);
  }

  for (int i = 0; i < SIZE; ++i){
    promet[i] = i +1;
  }

  bubble_sort(kol, promet);

  for (int i = 0; i < SIZE; ++i){
    if (kol[i] != 0){
      printf("%d\t", promet[i]);
    } 
  }

  printf("\n");

  for (int i = 0; i < SIZE; ++i){
    if (kol[i] != 0){
      printf("%d\t", kol[i]);
    } 
  }
  
  return 0;
}