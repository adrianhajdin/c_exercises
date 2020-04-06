#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char ime[100];
    char prezime[100];
    int dan;
    int mjesec;
    int godina;
} student;

void sortNames(student students[], int n){
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (strcmp(students[j - 1].prezime, students[j].prezime) > 0) {
                student tmp = students[j - 1];

                students[j - 1] = students[j];
                students[j] = tmp;
            }
        }
        
    }

    for(int i = 0; i < n; i++){
        if(strcmp(students[i].prezime, students[i + 1].prezime) == 0){
            if(strcmp(students[i].ime, students[i + 1].ime) > 0){
                student tmp = students[i];

                students[i] = students[i + 1];
                students[i + 1] = tmp;
            }
        }
    }
}

void sortDate(student students[], int n) {
    for(int i = 0; i < n; i++){
        if(students[i].ime == students[i + 1].ime && students[i].prezime == students[i + 1].prezime) {
            if(students[i].godina > students[i + 1].godina){
                student tmp = students[i];

                students[i] = students[i + 1];
                students[i + 1] = tmp;
            } else if(students[i].mjesec > students[i + 1].mjesec && students[i].godina == students[i + 1].godina) {
                student tmp = students[i];

                students[i] = students[i + 1];
                students[i + 1] = tmp;
            } else if(students[i].dan > students[i + 1].dan && students[i].godina == students[i + 1].godina && students[i].mjesec == students[i + 1].mjesec){
                student tmp = students[i];

                students[i] = students[i + 1];
                students[i + 1] = tmp;
            }
        }
    }
}


int main() {
    int n;
    student studenti[1000];

	scanf("%d ", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d.%d.%d.", studenti[i].ime, studenti[i].prezime, &studenti[i].dan, &studenti[i].mjesec, &studenti[i].godina);
    }

    sortNames(studenti, n);
    sortDate(studenti, n);

    for (int i = 0; i < n; i++) {
        printf("%s;%s;%d.%d.%d.\n", studenti[i].prezime, studenti[i].ime, studenti[i].dan, studenti[i].mjesec, studenti[i].godina);
    }

    return 0;
}