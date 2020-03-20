#include <stdio.h>
#include <stdint.h>
 
int load_data(int polje[]){
    int x = 0;
    int input;
 
    scanf("%d", &input);

    while(input != 0) {
        polje[x++] = input;

        scanf("%d`", &input);
    }
 
    return x;
}

void selection_sort(int array[], int n) {
    for (int i = 0; i < (n - 1); i++) {
        int min = i;

        for (int j = (i + 1); j < n; j++) {
            if(array[min] > array[j]) {
                min = j;
            }
        }

        int tmp = array[min];
        array[min] = array[i];
        array[i] = tmp;
    }
}
 
int main() {
    int polje[10000];
    int n;
 
    n = load_data(polje);

    selection_sort(polje, n);
 
    for (int i = 0; i < n; i++){
        printf("%d ", polje[i]);
    }
 
    return 0;
}