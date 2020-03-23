#include <stdio.h>
#include <stdint.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define M 100

int count_cards(char c){
  switch (c){
    case 'S':
      return 20;

    case 'M':
      return 32;

    case 'T':
      return 40;

    case 'N':
      return 52;
  }

  return -1;
}

void sort (int array[], int n){
  for (int i = 0; i < n - 1; ++i){
    int min = i;

    for (int j = i +1; j < n; ++j){
      if (array[min] > array[j]){
        min = j;
      }
    }

    int tmp = array[min];
    array[min] = array[i];
    array[i] = tmp;
  }
}



int main() {

  int n;
  char c;
  int decks[M] = {0}, cards[M][M];

  scanf ("%d", &n);

  for (int i = 0; i < n; ++i){
    scanf (" %c", &c);

    decks[i] = count_cards(c);

    for (int j = 0; j < decks[i]; ++j){
      scanf("%d", &cards[i][j]);
    }
  }

  for (int i = 0; i < n; ++i){
    sort(cards[i], decks[i]);
  }

  for (int i = 0; i < n; ++i){
    for (int j = 0; j < decks[i]; ++j){
      printf("%d ", cards[i][j] );
    }

    printf("\n");
  }
  
  return 0;
}