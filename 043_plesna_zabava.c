#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(VA_ARGS)
#endif

typedef struct {
  char ime[32];
  int bp;
} plesacica;


void fix(char word[]) {
  int i, n = 0;

  word[0] = toupper(word[0]);
  for (i = 1; i < strlen(word); i++) {
    if (!isalpha(word[i])) {
      n++;
    } else {
      word[i - n] = tolower(word[i]);
    }
  }
  word[i - n] = '\0';
}

void count(plesacica p[], int n, char ime[32]){
  for (int i = 0; i < n; ++i){
    if (!strcmp(p[i].ime, ime)){
      p[i].bp++;
    }
  }
}

int compare(plesacica p1, plesacica p2){
  if (p1.bp > p2.bp){
    return 0;
  } else if (p1.bp < p2.bp){
    return 1;
  } else if (p1.bp == p2.bp){
    return strcmp(p1.ime, p2.ime);
  }
  return -1;
}

void sort (plesacica array[], int n){
  for (int i = 1; i < n; i++) {
    plesacica tmp = array[i];
    int j = i;

    while (j > 0 && compare(array[j - 1], tmp) > 0) {
        array[j] = array[j - 1];
        j--;
    }

    array[j] = tmp;
  }
}


int main() {
    plesacica p[12];
    int n;
    char ime[32];

    FILE *fp_in, *fp_out;
    fp_in = fopen("input.dat", "r");
    fp_out = fopen("output.dat", "w");

    scanf("%d\n", &n);

    for (int i = 0; i < n; ++i){
        scanf("%s\n", p[i].ime);
        fix(p[i].ime);
        p[i].bp = 0;
    }

    while (!feof(fp_in)){
        fscanf(fp_in, "%s", ime);
        
        fix(ime);
        count(p, n, ime);
    }

    sort(p, n);

    for (int i = 0; i < n; ++i){
        printf("%s %d\n", p[i].ime, p[i].bp);
        fprintf(fp_out, "%s %d\n", p[i].ime, p[i].bp);
    }

    fclose(fp_in);
    fclose(fp_out);

     return 0;
}