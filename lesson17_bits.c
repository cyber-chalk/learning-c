#include <stdio.h>

void unsignPrint(unsigned int num) {
    int size = sizeof(num) * 8;
    for (int i = size - 1 ; i >= 0; i--){
        if ((num >> i) & 1) printf("1");
        else printf("0"); 
    }
    printf("\n");
}

void signPrint(int num) {
    int size = sizeof(num) * 8;
    if (num < 0) {
        num = -num;
        printf("1");
    } else {
        printf("0");
    }
    
    for (int i = size -1 ; i >= 0; i--){
        if ((num >> i) & 1) printf("1");
        else printf("0"); 
    }
    printf("\n");
}

int main() {
    unsigned int num = 5;
    int neg = -5;
    // unsignPrint(num);
    signPrint(neg);
    // printf("%ld", sizeof(num));

    return 0;
}