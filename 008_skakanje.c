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

int main() {
    uint32_t bin = 0;
    int n;

	scanf("%d", &n);

	uint32_t half_mask = create_bitmask(n / 2); // dijeljenje s dva, za polu masku, 00001111
	
	do {
		print_binary(bin, n);

		bin = reverse_binary(bin, n);

		if(bin == 0) {
			bin = 1;
		} else if((bin & half_mask) != 0) {
			bin <<= 1;
			bin &= half_mask;
		}
	} while(bin != 0); 	

    return 0;
}