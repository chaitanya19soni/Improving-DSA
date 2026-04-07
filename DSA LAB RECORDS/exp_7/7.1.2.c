#include <stdio.h>
#include <stdlib.h>

// Define structure for BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search a node
int search(struct Node* root, int value) {
    if (root == NULL)
        return 0;

    if (root->data == value)
        return 1;
    else if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Find minimum value node
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        // Node with one or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, op, x;

    scanf("%d", &n);

    // Store results of search operations
    char results[100][20];
    int count = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &op, &x);

        if (op == 1) {
            root = insert(root, x);
        }
        else if (op == 2) {
            root = deleteNode(root, x);
        }
        else if (op == 3) {
            if (search(root, x))
                sprintf(results[count++], "found");
            else
                sprintf(results[count++], "not found");
        }
    }

    // Print all results after processing
    for (int i = 0; i < count; i++) {
        printf("%s\n", results[i]);
    }

    return 0;
}