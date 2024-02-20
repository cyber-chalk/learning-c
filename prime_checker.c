#include <stdio.h>

int main () {
    int inputNum;
    printf("input num: \n");
    scanf("%d", &inputNum);

    
    for(int i = 2; i < inputNum; i++) {
        if (inputNum % i == 0 && i != inputNum) {
           break;
        } else {
             printf("yes it is a prime number %d", i);
            return 0;
        }
    }
    printf("no its not a prime number");
    return 0;
}