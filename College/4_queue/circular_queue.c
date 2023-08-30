#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

struct CircularQueue {
    int* array;
    int front;
    int rear;
    int size;
};

struct CircularQueue* createCircularQueue(int size) {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->array = (int*)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

bool isFull(struct CircularQueue* queue) {
    return (queue->front == (queue->rear + 1) % queue->size);
}

bool isEmpty(struct CircularQueue* queue) {
    return (queue->front == -1);
}

void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is Full!\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->array[queue->rear] = value;
    printf("%d is added to the queue.\n", value);
}

void dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("%d is removed from the queue.\n", queue->array[queue->front]);
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }
}

void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = queue->front;
    while (true) {
        printf("%d ", queue->array[i]);
        if (i == queue->rear) {
            break;
        }
        i = (i + 1) % queue->size;
    }
    printf("\n");
}

int main() {
    struct CircularQueue* queue = createCircularQueue(MAX);

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

