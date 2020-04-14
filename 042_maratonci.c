#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 42195

typedef struct {
    int h;
    int m;
    int s;
} time;

typedef struct {
    char name[256];
    char category[256];
    time time;
    float speed;
} maratonac;

void calculate_average_time(maratonac maratonci[], int n, float average_speeds[]) {
    int count_p = 0;
    int count_r = 0;
    float total_speed_p = 0;
    float total_speed_r = 0;

    for (int i = 0; i < n; i++) {
        if(!strcmp(maratonci[i].category, "rekreativac")) {
            count_r++;
            total_speed_r += maratonci[i].speed;
        } else if(!strcmp(maratonci[i].category, "profesionalac")) {
            count_p++;
            total_speed_p += maratonci[i].speed;
        }
    }

    average_speeds[0] = total_speed_p / count_p;
    average_speeds[1] = total_speed_r / count_r;
}

void print_profesionals(maratonac maratonci[], int n, float average_speeds[]) {
    printf("Profesionalci:\n");

    for (int i = 0; i < n; i++) {
        if(!strcmp(maratonci[i].category, "profesionalac") && maratonci[i].speed > average_speeds[0]) {
            printf("\t%s %.2f\n", maratonci[i].name, maratonci[i].speed);
        }
    }
}

void print_recreatives(maratonac maratonci[], int n, float average_speeds[]) {
    printf("Rekreativci:\n");

    for (int i = 0; i < n; i++) {
        if(!strcmp(maratonci[i].category, "rekreativac") && maratonci[i].speed > average_speeds[1]) {
            printf("\t%s %.2f\n", maratonci[i].name, maratonci[i].speed);
        }
    }
}

void sort(maratonac maratonci[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(maratonci[j - 1].speed < maratonci[j].speed){
                maratonac tmp = maratonci[j - 1];

                maratonci[j - 1] = maratonci[j];
                maratonci[j] = tmp;
            }
        }
    }
}

int main() {
    int i = 0;
    float average_speeds[2];
    maratonac maratonci[128];
    
    FILE *fp;
    fp = fopen("input.dat", "r");

    while(!feof(fp)) {
        fscanf(fp, "%[^,], %[^:]: %d:%d:%d", maratonci[i].name, maratonci[i].category, &maratonci[i].time.h, &maratonci[i].time.m, &maratonci[i].time.s);

        maratonci[i].speed = (float) LENGTH / (float) (maratonci[i].time.h * 3600 + maratonci[i].time.m * 60 + maratonci[i].time.s); 

        i++;
    }
        
    calculate_average_time(maratonci, i, average_speeds);
    sort(maratonci, i);
    print_profesionals(maratonci, i, average_speeds);
    print_recreatives(maratonci, i, average_speeds);

    fclose(fp);

    return 0;
}