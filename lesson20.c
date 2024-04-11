#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
        int data;
        struct Node* next;
}node;

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

bool palindrome(char* str, int n) {
        if (n <= 0) return true;
        if (str[0] != str[n-1]) return false;
        return palindrome(str + 1, n - 2);
}

int count(node n) {
        if (n.next == NULL) return 1;
        return 1 + count(*n.next);
}

int main() {
        //  printf("%d", factorial(5));
        //      printf("%d", palindrome("eve", 0));
        node node1 = {1}, node2 = {2}, node3 = {3};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

        printf("%d", count(node1));

    return 0;
}
