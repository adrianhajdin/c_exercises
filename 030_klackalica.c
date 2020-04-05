#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char firstString[100], secondString[100];
    int firstCount = 0, secondCount = 0;

    scanf("%[^B]", firstString);
    scanf("%[^\n]", secondString);

    for (int i = 0; i < strlen(firstString); i++) {
        if(firstString[i] == 'S') {
            firstCount++;
        } 
    }

    for (int i = 0; i < strlen(secondString); i++) {
        if(secondString[i] == 'S') {
            secondCount++;
        } 
    }
    
    if(firstCount > secondCount) {
        printf("Lijevo");
    } else if(firstCount < secondCount) {
        printf("Desno");
    } else {
        printf("Ravnoteza");
    }
    
    return 0;
}