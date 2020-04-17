#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct { int dan; int mjesec; int godina; } datum;

typedef struct { char jmbag[128]; char ime[128]; char prezime[128]; datum datum_rodenja; } student;

void sort(student s[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (strcmp(s[j - 1].jmbag, s[j].jmbag) > 0) {
                student tmp = s[j - 1];

                s[j - 1] = s[j];
                s[j] = tmp;
            }
        }
    }
}

void print_student(student s) {
    printf("%s %s %s %d.%d.%d.\n", s.jmbag, s.prezime, s.ime, s.datum_rodenja.dan, s.datum_rodenja.mjesec, s.datum_rodenja.godina);
}

void search_and_print(student s[], int n, char tip_pretrage, char vrijednost[]) {
    int nasao = 0;

    for (int i = 0; i < n; i++) {
        if((tip_pretrage == 'I' && !strcmp(s[i].ime, vrijednost)) || (tip_pretrage == 'P' && !strcmp(s[i].prezime, vrijednost)) || (tip_pretrage == 'J' && !strcmp(s[i].jmbag, vrijednost))) {
            print_student(s[i]);
            nasao = 1;
        } 
    }

    if(!nasao) {
        printf("-\n");
    }
}


int main() {
    int n, m;
    student s[1000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %s %s %s %d.%d.%d.", s[i].jmbag, s[i].ime, s[i].prezime, &s[i].datum_rodenja.dan, &s[i].datum_rodenja.mjesec, &s[i].datum_rodenja.godina);
    }

    sort(s, n);

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        char vrijednost[32];
        char tip_pretrage;

        scanf(" %c %s", &tip_pretrage, vrijednost);

        if (tip_pretrage == 'I') {
            printf("Ime: %s\n", vrijednost);

            search_and_print(s, n, tip_pretrage, vrijednost);
        } else if (tip_pretrage == 'P') {
            printf("Prezime: %s\n", vrijednost);

            search_and_print(s, n, tip_pretrage, vrijednost);
        } else if (tip_pretrage == 'J') {
            printf("JMBAG: %s\n", vrijednost);

            search_and_print(s, n, tip_pretrage, vrijednost);
        }
    }
    
    return 0;   
}