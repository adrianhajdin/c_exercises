#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
typedef struct {
    char ime[128];
    char prezime[128];
    char email[50];
    char alergija[3];
    int pocinjeAg;
    int zavrsavaAG;
} pacijent;
 
typedef struct{
    int dan;
    int mjesec;
    int godina;
} datum;
 
int compare(pacijent pac1, pacijent pac2){
    if(strcmp(pac1.prezime,pac2.prezime) == 0){
        return strcmp(pac1.ime, pac2.ime);
    }

    return strcmp(pac1.prezime, pac2.prezime);
}
 
void sortiranje(pacijent pac[], int n){
    for(int i = 1; i < n; i++){
        pacijent tmp = pac[i];
        int j = i;
 
        while(j > 0 && compare(pac[j-1], tmp) > 0){
            pac[j] = pac[j-1];
            j--;
        }
        pac[j] = tmp;
    }
}
 
void ispravak_slova(char slova[]){
    for(int i = 0; i < strlen(slova); i++){
        if(isupper(slova[i])){
            slova[i] = tolower(slova[i]);
        }
    }
 
    slova[0] = toupper(slova[0]);
}
 
 
int main() {
    pacijent pac[100];
    datum dat;
    int n;
 
    scanf("%d\n", &n);

    for(int i = 0; i < n; i++){
        scanf("%s %s %s %s", pac[i].ime, pac[i].prezime, pac[i].email, pac[i].alergija);

        if(!strcmp(pac[i].alergija, "DA")){
            scanf("%d %d", &pac[i].pocinjeAg, &pac[i].zavrsavaAG);
        }

        ispravak_slova(pac[i].ime);
        ispravak_slova(pac[i].prezime);
    }
 
    scanf("%d.%d.%d",&dat.dan, &dat.mjesec, &dat.godina);
 
    sortiranje(pac, n);

    for(int i = 0; i < n; i++){
        if((pac[i].alergija[0] == 'D') && (dat.mjesec >= pac[i].pocinjeAg && dat.mjesec <= pac[i].zavrsavaAG)) {
            printf("%s, %s: %s\n", pac[i].prezime, pac[i].ime, pac[i].email);
        }
    }
 
    return 0;
}