#include <string.h>
#include "../../1_Linked_lists/part_1/new_1.c"

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

void Permutation(char* s, int start ,int end){
	
	if(start==end){
		return;
	}	
	
	int temp = start;
	for(; start<=end; start++){
		char str[5]; 
		strcpy(str, s);
		char ch_temp = str[start];
		str[start] = str[temp];
		str[temp] = ch_temp;
		// printf("%s\n", str);
		Permutation(str, temp+1, end);
	}
}

int main(){

    // int arr[] = {1,2,3,4,5,6};
    // printf("sum of array = %d\n", arraySum(arr, 6));
    
    // char s[] = "1234";
    // printf("Reverse is %s\n", stringReverse(s, 4));

    // int base = 2, power = 3;
    // printf("%d to the Power of %d = %d\n", base, power, powerFunction(base, power));

    char str[] = "1234";
    Permutation(str, 0, 4);

    return 0;
}
