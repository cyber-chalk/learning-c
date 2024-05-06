#include "lesson23_tree.h"
#include <stdio.h>
#include <stdlib.h>

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findMin(Node* node) {
	int min = 0;
	while(node->left != NULL){
		min = node->data;
		node = node->left;
	}
	return min;
}

int findMax(Node* node) {
	int max = 0;
	while(node->right != NULL){
		max = node->data;
		node = node->right;
	}
	return max;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    } else if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

int findDepth(Node* node, int val) {
	if (node == NULL) return -1;
	if (node->data == val) return 1;

	if (val > node->data) {
		int rightDepth = findDepth(node->right, val);
		if (rightDepth == -1) return -1;
		return 1 + rightDepth;
	}
	if (val < node->data) {
		int	leftDepth = findDepth(node->left, val);
		if (leftDepth == -1) return -1;
		return 1 + leftDepth;
	}
	
	return -1;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
	
	Node *head = root;
	printf("%d", findDepth(head, 70));
	
	findMax(root);
	findMin(root);
	

	printf("Inorder traversal of binary search tree is: \n");
    inorderTraversal(root);
    printf("\n");
 
    return 0;
}
