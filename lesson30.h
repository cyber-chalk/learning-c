#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdbool.h>

/* The Priority Queue Abstract Data Type (ADT):
   A priority queue is a specialized data structure that manages a set of elements
   such that the element with the highest priority is always at the front. In this
   implementation, the priority queue is ordered based on the lexicographical order
   of string elements, meaning that the lexicographically smallest string is considered
   the highest priority. This ADT is used to efficiently manage and retrieve elements
   based on their priority, which is useful in scenarios like task scheduling,
   pathfinding algorithms, and simulations where processing elements in a specific
   priority order is required.
*/

/* Definition of lexicographical order:
   Lexicographical order is a generalization of the way words are alphabetically ordered in dictionaries.
   It is based on the alphabetical order of the individual characters. For example, "apple" comes before "banana"
   because 'a' < 'b', and "apple" comes before "applicable" because 'l' < 'i'.
*/

// Define the structure for a priority queue element (node)
typedef struct PQNode {
    char *data;            // Pointer to the string data
    struct PQNode *next;   // Pointer to the next node in the linked list
} PQNode;

// Define the structure for the priority queue
typedef struct {
    PQNode *head;          // Pointer to the head of the linked list
    int size;              // Current size of the priority queue
} PriorityQueue;

// Function prototypes

// Create a priority queue
PriorityQueue* pq_create(void);

// Destroy the priority queue
void pq_destroy(PriorityQueue *pq);

// Insert a string element into the priority queue in alphabetical order
bool pq_insert(PriorityQueue *pq, const char *data);

// Remove and return the lexicographically smallest string element from the priority queue
char* pq_remove(PriorityQueue *pq);

// Peek at the lexicographically smallest string element without removing it
const char* pq_peek(PriorityQueue *pq);

// Check if the priority queue is empty
bool pq_is_empty(PriorityQueue *pq);

// Get the current size of the priority queue
int pq_size(PriorityQueue *pq);

#endif // PRIORITY_QUEUE_H