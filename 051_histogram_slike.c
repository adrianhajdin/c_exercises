#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char fs[3];
    int w, h, d, c;
    int hist[256] = {0};

    FILE *fp; 
    fp = fopen("input.dat", "r");

    fscanf(fp, "%[^\n]\n", fs);
      
    if (strcmp(fs, "P2")) {
        printf("NE");

        fclose(fp);

        return 0;
    }

    fscanf(fp, "%d %d", &w, &h);
    fscanf(fp, "%d", &d);

    for (int i = 0; i < w * h; i++) {
        fscanf(fp, "%d", &c);
    
        hist[c]++;
    }
    
    for (int i = 0; i <= d; i++) {
        printf("%d ", hist[i]);
    }
  
    fclose(fp);

    return 0;
}
