#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

struct Queue{
    int back;
    int front;
    int capacity;
    int* array;
};

struct Queue* CreateQueue(int capacity){
    struct Queue* queue = (struct Queue* )malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->array = (int* )malloc(capacity*sizeof(int));
    queue->front = -1;
    queue->back = -1;
    return queue;
}

bool isFull(struct Queue* queue){
    if(queue->back == queue->capacity-1){
        return true;
    }
    return false;
}

bool isEmpty(struct Queue* queue){
    if(queue->front > queue->back || queue->front == -1){
        return true;
    }
    return false;
}

void enqueue(struct Queue* queue, int value){
    if(isFull(queue)){
        printf("\nThe queue is Full!!\n");
        return;
    }
    if(queue->front == -1){
        queue->front = 0;
    }
    queue->back++;
    queue->array[queue->back] = value;
    printf("%d is added!!\n", value);
}

void dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("\nThe queue is Empty.\n");
        return;
    }
    printf("%d is poped!!\n", queue->array[queue->front]);
    queue->front++;
}

void display(struct Queue* queue){
    printf("\nQueue : ");
    if(isEmpty(queue)){
        printf("Empty");
    }
    else{
        for(int i=queue->front; i<=queue->back; i++){
            printf("%d ", queue->array[i]);
        }
    }
    printf("\n");
}

int main(){
    struct Queue* queue = CreateQueue(MAX);
    
    int choice, value;

    printf("\nCircular Queue Menu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Check if Full\n");
    printf("4. Check if Empty\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    do {
        printf("\nChoice> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                if (isFull(queue)) {
                    printf("Queue is Full.\n");
                } else {
                    printf("Queue is not Full.\n");
                }
                break;
            case 4:
                if (isEmpty(queue)) {
                    printf("Queue is Empty.\n");
                } else {
                    printf("Queue is not Empty.\n");
                }
                break;
            case 5:
                display(queue);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;


}