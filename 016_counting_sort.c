#include <stdio.h>

void load_data(int input[], int n) {
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &input[i]);
	}
}

void counting_sort(int array[], int red[], int n){
	for (int i = 0; i < n; ++i) {
		red[array[i]]++;
	}
}

int main() {
	int polje[10000], brojevi[100] = { 0 }, n;

	scanf("%d ", &n);

	load_data(polje, n);

	counting_sort(polje, brojevi, n);

	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < brojevi[i]; ++j) {
			printf("%d ", i);
		}
	}

	return 0;
}
