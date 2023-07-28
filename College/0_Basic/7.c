#include <stdio.h>
#include <stdlib.h>

int* resizeArray(int* arr, int currentSize) {
    int newSize = currentSize * 2;
    int* resizedArray = (int*)malloc(newSize * sizeof(int));

    for (int i = 0; i < currentSize; ++i) {
        resizedArray[i] = arr[i];
    }

    free(arr); 

    return resizedArray;
}

int main() {
    int currentSize = 5;
    int* arr = (int*)malloc(currentSize * sizeof(int));
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    printf("Original Array: ");
    for (int i = 0; i < currentSize; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    arr = resizeArray(arr, currentSize);
    currentSize *= 2;

    printf("Resized Array: ");
    for (int i = 0; i < currentSize; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); 
    
    return 0;
}
