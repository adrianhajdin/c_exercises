#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main() {
    FILE *fp;
	fp = fopen("input.dat", "r");
    char _[256], ekstenzija[256];
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    while(!feof(fp)) {
        fscanf(fp, "%[^.]. %[^\n]\n", _, ekstenzija);

        if(!strcmp(ekstenzija, "mp3")) {
            c1++;
        } else if(!strcmp(ekstenzija, "mp4")) {
            c2++;
        } else if(!strcmp(ekstenzija, "txt")) {
            c3++;
        } else {
            c4++;
        }
    }
        
    printf("%d\n%d\n%d\n%d", c1, c2, c3, c4);

    fclose(fp);

    return 0;
}