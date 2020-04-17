#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char c;
	int pon;
	float uc;
} znak;

int charcomp (znak z1, znak z2) {
	if (z1.pon == z2.pon) {
		return z1.c > z2.c;
	}

	return z1.pon < z2.pon;
}

void sort(znak z[]) {
	for (int i = 0; i < 128; i++) {
		znak temp = z[i];
		int j = i;

		while (j > 0 && charcomp(z[j - 1], temp) > 0) {
			z[j] = z[j - 1];
			j--;
		}
		z[j] = temp;
	}
}

int main() {
	znak znakovi[256];
	int nz = 0, len = 0;

	FILE *fp;
	fp = fopen("input.dat", "r");

	for (int i = 0; i < 128; ++i) {
		znakovi[i].c = 0;
	}

	while(!feof(fp)) {
		char c;
		fscanf(fp, "%c", &c);
		if (isalnum(c) || ispunct(c)) {
			c = tolower(c);
			if (!znakovi[c].pon) {
				nz++;
			}
			znakovi[c].c = c;
			znakovi[c].pon++;
			len++;
		}
	}

	for (int i = 0; i < 256; ++i) {
		znakovi[i].uc = ((float)znakovi[i].pon / (float)len) * 100.0;
	}

	sort(znakovi);

	for (int i = 0; i < nz; ++i) {
		printf("%c %d %.1f%%\n", znakovi[i].c, znakovi[i].pon, znakovi[i].uc);
	}

	return 0;
}