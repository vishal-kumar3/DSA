#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct Stack {
    int top;
    unsigned capacity;
    struct StackNode* stackNode;
};

struct Stack* CreateStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

    stack->top = -1;
    stack->capacity = capacity;
    stack->stackNode = NULL;
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }

    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));

    newNode->data = value;
    newNode->next = stack->stackNode; 
    stack->stackNode = newNode; 
    stack->top++;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }

    struct StackNode* temp = stack->stackNode;
    int data = temp->data;
    stack->stackNode = temp->next; 
    free(temp);
    stack->top--;
    return data;
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot peek\n");
        return -1; 
    }

    return stack->stackNode->data;
}

int main() {
    struct Stack* stack = CreateStack(5);

    printf("\nOperations for Stack using Array:-\n");
    printf(" 1.Insert a value at the end of the Stack\n");
    printf(" 2.Delete a value\n");
    printf(" 3.Check if stack is Full\n");
    printf(" 4.Check if stack is Empty\n");
    printf(" 5.Peek\n");
    printf(" 6.Exit the program\n");

    while(1){
        int choice;
        printf("\n\nChoice> ");
        scanf("%d", &choice);
        int value;

        switch (choice)
        {
        case 1:
            printf("Enter the Value to add in stack: ");
            scanf("%d", &value);
            push(stack, value);
            break;

        case 2:
            printf("%d is removed!!", pop(stack));
            break;
        
        case 3:
            if(isFull(stack)){
                printf("Stack is Full!!");
            }
            else{
                printf("Stack is Not Full!!");
            }
            break;

        case 4:
            if(isEmpty(stack)){
               printf("Stack is Empty!!");
            }
            else{
                printf("Stack is Not Empty!!");
            }
            break;

        case 5:
            printf("Peek : %d", peek(stack));
            break;

        case 6:
            printf("Exiting the programme!!");
            return 0;

        default:
            break;
        }
    }
    return 0;

    free(stack->stackNode);
    free(stack);

    return 0;
}
