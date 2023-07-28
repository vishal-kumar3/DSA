#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    int age;
    char name[50];
};

struct Student CreateStudent(int age, char name[]){
    struct Student s; 
    s.age = age;
    strcpy(s.name, name);
    return s;
}

void display(struct Student s){
    printf("Stduent Name: %s\nStduent Age: %d\n", s.name, s.age);
}

int main(){
    int noOfStudents;
    printf("\nEnter Number of students: ");
    scanf("%d", &noOfStudents);

    struct Student* students = (struct Student*)malloc(noOfStudents * sizeof(struct Student));
    
    for(int i=0; i<noOfStudents; ++i){

        printf("\nEnter Name of Stduent %d: ", i+1);
        scanf("%s", (students + i)->name);
        
        printf("Enter Age : ");
        scanf("%d", &(students + i)->age);
    }

    for(int i=0; i<noOfStudents; ++i){
        printf("\nStudent ID: %d\n", i+1);
        display(students[i]);
    }

    free(students);

    return 0;
}