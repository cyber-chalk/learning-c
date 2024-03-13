#include <stdio.h>

struct _node {
  int data;
  struct _node *next;
};

typedef struct _node node;


void removeNode(node *head, int position) {
  int i = 0;
    while (head != NULL) {
      if (i == position) break;
      head = head->next;
    }
    

}

void insertNode(node* original, int val) {
  // printf("%d", original);
    /*1. check if the given prev_node is NULL */
  if (original == NULL) {
    printf("nuh");
      return;
  }
 
    /* 2. allocate new node */
  node *newNode;
    /* 3. put in the data */
  newNode->data = val;
    /* 4. Make next of new node as next of prev_node */
   newNode->next = original->next;
 
    /* 5. move the next of prev_node as new_node */
  original->next = newNode;

}
int main() {

 node *node1, *node2, *node3;
    node1->data = 1;
    node2->data = 2;
    node3->data = 3;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL; // Mark the end of the list

    insertNode(node3, 4);

    node *head = node1; //&
    while (head != NULL) head = head->next;
    removeNode(head, 2);

    return 0;
}