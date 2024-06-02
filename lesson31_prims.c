#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "lesson31_pqueue.h"

/* Hints:
     * 0. How to compile this program:
     *    i) Download lesson31_pqueue.h, lessone31_pqueue.o and
     *    lesson31_prims.c to the same directory
     *    ii) Execute: 'gcc lesson31_pqueue.o lesson31_prims.c -o l31'
     *    iii) Execute: l31
     *
     *    You will see no output. Implement this missing function so that the
     *    edges of the MST are printed. (Watch the demonstration in class).
     *
     * 1. Read the provided source for Dijkstra's algorithm
     *    The code for this function may look very similar
     *
     * 2. Read the lesson notes and be sure to understand
     *    what each algorithm is designed to achieve
     */

// Structure to represent a graph node
typedef struct Node {
    int dest;
    int weight;
    struct Node* next; // Pointer to the next adjacent node
} Node;

// Structure to represent a graph
typedef struct {
    int V; // Number of vertices
    Node** adjList; // Array of adjacency lists
} Graph;

// Function to create a new graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; ++i)
        graph->adjList[i] = NULL;
    return graph;
}

// Function to add an undirected edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    // Add an edge from src to dest
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add an edge from dest to src
    newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = src;
    newNode->weight = weight;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to free the memory allocated to the graph
void destroyGraph(Graph* graph) {
    for (int i = 0; i < graph->V; ++i) {
        Node* temp = graph->adjList[i];
        while (temp != NULL) {
            Node* prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(graph->adjList);
    free(graph);
}

/*
1. pick a arbitrary node to start on and mark it as visited and add adjacent nodes to the priority queue
2. get smallest weight from the pq and add its adjacent nodes to the pq that have not been visited (also mark it as visited)
3. repeat until no nodes left
*/


void primMST(Graph* graph) {
    int V = graph->V;
    int* visited = calloc(V, sizeof(int));

    PriorityQueue* pq = create();
    enqueue(pq, 0); // idk might need to change

    while(!is_empty(pq)) {
        int current = dequeue(pq);
        visited[current] = 1;

        Node* temp = graph->adjList[current];
        while(temp != NULL) {
            //add adjacent nodes to the pq that have not yet been visited
            if (!visited[temp->dest]) enqueue(pq, temp->dest);
            temp = temp->next;  // Move to the next adjacent vertex
        }
    }
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; ++i) {
        printf("%d \t%d\n", i, graph->adjList[i]->weight);
    }
}


int main() {
    int V = 9;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    primMST(graph);

    destroyGraph(graph);

    return 0;
}