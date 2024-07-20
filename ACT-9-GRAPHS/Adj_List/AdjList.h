#ifndef AdjList
#define AdjList

#define SIZE 4 // Adjust this value for the desired number of vertices

// Structure for the node with vertex
typedef struct node {
	int V; // Vertex value
	struct node* next;
}*nodeType;
	 
typedef struct graph{
	int numOfVertices; // Number of Vertices
	int numOfEdges; // Number of Edges
	nodeType nodes[SIZE]; // Array of Linked-List (Adjacency List)
}GRAPH;

/* Main Functions */
GRAPH* initGraph(void); // Initializes Graph
nodeType createNode(int vertix); // Creates a new node for graphs
void addEdge(GRAPH* G, int i, int j); // i = original vertice, j = destination vertice

/* Utility Functions */
void printGraph(GRAPH G);

#endif
