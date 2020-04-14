#include <stdio.h>
#include <string.h>
#include <ctype.h>

void strip(char in[]) {
	int n = strlen(in) - 1;
	for (int i = 0; i < n; ++i) {
		in[i] = tolower(in[i]);
		if (!isalpha(in[i])) {
			int j;
			for (j = i; j < n; ++j) {
				in[j] = in[j + 1];
			}
			n--;
			i--;
		}
	}
	in[n] = '\0';
}

void reverse(char in[], char out[]) {
	int j = 0;
	for (int i = strlen(in) - 1; i >= 0; i--) {
		out[j] = in[i];
		j++;
	}
}

int main() {
	char unos[256], rev[256];
	scanf("%[^\n]%*c", unos);
	strip(unos);
	reverse(unos, rev);

	if (strncmp(unos, rev, strlen(unos)))	{
		printf("NE");
	} else {
		printf("DA");
	}	

	return 0;
}
