#include <stdio.h>
#include <stdlib.h>

// Define the structure for the adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Define the structure for the adjacency list
struct AdjList {
    struct Node* head;
};

// Define the structure for the graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};


typedef struct qNode_ {
    struct Node* vertex;
    struct qNode_* next;
}qNode;

typedef struct queue_ {
    qNode* front;
    qNode* rear;
}queue;


void enqueue(queue* q, struct Node* node) { 
    qNode* newNode = malloc(sizeof(qNode));
    newNode->vertex = node;
    newNode->next = NULL;
    if (q->rear != NULL) q->rear->next = newNode;
    q->rear = newNode;
    if (q->front == NULL) q->front = newNode;
}


queue* createQueue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

int deQueue(queue* q) {
    if (q->front == NULL) return;
    // Store previous front and move front one node ahead
    qNode* temp = q->front;
    int value = temp->vertex;
    q->front = q->front->next;
    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return value;
}

// Create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with numVertices vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));

    for (int i = 0; i < numVertices; i++)
        graph->array[i].head = NULL;

    return graph;
}

// Add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; ++v) {
        struct Node* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->vertex);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}


int* qvisited;
// BFS traversal method to be completed by students
void BFS(struct Graph* graph, int startVertex) {
    queue* q = createQueue();
    qvisited[startVertex] = 1;
    enqueue(q, graph->array[startVertex].head);

    while(q->front != NULL) {
        startVertex = deQueue(q);

        struct Node* temp = graph->array[startVertex].head;

        while (temp) {
            int adjVertex = temp->vertex;

            if (qvisited[adjVertex] == 0) {
            qvisited[adjVertex] = 1;
            enqueue(q, adjVertex);
        }
        temp = temp->next;
        }
    }

}

// DFS traversal method to be completed by students
int* visited;

void DFS(struct Graph* graph, int startVertex) {
    visited[startVertex] = 1;

    struct Node* currentNode = graph->array[startVertex].head;
    while (currentNode) {
        int adjacentVertex = currentNode->vertex;

        if (!visited[adjacentVertex]) {
            DFS(graph, adjacentVertex);
        }
        currentNode = currentNode->next;
    }
}

int main() {
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    visited = (int*)calloc(numVertices, sizeof(int));
    // Call BFS and DFS methods (students will implement these)
    
    DFS(graph, 0);
    free(visited);
    qvisited = (int*)calloc(numVertices, sizeof(int));
    BFS(graph, 0);
    free(qvisited);

    return 0;
}