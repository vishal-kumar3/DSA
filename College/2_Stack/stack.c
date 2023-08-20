#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* CreateStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int)malloc(stack->capacity * sizeof(struct Stack));
    return stack;
}

int isFull(struct Stack* stack){

    if(stack->top==(stack->capacity-1)){
        printf("[+] Stack is Full!!");
        // if full will return 1 else 0
        return 1;
    }
    else{
        printf("[-] Stack is not Full!!");
        return 0;
    }
}

int isEmpty(struct Stack* stack){
    // if empty will return -1 else will return 0
    if(stack->top==-1){
        printf("[+] Stack is Empty!!");
        return 1;
    }
    else{
        printf("[-] Stack is not Empty!!");
        return 0;
    }
}

int dispaly(struct Stack* stack){
    for(int i=0; i<=stack->top; i++){
        printf("%d ", stack->array[i]);
    }
}


void push(struct Stack* stack, int value){

    if(stack->top == (stack->capacity-1)){
        printf("[-] The Stack is FUll!!");
        return;
    }
    else{
        stack->top++;
        stack->array[stack->top] = value;
        printf("[+] %d is added to the stack!!", value);
    }
}

void pop(struct Stack* stack){
    if(stack->top == -1){
        printf("[-] The stack is empty!!");
        return;
    }
    else{
        // stack->array[stack->top]=NULL;
        stack->top = stack->top-1;
        printf("[+] %d is removed!!", stack->array[stack->top+1]);
    }
}


int main(){

    struct Stack* stack = CreateStack(MAX);
    
    printf("\nOperations for Stack using Array:-\n");
    printf(" 1.Insert a value at the end of the Stack\n");
    printf(" 2.Delete a value\n");
    printf(" 3.Display the Stack\n");
    printf(" 4.Check if stack is Full\n");
    printf(" 5.Check if stack is Empty\n");
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
            pop(stack);
            break;
        
        case 3:
            dispaly(stack);
            break;

        case 4:
            isFull(stack);
            break;

        case 5:
            isEmpty(stack);
            break;

        case 6:
            printf("Exiting the programme!!");
            return 0;

        default:
            break;
        }
    }
    return 0;
}