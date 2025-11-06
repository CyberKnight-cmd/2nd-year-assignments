#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        printf("Duplicate value %d not inserted\n", data);
    }
    
    return root;
}

Node* findMin(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* findMax(Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        printf("Node %d not found\n", data);
        return root;
    }
    
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node to be deleted found
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            printf("Node %d deleted\n", data);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            printf("Node %d deleted\n", data);
            return temp;
        }
        
        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        printf("Node %d deleted\n", data);
    }
    
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
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int findHeight(Node* root) {
    if (root == NULL) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countInternalNodes(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    
    if (key < root->data) {
        return search(root->left, key);
    }
    
    return search(root->right, key);
}

int isCompleteBinaryTree(Node* root, int index, int nodeCount) {
    if (root == NULL) return 1;
    
    if (index >= nodeCount) return 0;
    
    return isCompleteBinaryTree(root->left, 2 * index + 1, nodeCount) &&
           isCompleteBinaryTree(root->right, 2 * index + 2, nodeCount);
}

int balanceFactor(Node* root) {
    if (root == NULL) return 0;
    return findHeight(root->left) - findHeight(root->right);
}

int countNullPointers(Node* root) {
    if (root == NULL) return 1;
    return countNullPointers(root->left) + countNullPointers(root->right);
}

Node* createBST() {
    Node* root = NULL;
    int n, data;
    
    printf("\n=== Creating Binary Search Tree ===\n");
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number of nodes!\n");
        return NULL;
    }
    
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }
    
    printf("BST created successfully!\n");
    return root;
}

void displayTreeStructure(Node* root, int space) {
    const int COUNT = 10;
    
    if (root == NULL) return;
    
    space += COUNT;
    
    displayTreeStructure(root->right, space);
    
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    
    displayTreeStructure(root->left, space);
}

void bstAnalysis(Node* root) {
    printf("\n=== BST Analysis ===\n");
    if (root == NULL) {
        printf("BST is empty!\n");
        return;
    }
    
    int totalNodes = countNodes(root);
    int leafNodes = countLeafNodes(root);
    int internalNodes = countInternalNodes(root);
    int height = findHeight(root);
    int nullPointers = countNullPointers(root);
    
    Node* minNode = findMin(root);
    Node* maxNode = findMax(root);
    
    printf("Root Node: %d\n", root->data);
    printf("Total Nodes: %d\n", totalNodes);
    printf("Leaf Nodes: %d\n", leafNodes);
    printf("Internal Nodes: %d\n", internalNodes);
    printf("Tree Height: %d\n", height);
    printf("Minimum Value: %d\n", minNode ? minNode->data : -1);
    printf("Maximum Value: %d\n", maxNode ? maxNode->data : -1);
    printf("NULL Pointers: %d\n", nullPointers);
    printf("Root Balance Factor: %d\n", balanceFactor(root));
    
    // Check if complete binary tree
    int isComplete = isCompleteBinaryTree(root, 0, totalNodes);
    printf("Complete Binary Tree: %s\n", isComplete ? "Yes" : "No");
    
    // BST properties
    printf("\nBST Properties:\n");
    printf("• Inorder traversal gives sorted sequence\n");
    printf("• Search time complexity: O(h) where h is height\n");
    printf("• Best case height: O(log n)\n");
    printf("• Worst case height: O(n)\n");
}

void traversalComparison(Node* root) {
    printf("\n=== Traversal Comparison ===\n");
    if (root == NULL) {
        printf("BST is empty!\n");
        return;
    }
    
    printf("Inorder (Sorted):     ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Preorder (Root-L-R):  ");
    preorderTraversal(root);
    printf("\n");
    
    printf("Postorder (L-R-Root): ");
    postorderTraversal(root);
    printf("\n");
    
    printf("\nNote: Inorder traversal of BST gives elements in sorted order\n");
}

