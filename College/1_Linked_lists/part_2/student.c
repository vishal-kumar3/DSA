#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[100];
    int rollNumber;
    float marks;
    struct Student* next;
};

void displayStudents(struct Student* student) {
    struct Student* currentStudent = student;
    while (currentStudent != NULL) {
        printf("Name: %s | Roll Number: %d | Marks: %.2f\n", currentStudent->name, currentStudent->rollNumber, currentStudent->marks);
        currentStudent = currentStudent->next;
    }
}

void addStudent(struct Student** studentList, const char* name, int rollNumber, float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->name, name);
    newStudent->rollNumber = rollNumber;
    newStudent->marks = marks;
    newStudent->next = NULL;

    if (*studentList == NULL) {
        *studentList = newStudent;
    } else {
        struct Student* currentStudent = *studentList;
        while (currentStudent->next != NULL) {
            currentStudent = currentStudent->next;
        }
        currentStudent->next = newStudent;
    }
}

void deleteStudent(struct Student** studentList, int rollNumber) {
    struct Student* currentStudent = *studentList;
    struct Student* previousStudent = NULL;

    while (currentStudent != NULL) {
        if (currentStudent->rollNumber == rollNumber) {
            if (previousStudent == NULL) {
                *studentList = currentStudent->next;
            } else {
                previousStudent->next = currentStudent->next;
            }
            free(currentStudent);
            printf("[+] Student with Roll Number %d is deleted!\n", rollNumber);
            return;
        }
        previousStudent = currentStudent;
        currentStudent = currentStudent->next;
    }
    printf("[-] Student with Roll Number %d not found!\n", rollNumber);
}

int searchStudent(struct Student** studentList, int targetRollNumber) {
    struct Student* currentStudent = *studentList;
    int pos = 0;

    while (currentStudent != NULL) {
        if (currentStudent->rollNumber == targetRollNumber) {
            return pos;
        }
        currentStudent = currentStudent->next;
        pos++;
    }
    return -1;
}

int main() {
    struct Student* studentList = NULL;

    printf("\nStudent Management:\n");
    printf(" 1.Add a student\n");
    printf(" 2.Delete a student by Roll Number\n");
    printf(" 3.Display students\n");
    printf(" 4.Search for a student\n");
    printf(" 5.Exit the program\n");

    while (1) {
        int choice;
        printf("\nChoice> ");
        scanf("%d", &choice);

        char name[100];
        int rollNumber;
        float marks;

        if (choice != 3 && choice < 5) {
            printf("Name> ");
            scanf("%s", name);
            printf("Roll Number> ");
            scanf("%d", &rollNumber);
            printf("Marks> ");
            scanf("%f", &marks);
        }

        switch (choice) {
            case 1:
                addStudent(&studentList, name, rollNumber, marks);
                printf("[+] Student with Roll Number %d is added!\n", rollNumber);
                break;

            case 2:
                deleteStudent(&studentList, rollNumber);
                break;

            case 3:
                displayStudents(studentList);
                printf("\n");
                break;

            case 4:
                printf("[+] Student with Roll Number %d found at position %d!\n", rollNumber, searchStudent(&studentList, rollNumber));
                break;

            case 5:
                printf("\nExiting the program!\n");
                return 0;
                break;

            default:
                printf("[-] Please choose a valid option!\n");
                break;
        }
    }

    return 0;
}
