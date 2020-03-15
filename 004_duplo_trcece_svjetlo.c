#include <stdio.h>
#include <stdint.h>

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
	
	print_binary(bin, n);

	for (int i = 0; i < 2; i++) {
		bin = bin << 1;
		bin = bin | 1;
	}

    print_binary(bin, n);

	for (int i = 0; i < (n / 2) - 1; i++) {
		bin = bin << 2;

		print_binary(bin, n);
	}

	return 0;
}


//   for (int i = 0; i < 2; ++i){
//     bin <<= 1;
//     bin |= 1;
//   }

//   print_binary (bin, n);

//   for (int i = 0; i < n / 2 - 1; ++i){
//     bin <<= 2;
//     print_binary (bin, n);
//   }

//   return 0;
// }

