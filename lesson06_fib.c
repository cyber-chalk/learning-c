#include <stdio.h>

int main () {
    int arr[15] = {0, 1};

    for (int i = 2; i < 15; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    return 0;
}