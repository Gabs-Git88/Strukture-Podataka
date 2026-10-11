#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char name[30];
    char surname[30];
    int score;
} Student;

static FILE* open_file() {
    FILE* fp = fopen("D:\\Strukture Podataka\\studenti_git.txt", "r");
    if (!fp){exit(1);}
    return fp;
}

static void close_file(FILE* fp) {
    fclose(fp);
}

static void display_arr(Student* arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%s %s %d %d%%\n",arr[i].name,arr[i].surname,arr[i].score, arr[i].score);
    }
}

static void see_int_file(FILE* fp) {
    int count = 0;
    char name[30];
    char surname[30];
    int score;
    Student* s_p = NULL;
    while (fscanf(fp, "%s %s %d", name, surname, &score) == 3) {
        ++count;
        Student* temp = (Student*)realloc(s_p, count * sizeof(Student));
        if (!s_p && !temp){free(s_p);exit(1);}
        s_p = temp;
        strcpy(s_p[count-1].name,name);
        strcpy(s_p[count-1].surname,surname);
        s_p[count-1].score = score;
    }
    display_arr(s_p,count);
    free(s_p);
}


int main() {
    FILE* fp = open_file();
    see_int_file(fp);
    close_file(fp);
    return 0;
}