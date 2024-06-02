#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdbool.h>

/* NOTE: This is not the same header shared in Lesson 30.
/* The key difference is the payload type here is of type int (not string)
*/

// Define the structure for a priority queue element (node)
typedef struct _PQNode {
    int data;            // Pointer to the string data
    struct _PQNode *next;   // Pointer to the next node in the linked list
} PQNode;

// Define the structure for the priority queue
typedef struct _PriorityQueue {
    PQNode *head;          // Pointer to the head of the linked list
    int size;              // Current size of the priority queue
} PriorityQueue;

// Function prototypes

// Create a priority queue
PriorityQueue* create(void);

// Destroy the priority queue
void destroy(PriorityQueue *pq);

// Insert a string element into the priority queue in alphabetical order
void enqueue(PriorityQueue *pq, int data);

// Remove and return the lexicographically smallest string element from the priority queue
int dequeue(PriorityQueue *pq);

// Peek at the lexicographically smallest string element without removing it
int peek(PriorityQueue *pq);

// Check if the priority queue is empty
bool is_empty(PriorityQueue *pq);

// Get the current size of the priority queue
int size(PriorityQueue *pq);

#endif // PRIORITY_QUEUE_H