void balanceAnalysis(Node* root) {
    printf("\n=== Balance Analysis ===\n");
    if (root == NULL) {
        printf("BST is empty!\n");
        return;
    }
    
    printf("Node\tBalance Factor\n");
    printf("----\t--------------\n");
    
    // Simple balance factor display for root and immediate children
    printf("%d\t%d\n", root->data, balanceFactor(root));
    
    if (root->left) {
        printf("%d\t%d\n", root->left->data, balanceFactor(root->left));
    }
    
    if (root->right) {
        printf("%d\t%d\n", root->right->data, balanceFactor(root->right));
    }
    
    printf("\nBalance Factor = Height(Left) - Height(Right)\n");
    printf("Balanced if |Balance Factor| <= 1\n");
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
    
    printf("=== Binary Search Tree Implementation ===\n");
    printf("BST: Left subtree < Root < Right subtree\n");
    printf("Efficient searching, insertion, and deletion\n\n");
    
    int choice, data, result;
    Node* searchResult;
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Create BST\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("4. Search Data\n");
        printf("5. Inorder Traversal\n");
        printf("6. Preorder Traversal\n");
        printf("7. Postorder Traversal\n");
        printf("8. Count Nodes\n");
        printf("9. Find Height\n");
        printf("10. Count Leaf Nodes\n");
        printf("11. Count Internal Nodes\n");
        printf("12. Find Minimum\n");
        printf("13. Find Maximum\n");
        printf("14. Check Complete Binary Tree\n");
        printf("15. Balance Factor of Root\n");
        printf("16. Count NULL Pointers\n");
        printf("17. Display Tree Structure\n");
        printf("18. BST Analysis\n");
        printf("19. Traversal Comparison\n");
        printf("20. Balance Analysis\n");
        printf("21. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (root != NULL) {
                    printf("BST already exists. Freeing memory...\n");
                    freeTree(root);
                }
                root = createBST();
                break;
                
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Node %d inserted successfully\n", data);
                break;
                
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
                
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                searchResult = search(root, data);
                if (searchResult != NULL) {
                    printf("Data %d found in BST\n", data);
                } else {
                    printf("Data %d not found in BST\n", data);
                }
                break;
                
            case 5:
                printf("Inorder Traversal (Sorted): ");
                if (root != NULL) {
                    inorderTraversal(root);
                    printf("\n");
                } else {
                    printf("BST is empty!\n");
                }
                break;
                
            case 6:
                printf("Preorder Traversal: ");
                if (root != NULL) {
                    preorderTraversal(root);
                    printf("\n");
                } else {
                    printf("BST is empty!\n");
                }
                break;
                
            case 7:
                printf("Postorder Traversal: ");
                if (root != NULL) {
                    postorderTraversal(root);
                    printf("\n");
                } else {
                    printf("BST is empty!\n");
                }
                break;
                
            case 8:
                result = countNodes(root);
                printf("Total number of nodes: %d\n", result);
                break;
                
            case 9:
                result = findHeight(root);
                printf("Height of BST: %d\n", result);
                break;
                
            case 10:
                result = countLeafNodes(root);
                printf("Number of leaf nodes: %d\n", result);
                break;
                
            case 11:
                result = countInternalNodes(root);
                printf("Number of internal nodes: %d\n", result);
                break;
                
            case 12:
                searchResult = findMin(root);
                if (searchResult != NULL) {
                    printf("Minimum value: %d\n", searchResult->data);
                } else {
                    printf("BST is empty!\n");
                }
                break;
                
            case 13:
                searchResult = findMax(root);
                if (searchResult != NULL) {
                    printf("Maximum value: %d\n", searchResult->data);
                } else {
                    printf("BST is empty!\n");
                }
                break;
                
            case 14:
                result = isCompleteBinaryTree(root, 0, countNodes(root));
                printf("Complete Binary Tree: %s\n", result ? "Yes" : "No");
                break;
                
            case 15:
                result = balanceFactor(root);
                printf("Balance factor of root: %d\n", result);
                break;
                
            case 16:
                result = countNullPointers(root);
                printf("Number of NULL pointers: %d\n", result);
                break;
                
            case 17:
                printf("BST Structure (Rotated 90° clockwise):\n");
                if (root != NULL) {
                    displayTreeStructure(root, 0);
                } else {
                    printf("BST is empty!\n");
                }
                break;
                
            case 18:
                bstAnalysis(root);
                break;
                
            case 19:
                traversalComparison(root);
                break;
                
            case 20:
                balanceAnalysis(root);
                break;
                
            case 21:
                printf("Freeing memory and exiting...\n");
                freeTree(root);
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}