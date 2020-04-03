#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main() {
  int n;
  char recenica[255];
  int ukupnoSlova = 0, velikihSlova = 0, malihSlova = 0, znamenki = 0, razmaka = 0, ostalihZnakova = 0;

  scanf("%d\n", &n);

  for (int i = 0; i < n; i++) {
    scanf("%[^\n]%*c", recenica);

    for (int j = 0; j < (strlen(recenica) - 1); j++) {
      if(isalpha(recenica[j])) ukupnoSlova++;   
      if(isupper(recenica[j])) velikihSlova++;   
      if(islower(recenica[j])) malihSlova++;   
      if(isdigit(recenica[j])) znamenki++;   
      if(isspace(recenica[j])) razmaka++;   
      if(ispunct(recenica[j])) ostalihZnakova++;   
    }
  }

  printf("%d %d %d\n", ukupnoSlova, velikihSlova, malihSlova);
  printf("%d %d %d\n", znamenki, razmaka, ostalihZnakova);

  return 0;
}