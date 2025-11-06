#include <stdio.h>
#define MAX 100

int tree[MAX], size = 0;

void create() {
    printf("Enter size: "); scanf("%d", &size);
    printf("Enter elements: ");
    for(int i = 0; i < size; i++) scanf("%d", &tree[i]);
}

void inorder(int i) {
    if(i < size && tree[i] != -1) {
        inorder(2*i+1);
        printf("%d ", tree[i]);
        inorder(2*i+2);
    }
}

void preorder(int i) {
    if(i < size && tree[i] != -1) {
        printf("%d ", tree[i]);
        preorder(2*i+1);
        preorder(2*i+2);
    }
}

void postorder(int i) {
    if(i < size && tree[i] != -1) {
        postorder(2*i+1);
        postorder(2*i+2);
        printf("%d ", tree[i]);
    }
}

int count(int i) {
    return (i >= size || tree[i] == -1) ? 0 : 1 + count(2*i+1) + count(2*i+2);
}

int height(int i) {
    if(i >= size || tree[i] == -1) return -1;
    int l = height(2*i+1), r = height(2*i+2);
    return 1 + (l > r ? l : r);
}

int leafs(int i) {
    if(i >= size || tree[i] == -1) return 0;
    if((2*i+1 >= size || tree[2*i+1] == -1) && (2*i+2 >= size || tree[2*i+2] == -1)) return 1;
    return leafs(2*i+1) + leafs(2*i+2);
}

int internal(int i) {
    if(i >= size || tree[i] == -1) return 0;
    if((2*i+1 < size && tree[2*i+1] != -1) || (2*i+2 < size && tree[2*i+2] != -1))
        return 1 + internal(2*i+1) + internal(2*i+2);
    return 0;
}

int search(int key, int i) {
    if(i >= size || tree[i] == -1) return 0;
    if(tree[i] == key) return 1;
    return search(key, 2*i+1) || search(key, 2*i+2);
}

int main() {
    int ch, key;
    while(1) {
        printf("\n1.Create 2.Inorder 3.Preorder 4.Postorder 5.Count 6.Height 7.Leafs 8.Internal 9.Search 0.Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: create(); break;
            case 2: printf("Inorder: "); inorder(0); printf("\n"); break;
            case 3: printf("Preorder: "); preorder(0); printf("\n"); break;
            case 4: printf("Postorder: "); postorder(0); printf("\n"); break;
            case 5: printf("Nodes: %d\n", count(0)); break;
            case 6: printf("Height: %d\n", height(0)); break;
            case 7: printf("Leafs: %d\n", leafs(0)); break;
            case 8: printf("Internal: %d\n", internal(0)); break;
            case 9: printf("Key: "); scanf("%d", &key); printf("%s\n", search(key, 0) ? "Found" : "Not found"); break;
            case 0: return 0;
        }
    }
}