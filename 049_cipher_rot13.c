#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cipher(char c) {
	if ((c <= 'M' && c >= 'A' )|| (c <= 'm' && c >= 'a')) {
		c += 13;
	} else {
		c -= 13;
	}
	return c;
}

int main() {
    char line[528];

    FILE *fin, *fout; 
	fin = fopen("input.dat", "r");
	fout = fopen("decrypted.txt", "w+");

    while (!feof(fin)) {
        fscanf(fin, "%[^\n]\n", line);

        for (int i = 0; i < strlen(line); ++i) {
			if (isalpha(line[i]))	{
				line[i] = cipher(line[i]);
			}

			fprintf(fout, "%c", line[i]);
			printf("%c", line[i]);
		}
        
		fprintf(fout, "\n");
		printf("\n");
    }

    printf("\n");
    
    return 0;
}