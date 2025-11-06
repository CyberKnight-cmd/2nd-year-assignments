#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    char choice;
    printf("Insert %d to the left or right of %d? (l/r): ", data, root->data);
    scanf(" %c", &choice);
    
    if (choice == 'l' || choice == 'L') {
        if (root->left == NULL) {
            root->left = createNode(data);
            printf("Node %d inserted to the left of %d\n", data, root->data);
        } else {
            printf("Left child already exists. Inserting recursively...\n");
            root->left = insertNode(root->left, data);
        }
    } else if (choice == 'r' || choice == 'R') {
        if (root->right == NULL) {
            root->right = createNode(data);
            printf("Node %d inserted to the right of %d\n", data, root->data);
        } else {
            printf("Right child already exists. Inserting recursively...\n");
            root->right = insertNode(root->right, data);
        }
    } else {
        printf("Invalid choice! Node not inserted.\n");
    }
    
    return root;
}

Node* createTree() {
    Node* root = NULL;
    int n, data;
    
    printf("\n=== Creating Binary Tree ===\n");
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number of nodes!\n");
        return NULL;
    }
    
    printf("Enter root node data: ");
    scanf("%d", &data);
    root = createNode(data);
    printf("Root node %d created\n", data);
    
    for (int i = 1; i < n; i++) {
        printf("\nEnter data for node %d: ", i + 1);
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    
    printf("\nBinary tree created successfully!\n");
    return root;
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int findHeight(Node* root) {
    if (root == NULL) {
        return -1;
    }
    
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int countLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countInternalNodes(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

Node* searchData(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->data == key) {
        return root;
    }
    
    Node* leftResult = searchData(root->left, key);
    if (leftResult != NULL) {
        return leftResult;
    }
    
    return searchData(root->right, key);
}

void displayTreeStructure(Node* root, int space) {
    const int COUNT = 10;
    
    if (root == NULL) {
        return;
    }
    
    space += COUNT;
    
    displayTreeStructure(root->right, space);
    
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    
    displayTreeStructure(root->left, space);
}

void treeAnalysis(Node* root) {
    printf("\n=== Tree Analysis ===\n");
    if (root == NULL) {
        printf("Tree is empty!\n");
        return;
    }
    
    int totalNodes = countNodes(root);
    int leafNodes = countLeafNodes(root);
    int internalNodes = countInternalNodes(root);
    int height = findHeight(root);
    
    printf("Root Node: %d\n", root->data);
    printf("Total Nodes: %d\n", totalNodes);
    printf("Leaf Nodes: %d\n", leafNodes);
    printf("Internal Nodes: %d\n", internalNodes);
    printf("Tree Height: %d\n", height);
    
    // Tree properties
    printf("\nTree Properties:\n");
    printf("• Maximum nodes at height %d: %d\n", height, (1 << (height + 1)) - 1);
    printf("• Minimum height for %d nodes: %d\n", totalNodes, (int)(log2(totalNodes)));
    
    // Verify node count
    if (totalNodes == leafNodes + internalNodes) {
        printf("✓ Node count verification: PASSED\n");
    } else {
        printf("✗ Node count verification: FAILED\n");
    }
}

void traversalComparison(Node* root) {
    printf("\n=== Traversal Comparison ===\n");
    if (root == NULL) {
        printf("Tree is empty!\n");
        return;
    }
    
    printf("Inorder (Left-Root-Right):   ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Preorder (Root-Left-Right):  ");
    preorderTraversal(root);
    printf("\n");
    
    printf("Postorder (Left-Right-Root): ");
    postorderTraversal(root);
    printf("\n");
    
    printf("\nTraversal Uses:\n");
    printf("• Inorder: Binary Search Trees (gives sorted order)\n");
    printf("• Preorder: Tree copying, expression trees\n");
    printf("• Postorder: Tree deletion, calculating directory sizes\n");
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    
    printf("=== Binary Tree Implementation (Linked List) ===\n");
    printf("Dynamic binary tree with pointer-based structure\n");
    printf("Memory efficient with flexible node insertion\n\n");
    
    int choice, key;
    Node* searchResult;
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Create Binary Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Count Nodes\n");
        printf("6. Find Height\n");
        printf("7. Count Leaf Nodes\n");
        printf("8. Count Internal Nodes\n");
        printf("9. Search Data\n");
        printf("10. Display Tree Structure\n");
        printf("11. Tree Analysis\n");
        printf("12. Traversal Comparison\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (root != NULL) {
                    printf("Tree already exists. Freeing memory...\n");
                    freeTree(root);
                }
                root = createTree();
                break;
                
            case 2:
                printf("\nInorder Traversal (Left-Root-Right): ");
                if (root != NULL) {
                    inorderTraversal(root);
                    printf("\n");
                } else {
                    printf("Tree is empty!\n");
                }
                break;
                
            case 3:
                printf("\nPreorder Traversal (Root-Left-Right): ");
                if (root != NULL) {
                    preorderTraversal(root);
                    printf("\n");
                } else {
                    printf("Tree is empty!\n");
                }
                break;
                
            case 4:
                printf("\nPostorder Traversal (Left-Right-Root): ");
                if (root != NULL) {
                    postorderTraversal(root);
                    printf("\n");
                } else {
                    printf("Tree is empty!\n");
                }
                break;
                
            case 5:
                printf("\nTotal number of nodes: %d\n", countNodes(root));
                break;
                
            case 6:
                printf("\nHeight of tree: %d\n", findHeight(root));
                break;
                
            case 7:
                printf("\nNumber of leaf nodes: %d\n", countLeafNodes(root));
                break;
                
            case 8:
                printf("\nNumber of internal nodes: %d\n", countInternalNodes(root));
                break;
                
            case 9:
                printf("Enter data to search: ");
                scanf("%d", &key);
                searchResult = searchData(root, key);
                if (searchResult != NULL) {
                    printf("Data %d found in tree\n", key);
                    printf("Node address: %p\n", (void*)searchResult);
                } else {
                    printf("Data %d not found in tree\n", key);
                }
                break;
                
            case 10:
                printf("\nTree Structure (Rotated 90° clockwise):\n");
                if (root != NULL) {
                    displayTreeStructure(root, 0);
                } else {
                    printf("Tree is empty!\n");
                }
                break;
                
            case 11:
                treeAnalysis(root);
                break;
                
            case 12:
                traversalComparison(root);
                break;
                
            case 13:
                printf("Freeing memory and exiting...\n");
                freeTree(root);
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}