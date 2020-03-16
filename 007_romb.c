#include <stdio.h>
#include <stdint.h>

void print_binary(uint32_t b, int n) {
    uint32_t p = (1 << (n - 1));

    while(p != 0) {
        printf("%d", b & p ? 1 : 0);

        p >>= 1;
    }

    printf("\n");
}

uint32_t create_bitmask(int n) {
    uint32_t mask = 0;

    for (int i = 0; i < n; i++) {
        mask = mask << 1;
        mask = mask | 1;
    }
    
    return mask;
}

uint32_t reverse_binary(uint32_t input, int n) {
    uint32_t output = 0;

    for (int i = 0; i < n; i++) {
        output = output << 1;
        output = output | (input & 1);
        input = input >> 1;
    }
    
    return output;
}

int main(){
	uint32_t bin = 0;
	int n, k, op = 1;

	scanf ("%d %d", &n, &k);

	uint32_t mask = create_bitmask(n);
	uint32_t half_mask = create_bitmask((n >> 1));

	for (int i = 1; i < k; ++i){
		if (op == 1){
			bin >>= 1;
			bin |= 1 << ((n >> 1) - 1);
		} else {
			bin <<= 1;
		}

		bin &= half_mask;
		bin |= reverse_binary(bin, n);

		if (bin == mask){
			op = 0;
		} else if (bin == 0){
			op = 1;
		}
	}

	print_binary(bin, n);

  return 0;
}