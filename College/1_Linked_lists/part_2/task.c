#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    int taskID;
    char description[100];
    int priority;
    struct Task* next;
};

void displayTasks(struct Task* task) {
    struct Task* currentTask = task;
    while (currentTask != NULL) {
        printf("Task ID: %d | Description: %s | Priority: %d\n", currentTask->taskID, currentTask->description, currentTask->priority);
        currentTask = currentTask->next;
    }
}

void addTask(struct Task** taskList, int taskID, const char* description, int priority) {
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    newTask->taskID = taskID;
    strcpy(newTask->description, description);
    newTask->priority = priority;
    newTask->next = NULL;

    if (*taskList == NULL) {
        *taskList = newTask;
    } else {
        struct Task* currentTask = *taskList;
        while (currentTask->next != NULL) {
            currentTask = currentTask->next;
        }
        currentTask->next = newTask;
    }
}

void removeTask(struct Task** taskList, int taskID) {
    struct Task* currentTask = *taskList;
    struct Task* previousTask = NULL;

    while (currentTask != NULL) {
        if (currentTask->taskID == taskID) {
            if (previousTask == NULL) {
                *taskList = currentTask->next;
            } else {
                previousTask->next = currentTask->next;
            }
            free(currentTask);
            printf("[+] Task with ID %d is removed!\n", taskID);
            return;
        }
        previousTask = currentTask;
        currentTask = currentTask->next;
    }
    printf("[-] Task with ID %d not found!\n", taskID);
}

int searchTask(struct Task** taskList, int targetTaskID) {
    struct Task* currentTask = *taskList;
    int pos = 0;

    while (currentTask != NULL) {
        if (currentTask->taskID == targetTaskID) {
            return pos;
        }
        currentTask = currentTask->next;
        pos++;
    }
    return -1;
}

int main() {
    struct Task* taskList = NULL;

    printf("\nTask Management:\n");
    printf(" 1.Add a task\n");
    printf(" 2.Remove a task by ID\n");
    printf(" 3.Display tasks\n");
    printf(" 4.Search for a task\n");
    printf(" 5.Exit the program\n");

    while (1) {
        int choice;
        printf("\nChoice> ");
        scanf("%d", &choice);

        int taskID;
        char description[100];
        int priority;

        if (choice != 3 && choice < 5) {
            printf("Task ID> ");
            scanf("%d", &taskID);
            printf("Description> ");
            scanf("%s", description);
            printf("Priority> ");
            scanf("%d", &priority);
        }

        switch (choice) {
            case 1:
                addTask(&taskList, taskID, description, priority);
                printf("[+] Task with ID %d is added!\n", taskID);
                break;
            case 2:
                removeTask(&taskList, taskID);
                break;
            case 3:
                displayTasks(taskList);
                printf("\n");
                break;
            case 4:
                printf("[+] Task with ID %d found at position %d!\n", taskID, searchTask(&taskList, taskID));
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
