#include <stdio.h>
#include <string.h>
#include <ctype.h>


void check_colors(char (*)[3][3]);
  
const char BOJE[6][20] = {"Bijela", "Crvena", "Narancasta", "Plava", "Zelena", "Zuta"};
int main() {
  char cube[6][3][3];

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        scanf(" %c", &cube[i][j][k]);
      }
    }
  }

  check_colors(cube);

  return 0;
}

void check_colors(char (*pC)[3][3]) {
  int slozena = 1;

  for (int i = 0; i < 6; i++) {
    int slozena_strana = 1;

    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (*(*(*(pC+i)+j)+k) != *(*(*(pC+i)+1)+1)) {
          slozena_strana = 0;
          slozena = 0;
        }
      }
    }

    if(!slozena_strana){
      printf("%s\n", BOJE[i]);
    }
  }

  if(slozena){
    printf("Kocka je slozena\n");
  }
}