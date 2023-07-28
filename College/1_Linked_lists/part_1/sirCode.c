#include <stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void display(){
    struct Node* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}


void insertNode(int value){
    struct Node* current = head;
    //struct Node n;
    //n.data = value;
    //n.next = NULL;

    while(current->next != NULL){
        // printf("%d ", current->data);
        current = current->next;
    }

    current->next = (struct Node*) malloc (sizeof (struct Node));
    current->next ->data = value;
    current->next-> next = NULL;
    //current = current->next;
    //printf("\n\n%d", current->data);
}




int main(){

    struct Node n1;
    struct Node n2;
    
    n1.data = 5;
    n2.data = 15;
    
    head = &n1;


    // n1.next = &n2;
    head->next = &n2;
    n2.next = NULL;


    display();
    insertNode(20);
    //printf("\nvishal");
    display();
    return 0;
}

