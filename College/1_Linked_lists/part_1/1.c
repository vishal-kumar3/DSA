#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
};

// struct Node* head;

void display(struct Node* node){
    struct Node* current = node;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}



void insertNode(struct Node** node, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    // struct Node n;
    // n.data = value;
    // n.next = NULL;

    if(*node == NULL){
        *node = newNode;
    }

    else{
        struct Node* current = *node;
        while(current->next != NULL){
            // printf("%d ", current->data);
            current = current->next;
        }
        current->next = newNode;
    }
}


void deleteNode(struct Node** node, int value){
    struct Node* current = *node;
    struct Node* prev = NULL;

    while(current!=NULL){
        if(current->data==value){
            if(prev == NULL){
                *node = current->next;
            }
            else{
                prev->next = current->next; 
            }
            free(current);
            printf("[+] %d is Deleted!\n", value);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("[-] %d not found!\n", value);
}

// double pointer bcoz iss baar head/node me change krna tha
void reverseList(struct Node** node){
    struct Node* current = *node;
    struct Node* prev = NULL;

    while(current != NULL){
        struct Node* curr_next = current->next;
        current->next = prev;
        prev = current;
        current = curr_next;
    }

    // head change kr diya
    *node = prev;
}


int length(struct Node** node){
    struct Node* current = *node;
    int size = 0;
    
    while(current != NULL){
        size++;
        current = current->next;
    }

    return size;
}


int searchNode(struct Node** node, int target){
    struct Node* current = *node;
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

    struct Node* head=NULL;
    // struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    
    // head = (struct Node*)malloc(sizeof(struct Node));
    // head->next = NULL;
    // n1->data = 5;
    // n1->next = NULL;

    // head = n1;

    // deleteNode(&head, 0);

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
            printf("[+] %d found at %d!\n", value, searchNode(&head, value));
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