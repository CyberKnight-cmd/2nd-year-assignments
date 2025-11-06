#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* create(int data) {
    Node* n = malloc(sizeof(Node));
    n->data = data; n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int data) {
    if(!root) return create(data);
    if(data < root->data) root->left = insert(root->left, data);
    else if(data > root->data) root->right = insert(root->right, data);
    return root;
}

Node* findMin(Node* root) {
    while(root && root->left) root = root->left;
    return root;
}

Node* delete(Node* root, int data) {
    if(!root) return root;
    if(data < root->data) root->left = delete(root->left, data);
    else if(data > root->data) root->right = delete(root->right, data);
    else {
        if(!root->left) { Node* temp = root->right; free(root); return temp; }
        if(!root->right) { Node* temp = root->left; free(root); return temp; }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if(root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); }
}

void preorder(Node* root) {
    if(root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); }
}

void postorder(Node* root) {
    if(root) { postorder(root->left); postorder(root->right); printf("%d ", root->data); }
}

int count(Node* root) {
    return root ? 1 + count(root->left) + count(root->right) : 0;
}

int height(Node* root) {
    if(!root) return -1;
    int l = height(root->left), r = height(root->right);
    return 1 + (l > r ? l : r);
}

int leafs(Node* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return leafs(root->left) + leafs(root->right);
}

int internal(Node* root) {
    if(!root || (!root->left && !root->right)) return 0;
    return 1 + internal(root->left) + internal(root->right);
}

Node* search(Node* root, int key) {
    if(!root || root->data == key) return root;
    return key < root->data ? search(root->left, key) : search(root->right, key);
}

int isComplete(Node* root, int i, int n) {
    if(!root) return 1;
    if(i >= n) return 0;
    return isComplete(root->left, 2*i+1, n) && isComplete(root->right, 2*i+2, n);
}

int balance(Node* root) {
    return root ? height(root->left) - height(root->right) : 0;
}

Node* findMax(Node* root) {
    while(root && root->right) root = root->right;
    return root;
}

int nullCount(Node* root) {
    return root ? nullCount(root->left) + nullCount(root->right) : 1;
}

int main() {
    Node* root = NULL;
    int ch, data, n;
    while(1) {
        printf("\n1.Create 2.Insert 3.Delete 4.Search 5.Inorder 6.Preorder 7.Postorder 8.Count 9.Height 10.Leafs 11.Internal 12.Min 13.Max 14.Complete 15.Balance 16.NullCount 0.Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Nodes: "); scanf("%d", &n);
                for(int i = 0; i < n; i++) {
                    printf("Data: "); scanf("%d", &data);
                    root = insert(root, data);
                }
                break;
            case 2: printf("Data: "); scanf("%d", &data); root = insert(root, data); break;
            case 3: printf("Data: "); scanf("%d", &data); root = delete(root, data); break;
            case 4: printf("Key: "); scanf("%d", &data); printf("%s\n", search(root, data) ? "Found" : "Not found"); break;
            case 5: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 6: printf("Preorder: "); preorder(root); printf("\n"); break;
            case 7: printf("Postorder: "); postorder(root); printf("\n"); break;
            case 8: printf("Nodes: %d\n", count(root)); break;
            case 9: printf("Height: %d\n", height(root)); break;
            case 10: printf("Leafs: %d\n", leafs(root)); break;
            case 11: printf("Internal: %d\n", internal(root)); break;
            case 12: { Node* min = findMin(root); printf("Min: %s\n", min ? (printf("%d", min->data), "") : "Empty"); } break;
            case 13: { Node* max = findMax(root); printf("Max: %s\n", max ? (printf("%d", max->data), "") : "Empty"); } break;
            case 14: printf("Complete: %s\n", isComplete(root, 0, count(root)) ? "Yes" : "No"); break;
            case 15: printf("Balance: %d\n", balance(root)); break;
            case 16: printf("NULL: %d\n", nullCount(root)); break;
            case 0: return 0;
        }
    }
}