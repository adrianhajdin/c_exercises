#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char string[100];
    int n, count = 0;

    scanf("%d\n", &n);
    scanf("%[^\n]", string);

    for (int i = 0; i < n; i++){
        if(string[i] == string[i + 1]) {
          count++;
        }
    }
    
    printf("%d", count);
    
    return 0;
}