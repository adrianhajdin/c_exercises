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
  int n, k;

  scanf("%d %d", &n, &k);

  uint32_t half_mask = create_bitmask(n / 2);

  for (int i = 0; i < k - 1; ++i){
    if (bin == 0){
      bin |= 1;
      bin &= half_mask;
    } else {
      bin <<= 1;
      bin &= half_mask;
    }
  }
  
  print_binary(bin, n / 2);
  print_binary(reverse_binary(bin, n / 2), n / 2);
  printf("\n");
    
  return 0;
}