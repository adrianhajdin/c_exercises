#include <stdio.h>
#include <stdint.h>
 
int load_data(int polje[]){
    int x = 0;
    int input;
 
    scanf("%d", &input);

    while(input != 0) {
        polje[x++] = input;

        scanf("%d", &input);
    }
 
    return x;
}
 
void bubble_sort(int array[], int size){
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (array[j - 1] < array[j]) {
                int tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
        }
    }
}
 
int main() {
    int polje[10000];
    int n;
 
    n = load_data(polje);

    bubble_sort(polje, n);
 
    for (int i = 0; i < n; i++){
        printf("%d ", polje[i]);
    }
 
    return 0;
}