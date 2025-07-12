#include <stdio.h>
#include <stdlib.h>

// Define the structure for an n-ary tree node
typedef struct Node {
    int data;
    struct Node **children; // Array of pointers to child nodes
    int numChildren;       // Number of children this node has
} Node;

// Function to create a new n-ary tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->children = NULL; // Initialize children to NULL
    newNode->numChildren = 0;
    return newNode;
}

// Function to add a child to a parent node
void addChild(Node* parent, Node* child) {
    parent->numChildren++;
    // Reallocate memory for children array to accommodate the new child
    parent->children = (Node**)realloc(parent->children, parent->numChildren * sizeof(Node*));
    if (parent->children == NULL) {
        perror("Memory reallocation failed");
        exit(EXIT_FAILURE);
    }
    parent->children[parent->numChildren - 1] = child;
}

// Function to perform a pre-order traversal of the n-ary tree
void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data); // Visit the root
    for (int i = 0; i < root->numChildren; i++) {
        preOrderTraversal(root->children[i]); // Recursively visit children
    }
}

// Function to free the memory allocated for the tree
void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < root->numChildren; i++) {
        freeTree(root->children[i]);
    }
    free(root->children); // Free the array of child pointers
    free(root);          // Free the node itself
}

int main() {
    // Create nodes
    Node* root = createNode(1);
    Node* child2 = createNode(2);
    Node* child3 = createNode(3);
    Node* child4 = createNode(4);
    Node* child5 = createNode(5);
    Node* child6 = createNode(6);

    // Build the tree structure
    addChild(root, child2);
    addChild(root, child3);
    addChild(root, child4);
      printf("\n");

      printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    addChild(child2, child5);
    addChild(child2, child6);
  printf("\n");

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}
