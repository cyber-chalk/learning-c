#include <stdio.h>

struct node {
  int data;
  struct node *next;
};


void insertNode(struct node original, int val) {
  struct node newNode;
  newNode.data = val;
  newNode.next = NULL;

  original->next = &newNode;
}
int main() {

struct node node1, node2, node3;
    node1.data = 1;
    node2.data = 2;
    node3.data = 3;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL; // Mark the end of the list

    insertNode(node3, 4);
    return 0;
}