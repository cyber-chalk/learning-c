#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lesson30.h"


// 3 methods have been left unimplemented as an exercise for the student!
// Make sure to read the header file and use it as a guide.

// Create a priority queue
PriorityQueue* pq_create(void) {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (pq == NULL) {
        return NULL; // Memory allocation failed
    }
    pq->head = NULL;
    pq->size = 0;
    return pq;
}

// Destroy the priority queue
void pq_destroy(PriorityQueue *pq) {
    if (pq == NULL) {
        return;
    }
    PQNode *current = pq->head;
    while (current != NULL) {
        PQNode *temp = current;
        current = current->next;
        free(temp->data); // Free the string data
        free(temp);       // Free the node
    }
    free(pq); // Free the priority queue structure
}

// Peek at the lexicographically smallest string element without removing it
const char* pq_peek(PriorityQueue *pq) {
    if (pq == NULL || pq->head == NULL) {
        return NULL; // Queue is empty or not initialized
    }
    return pq->head->data;
}

// Check if the priority queue is empty
bool pq_is_empty(PriorityQueue *pq) {
    return (pq == NULL || pq->size == 0);
}


// The following functions are left as an exercise for the student:
bool pq_insert(PriorityQueue *pq, const char *data) {
    PQNode* newNode = malloc(sizeof(PQNode));
    newNode->data = (char*) data;
    newNode->next = NULL; // prevent memory leaks

    if (pq->head = NULL) {
        pq->head = newNode;
        return true;
    }

    PQNode* current = pq->head;
    PQNode* previous = NULL;

    while (current != NULL) {
        if (strcmp(data, current->data) <= 0) {
            previous->next = newNode; 
            newNode->next = current;
            return true;
        }
        current = current->next;
    }
    return false;
}


char* pq_remove(PriorityQueue *pq) {
     if (pq->head == NULL) {
        return NULL;
    }
    PQNode *temp = pq->head;
    PQNode *tData = pq->head->data;
    pq->head = pq->head->next;
    free(temp);
    return tData;
}

int pq_size(PriorityQueue *pq) {
    int size = 0;
    PQNode* current = pq->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

int main() {
    // Example usage of the implemented functions
    PriorityQueue *pq = pq_create();
    if (pq == NULL) {
        fprintf(stderr, "Failed to create priority queue\n");
        return 1;
    }

    printf("Priority queue is empty: %s\n", pq_is_empty(pq) ? "true" : "false");

    // Example clean up
    pq_destroy(pq);
    return 0;
}