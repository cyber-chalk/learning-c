#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;

void swap (int * const a, int* const b) {
    int const temp = *a;
    *a = *b;
    *b = temp;
}

struct Node *findNode (int i, node *head) {
    int n = head->data;
    while(head != NULL) {
        if (n == i) return head;
        n++;
        head = head->next;
    }
    printf("invalid");
}

int main () {
    int a = 5, b = 6;
    int* ptrA = &a;
    int* prtB = &b;

    // swap(ptrA, prtB);
    // printf("%d %d", *ptrA, *prtB);

    /*the same*/
    const int h = 4; 
    int const m = 6; 
    // First case: constant pointer
    int x = 10;
    int *const ptr2 = &x; // 🟥 address ✅ value
    // Second case: pointer to a const value
    int const *pt3 = &x;    // ✅ address 🟥 value
    const int *intPtr = &x; //  ✅ address 🟥 value

    node node1 = {1}, node2 = {2}, node3 = {3};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    node *head = &node1; //&

    printf("%d",findNode(2, head)->data);

    return 0;
}
// int const *a, int const *b: This means a and b are pointers to constant integers. You cannot modify the values they point to, but you can change the addresses they point to.

// int *const a, int *const b : This means a and b are constant pointers to integers.You cannot change the addresses they point to, but you can modify the values they point to.