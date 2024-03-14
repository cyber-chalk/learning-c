#include <stdio.h>

struct _node {
  int data;
  struct _node *next;
};

typedef struct _node node;

void traverse(node *head) {
  while (head != NULL)
  {
    printf("The payload is: %d\n", head->data);
    head = head->next;
  }
  printf("\n");
}

void removeNode(node *head, int position) {
  if (head == NULL) return;

  int i = 0;
    while (head != NULL) {
      i++;
      if (i == position) break;
      // printf("The payload is: %d\n", head->data);
      head = head->next;
    }

  if (head == NULL && i > position) {printf("wamp wamp"); return;}
  head->next = head->next->next; // Skip the node to be removed
  head = NULL;
}

void insertNodeAtHead(node *head, node *ptr0) {
  ptr0->next = head;
  ptr0->data = head->data - 1;
}

void insertNode(node *original, node* newNode) {
  newNode->data = original->data + 1;
  newNode->next = NULL;
  original->next = newNode;
}
int main() {

  node node1 = {1}, node2 = {2}, node3 = {3};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    node *head = &node3; //&
    node newNode;
    node *newPoint = &newNode;

    insertNode(head, newPoint);
    traverse(head = &node1);

    node node0;
    node *ptr0 = &node0;
    head = &node1;
    insertNodeAtHead(head, ptr0);
    traverse(head = &node0);

    head = &node0;
    removeNode(head, 2);
    traverse(head = &node0);
    return 0;
}