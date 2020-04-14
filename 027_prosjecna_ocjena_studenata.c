#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define SIZE 128

typedef struct {
	char ime[SIZE];
	char prezime[SIZE];
	float ocjena;
	int error;
} student;

int ispravi(char s[], int cut) {
	int i, posmak = 0;

	for (i = 0; i < strlen(s); ++i) {
		s[i - posmak] = tolower(s[i]);

		if (!isalpha(s[i])) {
			posmak++;
		}
	}

	s[0] = toupper(s[0]);
	s[i - posmak] = '\0';
	s[cut] = '\0';

	return posmak;
}

int compare(student s1, student s2) {
	if (!strcmp(s1.prezime, s2.prezime)) {
		return strcmp(s1.ime, s2.ime);
	} else {
		return strcmp(s1.prezime, s2.prezime);
	}
}

void sort(student s[], int size) {
	for (int i = 0; i < size; ++i) {
		student tmp = s[i];
		int j = i;

		while (j > 0 && compare(s[j - 1], tmp) > 0) {
			s[j] = s[j - 1];
			j--;
		}
		s[j] = tmp;
	}
}

void ispis(student s) {
	printf("%s, %s: %.3f. ", s.prezime, s.ime, s.ocjena);
	if (s.error) {
		printf("GRESKA!\n");
	} else {
		printf("\n");
	}
}

student unos() {
	char line[4 * SIZE];
	int n, offset, tmp, ocjena;
	student s;
	s.ocjena = 0;
	s.error = 0;

	fgets(line, 4 * SIZE, stdin);

	sscanf(line, "%s %s %d%n", s.ime, s.prezime, &n, &offset);

	for (int i = 0; i < n; ++i)
	{
		sscanf(line + offset, "%d%n", &ocjena, &tmp);
		offset += tmp;

		s.ocjena += ocjena;
	}	

	s.ocjena /= (float)n;

	s.error += ispravi(s.prezime, strlen(s.prezime));
	s.error += ispravi(s.ime, strlen(s.prezime));

	return s;
}

int main() {
	student st[10];
	int n;

	scanf("%d ", &n);

	for (int i = 0; i < n; ++i) {
		st[i] = unos();
	}

	sort(st, n);

	for (int i = 0; i < n; ++i) {
		ispis(st[i]);
	}
}