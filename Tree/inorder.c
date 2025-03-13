#include <stdio.h>
#include <stdlib.h>
// INORDER IS IN NOT FOLLOW ASCENDING ORDER BUT IT FOLLOW ASCENDING ORDER IN BST TREE

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* Create(int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = ptr->right = NULL;
    return ptr;
}

// Preorder traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data); // Visit root
    preorderTraversal(root->left); // Traverse left subtree
    preorderTraversal(root->right); // Traverse right subtree
}

// Inorder traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left); // Traverse left subtree
    printf("%d ", root->data); // Visit root
    inorderTraversal(root->right); // Traverse right subtree
}

// Postorder traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left); // Traverse left subtree
    postorderTraversal(root->right); // Traverse right subtree
    printf("%d ", root->data); // Visit root
}

int main() {
    // Create a sample binary tree
    struct Node* root = Create(1);
    root->left = Create(2);
    root->right = Create(3);
    root->left->left = Create(4);
    root->left->right = Create(5);
    root->right->left = Create(6);
    root->right->right = Create(7);

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Free the allocated memory (important for larger trees)
    // Add code to free all nodes in the tree.
    free(root->right->right);
    free(root->right->left);
    free(root->left->right);
    free(root->left->left);
    free(root->right);
    free(root->left);
    free(root);
    return 0;
}