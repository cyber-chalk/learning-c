#include <stdio.h>
#include <stdlib.h>
#include "lesson19_stack.h"

typedef struct Node {
	int data;
	struct node *next;
}node;

struct _stack {
	node *top;
};

// This function has already been done for you
// Read it carefully to give you an idea of how you
// might complete the rest of the implementation
stack create() {
	stack s = malloc(sizeof(struct _stack));
	if (s == NULL)
		exit(1);
	s->top = NULL;
	return s;
}

// Complete all of the functions below
void destroy(stack s) {
	empty(s);
	free(s);
}

int is_empty(stack s) {
	if (s->top == NULL) return 1;
	return 0;
}

void empty(stack s) {
	while (!is_empty(s)) pop(s);
}

void push(stack s, int num) {
	node *newNode = malloc(sizeof(node));
	newNode->next = s->top;
	newNode->data = num;
	s->top = newNode; 
}

int pop(stack s) {
    if (is_empty(s)) {
        printf("stack underflow\n");
        exit(EXIT_FAILURE);
    }

	node *topNode = s->top; // saves value
	s->top = s->top->next; // points to second element
	int poppedV = topNode->data;
	free(topNode);
	return poppedV;
}

// You can test your stack by using this main() function
int main() {
	stack s = create();
	destory(s);
	push(s, 5);

	return 0;
}