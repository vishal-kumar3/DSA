#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


// void Permutation(char* s, int size){
//     int x = size;
    
//     char* temp = (char*)malloc(size*sizeof(char));
//     strcpy(temp, s);
    
//     while(x>0){
//         x--;
//         for(int i=0; i<size-1; i++){
//             char tempChar = temp[i];
//             temp[i] = temp[i+1];
//             temp[i+1] = tempChar;

//             printf("%s\n", temp);
//         }
//     }
//     free(temp);
// }

void Permutation(char* s, int size){

    for(int i=0; i<size-1; i++){
        char* temp = (char*)malloc(size*sizeof(char));
        strcpy(temp, s);
        for(int j=0; j<size-1; j++){
            
        }
    }


}


// void permuations(char* s, int size){

    

//     printf("%s\n", s);
//     return permuations(s, size);
// }

int main(){

    // int arr[] = {1,2,3,4,5,6};
    // printf("sum of array = %d\n", arraySum(arr, 6));
    
    // char s[] = "1234";
    // printf("Reverse is %s\n", stringReverse(s, 4));

    // int base = 2, power = 3;
    // printf("%d to the Power of %d = %d\n", base, power, powerFunction(base, power));

    char str[] = "1234";
    Permutation(str, 4);

    return 0;
}