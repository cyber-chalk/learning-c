#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

void removeNode(node *head) {
  if (head == NULL) return;
  node *current = head;

  while (current != NULL && current->next != NULL) {
    node *runner = current;
    while(runner->next != NULL)
      if (runner->next->data == current->data)
        runner->next = runner->next->next;
      else
        runner = runner->next;
    current = current->next;
  }
}
int main() {
  node node1 = {1}, node2 = {2}, node2d = {2}, node3 = {3};
  node1.next = &node2;
  node2d.next = &node3;
  node2.next = &node3;
  node3.next = NULL;

  node *head = &node1; //&
  removeNode(head);
  head = &node1;
  while(head != NULL) {
    printf("%d", head->data);
    head = head->next;
  }
  return 0;
    }