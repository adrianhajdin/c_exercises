#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 255

void sortiraj(float ponznak[],char znak[]){
  for (int i = 0; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            if (ponznak[j - 1] < ponznak[j] && ponznak[j-1]!=ponznak[j]) {
                float tmp = ponznak[j - 1];
                ponznak[j - 1] = ponznak[j];
                ponznak[j] = tmp;

                char pom=znak[j-1];
                znak[j-1]=znak[j];
                znak[j]=pom;


            }
        }
    }
}

void znaksortiraj(float ponznak[],char znak[]){
  for (int i = 0; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            if (znak[j - 1] > znak[j] && ponznak[j-1]==ponznak[j]) {
                char pom=znak[j-1];
                znak[j-1]=znak[j];
                znak[j]=pom;
            }
        }
    }
}


void ispis(float ponznak[],char znak[],int ukupno){
  for(int i=0; i<MAX; i++){
      if(!ponznak[i]){
        break;
      }

      printf("%c %.0f %.1f%%\n",znak[i],ponznak[i],(ponznak[i]/ukupno)*100);
  }
}




int main(){
    int ukupno=0;
    float ponznak[MAX]={0.0};
    char znak[MAX];
    char c;
    FILE *fp;

    fp = fopen("input.dat", "r");


    if(fp==NULL){
        printf("GRESKA!");
        return -1;
    }

    do {
        c=fgetc(fp);

        if(isalnum(c) || ispunct(c)){
            ukupno++;
            c=tolower(c);
            ponznak[c]++;
            znak[c]=c;
        }
    } while(c!=EOF);
    
    
    sortiraj(ponznak ,znak);

    znaksortiraj(ponznak ,znak);
    ispis(ponznak,znak,ukupno);

  return 0;
}