#include <stdio.h>
#include <stdlib.h>
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

void insertNode(node *original, node* newNode, int val) {
  // printf("%d", original);  
  //printf("%d %d", newNode == NULL, newNode);
  
// newNode->data = val;
 if (newNode == NULL) {
 	printf("yes");
  //	newNode->next = NULL;
  	//original->next = newNode;
	return;
 }
//  newNode->next = original->next;
//  original->next = newNode;

}
int main() {

 node node1, node2, node3;
    node1.data = 1;
    node2.data = 2;
    node3.data = 3;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL; 

	node *newNode;
	node *head = &node1; //&
	while (head != NULL) {
  	//printf("%d", head->data);
  	head = head->next; 
  	}
  	
    insertNode(head, newNode, 4);

    
  	
  	
   //emoveNode(head, 2);

    return 0;
}
