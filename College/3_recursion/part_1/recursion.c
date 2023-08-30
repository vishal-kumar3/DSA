#include <string.h>
#include "../../1_Linked_lists/part_1/new_1.c"
// #include "../../2_Stack/stack.c"

int arraySum(int* arr, int size){

    if(size-1 == -1){
        return 0;
    }
    return arr[size-1] + arraySum(arr, size-1);
}

char* stringReverse(char* s, int size){
    static int i = 0;
    // printf("%d ", i);
    char temp = s[i];
    s[i] = s[size-1-i];
    s[size-1-i] = temp;
    // swap(s[i], s[size-1-i]);
    ++i;

    if(i>size/2-1){
        return s;
    }

    return stringReverse(s, size);
}

int powerFunction(int base, int power){
    if(power<0){
        return -1;
    }
    else if(power==0 || base == 1){
        return 1;
    }
    else if(base == 0){
        return 0;
    }

    return base * powerFunction(base, power-1);
}

bool isPalindrome(char* c, int s, int e){

    if(s>=e){
        return true;
    }

    if(c[s] == c[e]){
        return isPalindrome(c, s+1, e-1);
    }
    else{
        return false;
    }

}

void Permutation(char* s, int start ,int end){
	static int i =1;
	if(start==end){
        printf("%d.%s\n", i,s);
        i++;
		return;
	}	
	
	int temp = start;
	for(; start<=end; start++){
		char str[20];
		strcpy(str, s);
		char ch_temp = str[start];
		str[start] = str[temp];
		str[temp] = ch_temp;
		// printf("%s\n", str);
		Permutation(str, temp+1, end);
	}
}

void towerOfHanoiR(int n, int s, int h, int d){
    if(n>0){
        towerOfHanoiR(n-1, s, d, h);
        printf("Move disc from %d to %d\n", s, h);
        towerOfHanoiR(n-1, h, s, d);
    }
}

// void mergeRecursive(struct Node* l1, struct Node* l2, struct Node** l3){

//     if(l1 == NULL && l2 == NULL){
//         return;
//     }

//     struct Node* temp = (struct Node*) malloc(sizeof(struct Node));

//     if(l1 == NULL){
        
//         temp -> data = l2 -> data;
//         temp -> next = NULL;
//         (*l3) -> next = temp;
//         merge(l1, l2->next, &temp);
//     }

//     else if(l2 == NULL){

//         temp -> data = l1 -> data;
//         temp -> next = NULL;
//         (*l3) -> next = temp;
//         merge(l1 -> next, l2, &temp);
//     }

//     else if(l1 -> data >= l2 -> data){
//         temp -> data = l2 -> data;
//         temp -> next = NULL;
//         (*l3) -> next = temp;
//         merge(l1, l2->next, &temp);
//     }
//     else{
//         temp -> data = l1 -> data;
//         temp -> next = NULL;
//         (*l3) -> next = temp;
//         merge(l1 -> next, l2, &temp);
//     }

// }

// lengthRecursive();


int main(){

    // int arr[] = {1,2,3,4,5,6};
    // printf("sum of array = %d\n", arraySum(arr, 6));
    
    // char s[] = "1234";
    // printf("Reverse is %s\n", stringReverse(s, 4));

    // int base = 2, power = 3;
    // printf("%d to the Power of %d = %d\n", base, power, powerFunction(base, power));

    // char c[] = "AAAAA";
    // if(isPalindrome(c, 0, 4)){
    //     printf("True");
    // }
    // else{
    //     printf("False");
    // }

    // char str[] = "ABCD";
    // Permutation(str, 0, 3);
    // printf("\n");

    // struct Node* head = NULL;
    // struct Node* head2 = NULL;
    // struct Node* head3 = NULL;
    // insertNode(&head, 1);
    // insertNode(&head, 2);
    // insertNode(&head, 3);
    // insertNode(&head, 6);

    // insertNode(&head2, 0);
    // insertNode(&head2, 2);
    // insertNode(&head2, 7);
    // insertNode(&head2, 8);


    // printf("length = %d\n", lengthRecursive(head));
    // printf("index = %d\n", searchRecursion(head, 2));
    // reverse_recursion(&head, head, NULL);
    // display(head);
    // printf("\n");
    // printf("middle = %d\n", middleRecursion(head, head, head)->data);
    // mergeRecursive(head, head2, head3);
    // display(head);
    // printf("\n");

    // towerOfHanoiR(3, 1,2,3);

    return 0;
}