#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAIN

struct Node{
    int data;
    struct Node* next;
};


void display(struct Node* node){
    struct Node* current = node;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}


void createList(struct Node** node, int* array, int len){
    for(int i=0; i<len; i++){
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = array[i];
        new_node->next = NULL;

        if (*node == NULL) {
            *node = new_node; // If the list is empty, new_node becomes the first node
        } else {
            struct Node* current = *node;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node; // Add new_node at the end of the list
        }
    }
}


void insertNode(struct Node** node, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*node == NULL) {
        *node = new_node; // If the list is empty, new_node becomes the first node
    } else {
        struct Node* current = *node;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node; // Add new_node at the end of the list
    }
}


void deleteNode(struct Node** node, int value) {
    struct Node* current = *node;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                // If the node to be deleted is the head node
                *node = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("[-] %d not found in the list!\n", value);
}


// double pointer bcoz iss baar head/node me change krna tha
void reverseList(struct Node** node){
    struct Node* current = *node;
    struct Node* prev = NULL;

    while(current!=NULL){
        struct Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

     // head change kr diya
    *node = prev;
}

int length(struct Node* node){
    struct Node* current = node;   
    int size = 0;
    
    while(current != NULL){
        size++;
        current = current->next;
    }

    return size;
}

int lengthRecursive(struct Node* node){
    static int len=0;
    struct Node* current = node;
    if(current==NULL){
        return len;
    }
    len++;
    return lengthRecursive(current->next);
}


int searchNode(struct Node* node, int target){
    struct Node* current = node;
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

int searchRecursion(struct Node* node, int target){
    struct Node* current = node;
    static int pos = 0;

    if(current==NULL){
        return -1;
    }
    else if(current->data==target){
        return pos;
    }
    pos++;
    return searchRecursion(current->next, target);
}


void reverse_recursion(struct Node** node, struct Node* current, struct Node* prev){

    if (current == NULL){
        *node = prev;
        return;
    }
    
    struct Node* next = current->next;
    current->next = prev;
    return reverse_recursion(node, next, current);
}

void merge(struct Node** n1, struct Node* n2){
    struct Node* c1 = *n1;
    struct Node* prev = NULL;

    struct Node* c2 = n2;

    while(c2 != NULL){
        struct Node* temp = c2->next;
        if(c1->next == NULL){
            c1->next = c2;
            c1->next->next = NULL;
            c2 = temp;
        }
        else if(c1->data >= c2->data){
            c2->next = c1;
            // if is just used for head nothing else
            if(prev == NULL){
                prev = *n1;
                *n1 = c2;
            }
            else{
                prev->next = c2;
            }
            c2 = temp;
        }
        else if(c1->data < c2->data){
            prev = c1;
            c1 = c1->next;
        }
    }
}


struct Node* middle(struct Node* node){
    struct Node* fast = node;
    struct Node* slow = node;

    int fast_cnt = 0, slow_cnt = 0;

    while(fast != NULL){
        if(fast_cnt/2 - slow_cnt == 1){
            slow = slow->next;
            slow_cnt++;
        }
        fast = fast->next;
        fast_cnt++;
    }

    return slow;
}

struct Node* middleRecursion(struct Node* node, struct Node* fast, struct Node* slow){
    // struct Node* fast = node, *slow = node;
    static int fast_cnt=0, slow_cnt=0;

    if(fast == NULL){
        return slow;
    }

    if(fast_cnt/2 - slow_cnt == 1){
        slow_cnt++;
        return middleRecursion(node, fast, slow->next); 
    }
    fast_cnt++;
    return middleRecursion(node, fast->next, slow);
}

#ifndef MAIN

int main(){
    struct Node* head=NULL;
    int arr[] = {1,2,3};
    createList(&head, arr, 3);
    display(head);

    struct Node* mid = middle(head);
    printf("\n%d\n", mid->data);

}

int maaaain(){

    struct Node* head=NULL;
    // struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    
    // n1->data = 5;
    // n1->next = NULL;

    // head = n1;


    printf("\nOperations for Linked List:-\n");
    printf(" 1.Insert a node at the end of the list\n");
    printf(" 2.Delete a node by value\n");
    printf(" 3.Display the list\n");
    printf(" 4.Reverse the list\n");
    printf(" 5.Search for a node\n");
    printf(" 6.Exit the program\n");

    while(1){

        int choice;
        printf("\nChoice> ");
        scanf("%d", &choice);

        int value;
        if(choice!=3 && choice<6 && choice!=4){
            printf("Value> ");
            scanf("%d", &value);
        }

        switch (choice)
        {
        case 1:
            insertNode(&head, value);
            printf("[+] %d is added!\n", value);
            break;

        case 2:
            deleteNode(&head, value);
            printf("[+] %d is Deleted!\n", value);
            break;    

        case 3:
            display(head);
            printf("\n");
            break;    

        case 4:
            reverseList(&head);
            printf("[+] List is reversed!\n");
            break;  

        case 5:
            printf("[+] %d found at %d!\n", value, searchNode(head, value));
            break;    

        case 6:
            printf("\nCODE EXITS!!");
            return 0;
            break;    

        default:
            printf("[-] Choose Correctly!!!");
            break;
        }
    }

    return 0;
}

#endif