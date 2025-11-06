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
    char c; printf("Left/Right of %d (l/r): ", root->data); scanf(" %c", &c);
    if(c == 'l') root->left = root->left ? insert(root->left, data) : create(data);
    else root->right = root->right ? insert(root->right, data) : create(data);
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

int search(Node* root, int key) {
    if(!root) return 0;
    if(root->data == key) return 1;
    return search(root->left, key) || search(root->right, key);
}

int main() {
    Node* root = NULL;
    int ch, n, data, key;
    while(1) {
        printf("\n1.Create 2.Inorder 3.Preorder 4.Postorder 5.Count 6.Height 7.Leafs 8.Internal 9.Search 0.Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Nodes: "); scanf("%d", &n);
                printf("Root: "); scanf("%d", &data); root = create(data);
                for(int i = 1; i < n; i++) {
                    printf("Data: "); scanf("%d", &data);
                    insert(root, data);
                }
                break;
            case 2: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 3: printf("Preorder: "); preorder(root); printf("\n"); break;
            case 4: printf("Postorder: "); postorder(root); printf("\n"); break;
            case 5: printf("Nodes: %d\n", count(root)); break;
            case 6: printf("Height: %d\n", height(root)); break;
            case 7: printf("Leafs: %d\n", leafs(root)); break;
            case 8: printf("Internal: %d\n", internal(root)); break;
            case 9: printf("Key: "); scanf("%d", &key); printf("%s\n", search(root, key) ? "Found" : "Not found"); break;
            case 0: return 0;
        }
    }
}