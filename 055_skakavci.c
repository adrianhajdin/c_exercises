#include <stdio.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int *idx(int x, int n, int *niz) {
	for (int i = 0; i < n; i++) {
		if (niz[i] == x) {
			return &niz[i];
		}
	}
	return NULL;
}

void move(int *start, int len) {
	int c = *start;

	for (int i = 0; i < len; i++)
	{
		*(start - i) = *(start - i - 1);
	}

	*(start - len) = c;
}

int main() {
	int niz[100], n, k, x, b;

	scanf("%d ", &n);

	for (int i = 0; i < n; i++) {
		niz[i] = i + 1;
	}

	scanf("%d ", &k);

	for (int i = 0; i < k; i++) {
		scanf("%d %d", &x, &b);
		move(idx(x, n, niz), b);

	}

	for (int i = 0; i < n; i++) {
		printf("%d ", niz[i]);
	}

	return 0;
}