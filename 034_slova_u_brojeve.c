#include <stdio.h>
#include <ctype.h>
#include <string.h>

int tonum(char in[]) {
    int out;

    if (!strcmp(in, "nula")) {
        out = 0;
    } else if (!strcmp(in, "jedan")) {
        out = 1;
    } else if (!strcmp(in, "dva")) {
        out = 2;
    } else if (!strcmp(in, "tri")) {
        out = 3;
    } else if (!strcmp(in, "cetiri")) {
        out = 4;
    } else if (!strcmp(in, "pet")) {
        out = 5;
    } else if (!strcmp(in, "sest")) {
        out = 6;
    } else if (!strcmp(in, "sedam")) {
        out = 7;
    } else if (!strcmp(in, "osam")) {
        out = 8;
    } else if (!strcmp(in, "devet")) {
        out = 9;
    }

    return out;
}

int main() {
    char string[255];

    scanf("%[^\n]\n", string);

    while(string[0] != '_') {
        char newString[256] = {'\0'};
        float out = 0;
        int j = 0;

        for (int i = 0; i <= strlen(string); i++) {
            if(string[i] == '_' || i == strlen(string)) {
                out *= 10;
                out += tonum(newString);

                int n = strlen(newString);

                for (int k = 0; k < n; k++) {
                    newString[k] = '\0';
                }
                
                j = 0;
            }

            if (isalpha(string[i])) {
                newString[j] = tolower(string[i]);
                
                j++;
            } 
        }

        printf("%.2f\n", out / 2);

        scanf("%[^\n]\n", string);
    }

    return 0;
}