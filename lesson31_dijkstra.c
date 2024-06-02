#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "lesson31_pqueue.h"

// Structure to represent a graph node
typedef struct _Node {
    int dest;
    int weight;
    struct _Node* next;
} Node;

// Structure to represent a graph
typedef struct _Graph {
    int V; // Number of vertices
    Node **adjList;
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

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
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

// Function to implement Dijkstra's algorithm using priority queue
void dijkstra(Graph* graph, int src) {
    int V = graph->V;  // Number of vertices in the graph
    int dist[V];  // Array to store the shortest distance from src to each vertex
    bool visited[V];  // Array to track visited vertices

    // Initialize distances to all vertices as infinite and visited[] as false
    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;  // Distance from source to itself is always 0

    // Create a priority queue (min-heap) to store vertices that are being preprocessed
    PriorityQueue* pq = create();

    // Enqueue the source vertex
    enqueue(pq, src);

    // Loop until the priority queue is empty
    while (!is_empty(pq)) {
        // Dequeue the vertex with the minimum distance value
        int u = dequeue(pq);
        visited[u] = true;  // Mark the dequeued vertex as visited

        // Get all adjacent vertices of the dequeued vertex u
        Node* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->dest;  // Adjacent vertex
            int weight = temp->weight;  // Weight of the edge (u, v)

            // If vertex v is not visited and there is a shorter path to v through u
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;  // Update the distance to v
                enqueue(pq, v);  // Enqueue v
            }
            temp = temp->next;  // Move to the next adjacent vertex
        }
    }

    // Print the shortest distances from the source to all vertices
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
    destroy(pq);  // Clean up the priority queue
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

    dijkstra(graph, 0);

    destroyGraph(graph);

    return 0;
}