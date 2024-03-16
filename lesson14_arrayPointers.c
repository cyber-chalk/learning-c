#include <stdio.h>

int arraySum(int array[], const int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) sum += array[i];
    return sum;
}

int arraySum2(int *array, const int n) {
    int sum = 0;
    int *ptr = array;
    //  printf("%d array", *(ptr + 1));
    while(ptr < array + n) {
        sum += *ptr;
        printf("num %d   ", *ptr);
        ptr++;
    }
    return sum;
}   

int main () {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("array sum 1: %d \n", arraySum(arr, size));
    printf("array sum 2: %d", arraySum2(arr, size));
    return 0;
}