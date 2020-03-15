#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t bin = 0;
	int n;

	scanf("%d ", &n);

	for (int i = 0; i < (n - 1); ++i) {
		if (bin == 0) {
			bin = 1;
		} else {
			bin = bin << 1;
		}
	}

	printf("%hhu", bin);

	return 0;
}