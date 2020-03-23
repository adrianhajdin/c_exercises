#include <stdio.h>
#include <stdint.h>
 
void load_data(int polje[], int n){
    int input;

    for (int i = 0; i < n; i++) {
        scanf("%d", &input);

        polje[i] = input;
    }  
}

void counting_sort(int in[], int out[], int n) {
    for (int i = 0; i < n; i++) {
        int value = in[i];

        out[value]++;
    }
} 

int main() {
    int polje[10000];
    int n, k;

    scanf("%d", &n);
 
    load_data(polje, n);

    k = sizeof(polje) / sizeof(polje[0]);

    counting_sort(polje, n, k);
 
    for (int i = 0; i < n; i++){
        printf("%d ", polje[i]);
    }
 
    return 0;
}