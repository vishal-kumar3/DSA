#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void init(struct Stack* stack) {
    stack->top = NULL;
}

void push(struct Stack* stack, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return '\0'; // Stack underflow
    }
    struct Node* temp = stack->top;
    stack->top = temp->next;
    char data = temp->data;
    free(temp);
    return data;
}

bool isParenthesesMatch(const char* s) {
    struct Stack st;
    init(&st);

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&st, ch);
        } else {
            if (st.top == NULL) {
                return false;
            }
            char top = pop(&st);
            if ((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']')) {
                continue;
            } else {
                return false;
            }
        }
    }

    return (st.top == NULL);
}


bool isParenthesesMatchRecursion(const char* s){
    struct Stack st;
}


int main() {
    const char* s = "({[()]})";

    if (isParenthesesMatch(s)) {
        printf("True!!\n");
    } else {
        printf("False!!\n");
    }

    return 0;
}
