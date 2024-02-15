#include <stdio.h>


int main () {
    float arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int total = 0;
    float size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    printf("%.2f", total / size);
    return 0;
}