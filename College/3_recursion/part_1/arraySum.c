#include<stdio.h>

int recursiveSum(int* arr, int size){

    if(size - 1 == -1){
        return 0;
    }

    return arr[size-1] + recursiveSum(arr, size - 1);
}


int main(){

    int arr[] = {1,2,3,4,5,6};
    
    int sum = recursiveSum(arr, 6);

    printf("The sum is = %d\n", sum);

    return 0;
}