#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* root = NULL;

// Create new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node (duplicates go to right)
struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Inorder traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Find minimum value node
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete node
struct node* deleteNode(struct node* root, int key, int *found) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key, found);
    else if (key > root->data)
        root->right = deleteNode(root->right, key, found);
    else {
        *found = 1;

        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data, found);
    }
    return root;
}

// Print menu
void menu() {
    printf("1. Insert Node\n");
    printf("2. In-Order Traversal\n");
    printf("3. Pre-Order Traversal\n");
    printf("4. Post-Order Traversal\n");
    printf("5. Delete Node\n");
    printf("6. Exit\n");
}

int main() {
    int choice, data;

    while (1) {
        menu();
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Data: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            if (root == NULL)
                printf("The tree is empty\n");
            else {
                inorder(root);
                printf("\n");
            }
            break;

        case 3:
            if (root == NULL)
                printf("The tree is empty\n");
            else {
                preorder(root);
                printf("\n");
            }
            break;

        case 4:
            if (root == NULL)
                printf("The tree is empty\n");
            else {
                postorder(root);
                printf("\n");
            }
            break;

        case 5: {
            printf("Delete: ");
            scanf("%d", &data);
            int found = 0;
            root = deleteNode(root, data, &found);
            if (!found)
                printf("Value not found\n");
            break;
        }

        case 6:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
