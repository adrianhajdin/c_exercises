#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 255

typedef struct{
  char ime[MAX];
  char prezime [MAX];
  int rijesivost_pozadatku[MAX];
  int ukupnobodova;
} ispit;


void insertion_sort(ispit student[], int n) {
    for (int i = 1; i < n; i++) {
        ispit element = student[i];
        int j = i;

        while (j > 0 && student[j - 1].ukupnobodova < element.ukupnobodova) {
            student[j] = student[j - 1];
            j--;
        }

        student[j] = element;
    }
}

void sortiaj_string(ispit student[],int n){
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if(strcmp(student[i].prezime,student[j].prezime) < 0 && strcmp(student[i].prezime,student[j].prezime)!=0 && student[i].ukupnobodova==student[j].ukupnobodova){
        ispit pomoc;
        pomoc=student[i];
        student[i]=student[j];
        student[j]=pomoc;
      }
      else if (strcmp(student[i].ime,student[j].ime) < 0 && strcmp(student[i].ime,student[j].ime)!=0 && student[i].ukupnobodova==student[j].ukupnobodova){

        ispit pomoc;
        pomoc=student[i];
        student[i]=student[j];
        student[j]=pomoc;
      }
    }
  }
}

int main() {
  ispit student[MAX];
  int broj_zadataka;
  int bodovi_pozadatku[MAX];
  int broj_studenata;
 

  scanf("%d\n",&broj_zadataka);
  
  for (int i = 0; i < broj_zadataka; ++i)
  {
    scanf("%d ",&bodovi_pozadatku[i]);
  }

  scanf("%d\n",&broj_studenata);

  for (int i = 0; i < broj_studenata; ++i){   
      student[i].ukupnobodova=0;
    scanf("%s %s ",student[i].ime,student[i].prezime);
    for (int j = 0; j < broj_zadataka; ++j)
    {
      scanf("%d ",&student[i].rijesivost_pozadatku[j]);
      if(student[i].rijesivost_pozadatku[j]){
        student[i].ukupnobodova+=bodovi_pozadatku[j];
      }
    }

    scanf("\n");
  }



  insertion_sort(student,broj_studenata);
  sortiaj_string(student,broj_studenata);

  
  

  

for (int i = 0; i < broj_studenata; ++i){
  printf("%s %s %d\n",student[i].ime,student[i].prezime,student[i].ukupnobodova);
}


  return 0;
}
