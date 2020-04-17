#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int tonum(char in[]) {
	int out;

	if (!strcmp(in, "nula")) {
		out = 0;
	} else if (!strcmp(in, "jedan")) {
		out = 1;
	} else if (!strcmp(in, "dva")) {
		out = 2;
	} else if (!strcmp(in, "tri")) {
		out = 3;
	} else if (!strcmp(in, "cetiri")) {
		out = 4;
	} else if (!strcmp(in, "pet")) {
		out = 5;
	} else if (!strcmp(in, "sest")) {
		out = 6;
	} else if (!strcmp(in, "sedam")) {
		out = 7;
	} else if (!strcmp(in, "osam")) {
		out = 8;
	} else if (!strcmp(in, "devet")) {
		out = 9;
	} else {
		out = -1;
	}

	return out;
}

int main() {
	char rijec[8];
	int broj, j = 0;

	FILE *fp;
	fp = fopen("input.dat", "r");

	while(!feof(fp)) {
		char c;

		fscanf(fp, "%c", &c);

		if (c == '-') {
			broj = tonum(rijec);

			if (broj >= 0) {
				printf("%d", broj);
			}

			int n = strlen(rijec);

			for (int k = 0; k < n; ++k) {
				rijec[k] = '\0';
			}

			j = 0;
		} else if (isalpha(c)) {
			rijec[j] = tolower(c);

			j++;
		}
	}

	fclose(fp);

	return 0;
}