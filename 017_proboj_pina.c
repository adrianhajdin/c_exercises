#include <stdio.h>

void insertion_sort(int array[], int n) {
  for (int i = 1; i < n; i++){
    int element = array[i];
    int j = i;

    while(j > 0 && array[j - 1] > element) {
      array[j] = array[j - 1];
      j--;
    } 

    array[j] = element;
  }
}

int main(){
  int n, num = 0;
  int array[500];

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  insertion_sort(array, n);

  for (int i = 0; i < n / 2; i++) {
    if(num < 3) {
      printf("%d ", array[(n / 2) + i - 1]);
    }
    
    num++;
  }
  
  return 0;
}