#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insertBST(struct Node* root, int val) {
    if (root == NULL) return newNode(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// Search in BST
int searchBST(struct Node* root, int key) {
    if (root == NULL) return 0;

    if (root->data == key) return 1;

    if (key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

// Main function
int main() {
    int n, x, key;
    struct Node* root = NULL;

    scanf("%d", &n);

    // Build BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insertBST(root, x);
    }

    scanf("%d", &key);

    if (searchBST(root, key))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}
