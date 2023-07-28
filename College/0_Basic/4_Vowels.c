#include<stdio.h>

int cntVowels(char string[], int length){
    int cnt = 0;

    for(int i=0; i<length; i++){
        char c = string[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            cnt++;
            }
    }

    return cnt;
}

int length(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main(){

    char name[] = "stringaioue";
    int len = length(name);

    printf("No. of vowels is : %d\n", cntVowels(name, len));

    return 0;
}