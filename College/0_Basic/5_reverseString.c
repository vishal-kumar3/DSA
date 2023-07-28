#include<stdio.h>

void reverseString(char* string, int length, int i){
    if(length/2<=i){
        return;
    }    

    char temp = string[i];
    string[i] = string[length-i-1];
    string[length-i-1] = temp;
    
    return reverseString(string, length, i+1);
}

int length(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main(){

    char name[50] = "NamalmaN";

    reverseString(name, length(name), 0);

    for(int i=0; i<length(name); i++){
        printf("%c", name[i]);
    }
    printf("\n");

    return 0;
}