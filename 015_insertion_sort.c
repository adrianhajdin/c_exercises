#include <stdio.h>
#include <stdint.h>
 
void load_data(int polje[], int n){
    int input;

    for (int i = 0; i < n; i++) {
        scanf("%d", &input);

        polje[i] = input;
    }  
}

void insertion_sort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int element = array[i];
        int j = i;

        while(j > 0 && array[j - 1] > element) {
            array[j] = array[j - 1];
            j--;
        }

        array[j] = element;
    }
}

int main() {
    int polje[10000];
    int n;

    scanf("%d", &n);
 
    load_data(polje, n);

    insertion_sort(polje, n);
 
    for (int i = 0; i < n; i++){
        printf("%d ", polje[i]);
    }
 
    return 0;
}