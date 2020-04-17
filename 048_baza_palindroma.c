#include <stdio.h>
#include <string.h>
#include <ctype.h>

void clean_string(char s[]) {
  int i, n = 0;

  for (i = 0; i < strlen(s); i++) {
    if (!isalpha(s[i])) {
      n++;
    } else {
      s[i - n] = tolower(s[i]);
    }
  }

  s[i - n] = '\0';
}

int isPalindrome(char string[]) { 
    int l = 0; 
    int h = strlen(string) - 1; 
  
    while (h > l){ 
        if (string[l++] != string[h--]){ 
            return 0; 
        } 
    } 

    return 1; 
} 

int main() {
    int count = 0;
    char line[256];
    
	FILE *fp;
	fp = fopen("input.dat", "r");

	while(!feof(fp)) {
        fscanf(fp, "%[^\n]\n", line);

        clean_string(line);  

        if(isPalindrome(line)) {
            count++;
        }
    }

    printf("%d", count);

    fclose(fp);

    return 0;
}
