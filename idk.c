#include <stdio.h>

struct _node {
  int p;
  struct _node *ptr;
};

typedef struct _node node;

struct date {
    int m;
    int d;
    int y;
} today ;

// This is just pseudocode to give you an idea
// insertNode({1}->{2}, {3}) --> {1}->{2}->{3}
void insertNode(node *head, node * newNode) {
  
 
}

int main() {
    
    // today.m = 3;
    
    // Use a pointer!
    struct date *datePtr = &today;
    
    // This is the long way to do it
    (*datePtr).m = 3;
    (*datePtr).d = 12;
    (*datePtr).y = 24;
    
    // There is a short way to do it
    // Use the arrow operator ->
    datePtr->m = 3;
    datePtr->d = 12;
    datePtr->y = 24;
    
    node one = {.p = 1};
    node two = {.p = 2};
    node three = {.p = 3};
    
    one.ptr = &two;
    two.ptr = &three;
    three.ptr = NULL;
    
    // if (three.ptr == NULL) {
    //     //printf("Nothing left in the list, bruh.");
    // }
    
    node *head = &one;
    while (head != NULL) {
        printf("The payload is: %d\n",    head->p);
        head = head->ptr;
    }

    node four = {.p = 4};
    node* newNodePtr;
    insertNode(head,newNodePtr);
    
    while (head != NULL) {
        printf("The payload is: %d\n",    head->p);
        head = head->ptr;
    }

    return 0;
}
