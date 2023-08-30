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
    for(int i=queue->front; i<=queue->back; i++){
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main(){
    struct Queue* queue = CreateQueue(MAX);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);

    display(queue);

    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    display(queue);
    

}