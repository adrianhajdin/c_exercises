#include <stdio.h>
#include <stdint.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void print_binary(uint32_t b, int n) {
	uint32_t p = (1 << (n - 1));

	while(p != 0) {
		printf("%d",b & p ? 1 : 0);
		p >>= 1;
	}
	printf("\n");
}

uint32_t create_bitmask(int n) {
	uint32_t mask = 0;

	for (int i = 0; i < n; i++) {
		mask <<= 1;
		mask |= 1;
	}

	return mask;
}

uint32_t reverse_binary(uint32_t input, int n) {
    uint32_t output = 0;
    
    for (int i = 0; i < n; i++) {
        output <<= 1;
        output |= input & 0x01;
        input >>= 1;
    }

    return output;
}

int main() {
    uint32_t bin = 0;
    int n;

    scanf("%d", &n);

    uint32_t mask = create_bitmask(n);

    print_binary(bin, n);
    
    bin = bin | 1;

    print_binary(bin, n);

    for (int i = 0; i < n; i++) {   
        if(i == 0) {
            bin = bin << 1;
            bin = bin | 1;
        } 

        bin = bin << 1;
        
        print_binary(bin, n);
    }
    
    
    // 00000000
    // 00000001
    // 00000011
    // 00000110
    // 00001100
    // 00011000
    // 00110000
    // 01100000
    // 11000000
    // 10000000
    return 0;
}