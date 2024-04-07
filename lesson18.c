#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}node;

void traverse(node *head) {
    while (head != NULL) {
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

int main () {
    int input;
    node * current = NULL;
    node * head;
    for(;;) {
        scanf("%d\n", &input);
        if (input == 0) break;
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = input;
        newNode->next = NULL;

        if (current == NULL) {
            current = newNode;
            head = newNode;
        } else {
            current->next = newNode;
            current = newNode;
            
        }
    }
    node *temp = head;
    traverse(temp);

    int input2;
    for (;;) {
        scanf("%d", &input2);
        if (input2 == 0) break;
        node *temp = (node *)malloc(sizeof(node));
        temp->next = head;

        node *previous = temp;
        
        while(temp != NULL) {
            if (temp->data == input2) {
                previous->next = previous->next->next;
                temp->next = NULL;
                free(temp);
                free(previous);
                continue;
            }
        }
        previous = temp;
        temp = temp->next;
    }
    return 0;
}