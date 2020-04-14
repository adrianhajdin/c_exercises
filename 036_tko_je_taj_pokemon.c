#include <stdio.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define SIZE 100

int compare(char s1[], char s2[]) {
  if (strlen(s1) != strlen(s2)) {
    return 0;
  }
  
  for (int i = 0; i < strlen(s1); i++) {
    if(s1[i] != '*' && s1[i] != s2[i]) {
        return 0;
    }
  }
  
  return 1;    
}

int main() {
  char n1[SIZE][SIZE], n2[SIZE][SIZE];
  int n, m;
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf(" %s", n1[i]);
  }
  
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf(" %s", n2[i]);
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (compare(n1[i], n2[j])) {
        printf("%s\n", n2[j]);
      }
    } 
  }
  
  return 0;
}