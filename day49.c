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
    if (root == NULL) {
        return newNode(val);
    }

    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

// Level Order Traversal (Queue using array)
void levelOrder(struct Node* root) {
    if (!root) return;

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
}

// Example main
int main() {
    // Example BST: 4 2 7 1 3
    struct Node* root = NULL;
    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 1);
    insertBST(root, 3);

    int val = 5;
    insertBST(root, val);

    levelOrder(root);

    return 0;
}
