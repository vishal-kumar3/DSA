#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Queue{
    int back;
    int head;
    int capacity;
    int* array;
};

struct Queue* CreateQueue(int capacity){
    struct Queue* queue = (struct Queue* )malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->array = (int)malloc(capacity*sizeof(int));
    queue->head = -1;
    queue->back = -1;
}

