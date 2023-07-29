#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
};

// struct Node* head;


void display(struct Node* nd){
    struct Node* current = nd;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}


void insertNode(int value, struct Node* nd){
    struct Node* current = nd;
    // struct Node n;
    // n.data = value;
    // n.next = NULL;

    while(current->next != NULL){
        // printf("%d ", current->data);
        current = current->next;
    }

    current->next = (struct Node*)malloc(sizeof(struct Node));
    current = current->next;
    current->data = value;
    current->next = NULL;
}


void deleteNode(int value, struct Node* nd){
    struct Node* current = nd;
    struct Node* prev = NULL;

    while(current!=NULL){
        if(current->data==value){
            if(prev == NULL){
                nd = current->next;
            }
            else{
                prev->next = current->next; 
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}


// void reverseList(){
//     struct Node* current = head;
//     free(current);
// }

int length(struct Node* nd){
    struct Node* current = nd;   
    int size = 0;
    
    while(current != NULL){
        size++;
        current = current->next;
    }

    return size;
}


int searchNode(int target, struct Node* nd){
    struct Node* current = nd;
    int pos = 0;

    while(current != NULL){
        if(current->data==target){
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;
}


int main(){

    struct Node* head;
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    
    n1->data = 5;
    n1->next = NULL;

    head = n1;


    // display();
    insertNode(15, head);
    insertNode(20, head);
    printf("\n%d\n", searchNode(20, head));
    // printf("\n%d\n", length());
    // printf("\n");
    // display();
    // deleteNode(5);
    // printf("\n%d\n", length());
    // deleteNode(15);
    // printf("\n");
    // display();

    printf("\n");


    if(!n1){
        free(n1);
    }
    return 0;
}