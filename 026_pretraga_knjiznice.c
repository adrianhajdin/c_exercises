#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif
 
typedef struct {
    char author[101];
    char title[101];
    char subject[201];
} book;
 
int compare(book b1, book b2, int flag) {
    if (flag == 1)
    {
        return strcmp(b1.title, b2.title);
    }
    else if (flag == 2)
    {
        return strcmp(b1.author, b2.author);
    }
    else if (flag == 3)
    {
        return strcmp(b1.subject, b2.subject);
    }
 
    return -1;
}
 
void sort(book b[], int size, int flag) {
    for (int i = 0; i < size; i++)
    {
        book tmp = b[i];
        int j = i;
 
        while(j > 0 && compare(b[j - 1], tmp, flag) > 0) {
            b[j] = b[j - 1];
            j--;
        }
 
        b[j] = tmp;
    }
}
 
int main() {
    book b[100];
    int n, offset = 0, tmp, flag = 0;
    char line[325], word[100];
 
    scanf("%d\n", &n);
 
    for (int i = 0; i < n; i++)
    {
        scanf("%[^\n]\n", line);
 
        b[i].title[0] = b[i].author[0] = b[i].subject[0] = '\0';
        offset = 0;
 
        while(offset < strlen(line)) {
            sscanf(line + offset, "%s %n", word, &tmp);
            offset += tmp;
 
            if (!strcmp(word, "Title:"))
            {
                flag = 1;
            }
            else if (!strcmp(word, "Author:"))
            {
                flag = 2;
            }
            else if (!strcmp(word, "Subject:"))
            {
                flag = 3;
            }
            else if (flag == 1)
            {
                strcat(b[i].title, word);
                strcat(b[i].title, " ");
            }
            else if (flag == 2)
            {
                strcat(b[i].author, word);
                strcat(b[i].author, " ");
            }
            else if (flag == 3)
            {
                strcat(b[i].subject, word);
                strcat(b[i].subject, " ");
            }
        }
 
        b[i].title[strlen(b[i].title) - 1] = '\0';
        b[i].author[strlen(b[i].author) - 1] = '\0';
        b[i].subject[strlen(b[i].subject) - 1] = '\0';
    }
 
    scanf("%s", word);
 
    if (!strcmp(word, "title"))
    {
        flag = 1;
    }
    else if (!strcmp(word, "author"))
    {
        flag = 2;
    }
    else if (!strcmp(word, "subject"))
    {
        flag = 3;
    }
 
    sort(b, n, flag);
 
    if (flag == 1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%s, %s; %s\n", b[i].title, b[i].author, b[i].subject);
        }
    }
    else if (flag == 2)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%s: %s; %s\n", b[i].author, b[i].title, b[i].subject);
        }
    }
    else if (flag == 3)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%s; %s: %s\n", b[i].subject, b[i].author, b[i].title);
        }
    }
 
 
  return 0;
}