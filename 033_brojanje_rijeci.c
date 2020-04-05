#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char string[255];
    int br = 0;

    scanf("%[^\n]", string);

    string[0] = toupper(string[0]);

    for (int i = 1; i < strlen(string); ++i){
        string[i] = tolower(string[i]);
    }

    for (int i = 1; i < strlen(string); ++i){
        if (isblank(string[i])) {
            br++;
            
            string[i + 1] = toupper(string[i + 1]);
        }
    }

    printf("%d\n", br + 1);
    printf("%s", string);

    return 0;
}