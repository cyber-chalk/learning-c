#include <stdio.h>

int main () {
    int inputNum;
    printf("input num: \n");
    scanf("%d", &inputNum);

    if (inputNum % 1 == 0 && inputNum % inputNum == 0) {
        printf("Yes %d is a prime number", inputNum);
    } else {
        printf("No %d is not a prime number", inputNum);
    }
}