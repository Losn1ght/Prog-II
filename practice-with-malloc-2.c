#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    int idnum;
    int grades[4];
} Student;

void inputStudInfo(Student *s, int num);
void displayList(Student *s, int num);
void checkGrade(Student *s, int num);


int main(){
    int num;


    printf("How many students you want to put in the list? ");
    scanf("%d", &num);

    Student *s1 = (Student*)malloc(sizeof(Student) * num);
    inputStudInfo(s1, num);
    //displayList(s1, num);
    checkGrade(s1, num);
    
    free(s1);

    
}
void checkGrade(Student *s, int num){
    
    
    for(int i = 0; i < num; i++){
        int total = 0;
        float average = 0;
        for(int j = 0; j < 4; j++){      
            total += s[i].grades[j];
            average = total/4;
        }if(average >= 80){
            printf("Student Passed!\n");
            printf("Name: %s\n", s[i].name);
            printf("Average: %.2f\n", average);
        }else{
            printf("Student Failed!\n");
            printf("Name: %s\n", s[i].name);
            printf("Average: %.2f", average);
        }
    }
}

void displayList(Student *s, int num){
    for(int i = 0; i < num; i++){
        printf("Name: %s\n", s[i].name);
        printf("Id number: %d\n", s[i].idnum);
        printf("Grades: %d %d %d %d\n", s[i].grades[0], s[i].grades[1], s[i].grades[2], s[i].grades[3]);
        printf("\n");
    }
    
}

void inputStudInfo(Student *s, int num){

    for(int i = 0; i < num; i++){
        printf("Student %d\n", i + 1);
        printf("Name: ");
        getchar();
        scanf("%[^\n]s", s[i].name);
        printf("Id Number: ");
        scanf("%d", &s[i].idnum);
        printf("Grades:\t\n");
        for(int j = 0;  j < 4; j++){
            printf("Subject %d: ", j + 1);
            scanf("%d", &s[i].grades[j]);
        }
        printf("\n");
    }

    
}
