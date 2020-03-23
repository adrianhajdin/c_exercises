#include <stdio.h>
#include <stdint.h>

void selection_sort (int a1[], int a2[], int size){

  for (int i = 0; i < size - 1; ++i){
    int max = i;

    for (int j = i + 1; j < size; ++j){
      if (a1[max] < a1[j]){
        max = j;
      }
    }

    int tmp = a1[max];
    a1[max] = a1[i];
    a1[i] = tmp;

    tmp = a2[max];
    a2[max] = a2[i];
    a2[i] = tmp;
  }
}
 
int main(){
  int n, k, tmp, kolicina[1000] = {0}, popularnost[1000] = {0};

  scanf ("%d\n", &n);

  for (int i = 0; i < n; ++i){
    scanf ("%d ", &tmp);
    kolicina[tmp - 1]++;
  }

  for(int i = 0; i < n; i++){
    popularnost[i] = i + 1;
  }

  scanf("%d", &k);

  selection_sort(kolicina, popularnost, n);

  for (int i = 0; i < k; ++i){
    printf("%d\n", popularnost[i]);
  }

  return 0;
}