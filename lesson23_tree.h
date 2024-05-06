#ifndef STACK_H
#define STACK_H

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Tree structure
typedef struct {
    Node* root;
} Tree;

// Function declarations
Node* insert(Node* node, int data);
void inorderTraversal(Node* node);

// The number of methods for this tree
// is kept low to keep this demonstration simple.

#endif /* TREE_H */

