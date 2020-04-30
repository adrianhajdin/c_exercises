#include <stdio.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
	char z;
	char v;
} kartica;

void okreni(kartica *c1, kartica *c2, int *bod, int *red) {
	if (tolower(c1 -> z) == tolower(c2 -> z)) {
		c1 -> v = c2 -> v = 1; // *(c1).v
		bod[*red]++;
        
		return;
	}

	*red = !*red;
}

int main() {
	int m, n, k;
	int wins[2] = {}, turn = 0;
	int x0, x1, y0, y1;
	kartica cards[52][52];

	scanf("%d %d ", &m, &n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%c ", &cards[i][j].z);
			cards[i][j].v = 0;
		}
	}

	scanf("%d ", &k);

	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d ", &x0, &y0, &x1, &y1);
		okreni(&cards[x0][y0], &cards[x1][y1], wins, &turn);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (cards[i][j].v) {
				putchar(cards[i][j].z);
			} else {
				putchar('*');
			}
		}
		putchar('\n');
	}

	printf("%d:%d", wins[0], wins[1]);

	return 0;
}
