#ifndef BST
#define BST
#define EMPTY "EMPTY"

typedef struct {
	int month;
	int day;
	int year;
}Date;

typedef struct {
	char prodName[20]; // Basis for deletion and insertion; use strcmp
	float prodPrice;
	int prodQty;
	Date expDate;
}Product;

typedef struct node {
	Product item;
	struct node* left;
	struct node* right;
}NodeType, *NodePtr;

NodePtr initTree(void);
void addElement(NodePtr* T, Product prod[]);
void deleteElement(NodePtr* T, Product prod);

// DFS
void preOrder(NodePtr T);
void inOrder(NodePtr T);
void postOrder(NodePtr T);


#endif
