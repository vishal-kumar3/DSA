
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5


struct Queue{
    int front;
    int back;
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

void sort(struct Queue* queue){
    for(int i=queue->front; i<queue->back; i++){
        for(int j=i; j<queue->back; j++){
            if(queue->array[j]>queue->array[j+1]){
                int temp = queue->array[j];
                queue->array[j] = queue->array[j+1];
                queue->array[j+1] = temp;
            }
        }
    }
}

bool isFull(struct Queue* queue){
    return (queue->back == (queue->capacity-1));
}

bool isEmpty(struct Queue* queue){
    return ((queue->front > queue->back) || (queue->front == -1));
}

void enqueue(struct Queue* queue, int value){
    if(isFull(queue)){
        printf("\nQueue is Full!!!\n");
        return;
    }
    if(queue->front == -1){
        queue->front = 0;
    }
    queue->back++;
    queue->array[queue->back] = value;
    printf("%d is added!!\n", value);
    sort(queue);
}

void dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("The Queue is Empty!!!\n");
        return;
    }
    printf("The poped element is: %d\n", queue->array[queue->front]);
    queue->front++;
}

void display(struct Queue* queue){
    printf("\nQueue :- ");
    if(isEmpty(queue)){
        printf("Empty\n");
        return;
    }
    for(int i=queue->front; i<=queue->back; i++){
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main(){
    struct Queue* queue;

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