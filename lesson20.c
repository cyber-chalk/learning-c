#include <stdio.h>

int factorial (int num) {
    int result = num;
    for(int i = num -1; i >= 1; i--) {
        result *= num - i;
    }
    return result;
}


void fibonachi (int num) {
    int arr[15] = {0, 1};
    for (int i = 2; i < 15; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

int odds(int n) {
    if (n == 1) {
        return 1;
    } else {
        return (2 * n - 1) * odds(n - 1);
    }
}


int main() {
    printf("%d", factorial(5));
    return 0;
}