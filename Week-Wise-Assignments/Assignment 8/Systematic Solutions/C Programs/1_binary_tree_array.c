#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} BinaryTree;

void initTree(BinaryTree* tree) {
    tree->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        tree->data[i] = -1; // -1 indicates empty node
    }
}

void createTree(BinaryTree* tree) {
    printf("\n=== Creating Binary Tree ===\n");
    printf("Enter number of nodes: ");
    scanf("%d", &tree->size);
    
    if (tree->size > MAX_SIZE) {
        printf("Size exceeds maximum limit!\n");
        tree->size = 0;
        return;
    }
    
    printf("Enter elements (use -1 for empty nodes):\n");
    for (int i = 0; i < tree->size; i++) {
        printf("Node %d: ", i);
        scanf("%d", &tree->data[i]);
    }
    
    printf("Tree created successfully!\n");
    printf("Array representation: ");
    for (int i = 0; i < tree->size; i++) {
        printf("%d ", tree->data[i]);
    }
    printf("\n");
}

void inorderTraversal(BinaryTree* tree, int index) {
    if (index >= tree->size || tree->data[index] == -1) {
        return;
    }
    
    inorderTraversal(tree, 2 * index + 1);  // Left child
    printf("%d ", tree->data[index]);
    inorderTraversal(tree, 2 * index + 2);  // Right child
}

void preorderTraversal(BinaryTree* tree, int index) {
    if (index >= tree->size || tree->data[index] == -1) {
        return;
    }
    
    printf("%d ", tree->data[index]);
    preorderTraversal(tree, 2 * index + 1);  // Left child
    preorderTraversal(tree, 2 * index + 2);  // Right child
}

void postorderTraversal(BinaryTree* tree, int index) {
    if (index >= tree->size || tree->data[index] == -1) {
        return;
    }
    
    postorderTraversal(tree, 2 * index + 1);  // Left child
    postorderTraversal(tree, 2 * index + 2);  // Right child
    printf("%d ", tree->data[index]);
}

int countNodes(BinaryTree* tree, int index) {
    if (index >= tree->size || tree->data[index] == -1) {
        return 0;
    }
    
    return 1 + countNodes(tree, 2 * index + 1) + countNodes(tree, 2 * index + 2);
}

int findHeight(BinaryTree* tree, int index) {
    if (index >= tree->size || tree->data[index] == -1) {
        return -1;
    }
    
    int leftHeight = findHeight(tree, 2 * index + 1);
    int rightHeight = findHeight(tree, 2 * index + 2);
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int countLeafNodes(BinaryTree* tree, int index) {
    if (index >= tree->size || tree->data[index] == -1) {
        return 0;
    }
    
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    // Check if it's a leaf node
    if ((leftChild >= tree->size || tree->data[leftChild] == -1) &&
        (rightChild >= tree->size || tree->data[rightChild] == -1)) {
        return 1;
    }
    
    return countLeafNodes(tree, leftChild) + countLeafNodes(tree, rightChild);
}

int countInternalNodes(BinaryTree* tree, int index) {
    if (index >= tree->size || tree->data[index] == -1) {
        return 0;
    }
    
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    // Check if it's an internal node
    if ((leftChild < tree->size && tree->data[leftChild] != -1) ||
        (rightChild < tree->size && tree->data[rightChild] != -1)) {
        return 1 + countInternalNodes(tree, leftChild) + countInternalNodes(tree, rightChild);
    }
    
    return 0;
}

int searchData(BinaryTree* tree, int key, int index) {
    if (index >= tree->size || tree->data[index] == -1) {
        return -1;
    }
    
    if (tree->data[index] == key) {
        return index;
    }
    
    int leftResult = searchData(tree, key, 2 * index + 1);
    if (leftResult != -1) return leftResult;
    
    return searchData(tree, key, 2 * index + 2);
}

void displayTreeStructure(BinaryTree* tree) {
    printf("\n=== Tree Structure ===\n");
    if (tree->size == 0) {
        printf("Tree is empty!\n");
        return;
    }
    
    int height = findHeight(tree, 0);
    printf("Tree Height: %d\n", height);
    
    for (int level = 0; level <= height; level++) {
        printf("Level %d: ", level);
        int start = (int)pow(2, level) - 1;
        int end = (int)pow(2, level + 1) - 2;
        
        for (int i = start; i <= end && i < tree->size; i++) {
            if (tree->data[i] != -1) {
                printf("%d ", tree->data[i]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

void treeAnalysis(BinaryTree* tree) {
    printf("\n=== Tree Analysis ===\n");
    if (tree->size == 0) {
        printf("Tree is empty!\n");
        return;
    }
    
    int totalNodes = countNodes(tree, 0);
    int leafNodes = countLeafNodes(tree, 0);
    int internalNodes = countInternalNodes(tree, 0);
    int height = findHeight(tree, 0);
    
    printf("Total Nodes: %d\n", totalNodes);
    printf("Leaf Nodes: %d\n", leafNodes);
    printf("Internal Nodes: %d\n", internalNodes);
    printf("Tree Height: %d\n", height);
    printf("Array Size Used: %d\n", tree->size);
    
    // Verify node count
    if (totalNodes == leafNodes + internalNodes) {
        printf("✓ Node count verification: PASSED\n");
    } else {
        printf("✗ Node count verification: FAILED\n");
    }
}

int main() {
    BinaryTree tree;
    initTree(&tree);
    
    printf("=== Binary Tree Implementation (Array) ===\n");
    printf("Array-based binary tree with complete functionality\n");
    printf("Array indexing: Root at 0, Left child at 2i+1, Right child at 2i+2\n\n");
    
    int choice, key, result;
    
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
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createTree(&tree);
                break;
                
            case 2:
                printf("\nInorder Traversal (Left-Root-Right): ");
                if (tree.size > 0) {
                    inorderTraversal(&tree, 0);
                    printf("\n");
                } else {
                    printf("Tree is empty!\n");
                }
                break;
                
            case 3:
                printf("\nPreorder Traversal (Root-Left-Right): ");
                if (tree.size > 0) {
                    preorderTraversal(&tree, 0);
                    printf("\n");
                } else {
                    printf("Tree is empty!\n");
                }
                break;
                
            case 4:
                printf("\nPostorder Traversal (Left-Right-Root): ");
                if (tree.size > 0) {
                    postorderTraversal(&tree, 0);
                    printf("\n");
                } else {
                    printf("Tree is empty!\n");
                }
                break;
                
            case 5:
                result = countNodes(&tree, 0);
                printf("\nTotal number of nodes: %d\n", result);
                break;
                
            case 6:
                result = findHeight(&tree, 0);
                printf("\nHeight of tree: %d\n", result);
                break;
                
            case 7:
                result = countLeafNodes(&tree, 0);
                printf("\nNumber of leaf nodes: %d\n", result);
                break;
                
            case 8:
                result = countInternalNodes(&tree, 0);
                printf("\nNumber of internal nodes: %d\n", result);
                break;
                
            case 9:
                printf("Enter data to search: ");
                scanf("%d", &key);
                result = searchData(&tree, key, 0);
                if (result != -1) {
                    printf("Data %d found at index %d\n", key, result);
                } else {
                    printf("Data %d not found in tree\n", key);
                }
                break;
                
            case 10:
                displayTreeStructure(&tree);
                break;
                
            case 11:
                treeAnalysis(&tree);
                break;
                
            case 12:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}