#include<stdio.h>

int* maxValue(int* array, int length){
    int* max = array;

    for(int i=1; i<length-1; i++){
        if(*max <= *(array + i)){
            max = (array + i);
        }
    }

    return max;
}


int main(){

    int array[] = {1,2,3,114,15,6,7,8,9};

    int* max = maxValue(array, 9);
    printf("%d\n", *max);

    return 0;
}