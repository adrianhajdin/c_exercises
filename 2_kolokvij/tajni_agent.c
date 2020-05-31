#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void decypher(char *S, int *B) {
    int tmp = 0;

    while(*S) {
        if(isdigit(*S)) {
            tmp = tmp * 10 + (*S - '0');
        } else if(isalpha(*S)) {
            *B += tmp;
            tmp = 0;
        }

        S++;
    } 

    *B += tmp;
}

int main() {
  char S[100];
  int B = 0, *pB = &B;

  scanf("%s", S);

  decypher(S, pB);

  printf("%d", B);

  return 0;
}