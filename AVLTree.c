#include <stdio.h>
#include <stdlib.h>

 typedef struct node {
    int data;
    struct node* left;
    struct node* right;
 } node;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

node* bst_insert(node* root, int data) {
    if(root == NULL) {
        return create_node(data);
    }

    if(root->data == data) {
        return root;
    }

    if(data < root->data) {
        root->left = bst_insert(root->left, data);
    } else {
        root->right = bst_insert(root->right, data);
    }

    return root;
}

void preorder_traversal (node* root) {
    if(root == NULL) {
        return;
    }

    printf("%d -> ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal (node* root) {
    if(root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%d -> ", root->data);
    inorder_traversal(root->right);
}

void postorder_traversal(node* root) {
    if(root == NULL) {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d -> ", root->data);
}

int main () {

     printf("\n\n");

    node* root = NULL;
    int option;

    root = bst_insert(root, 3);
    root = bst_insert(root, 1);
    root = bst_insert(root, 2);
    root = bst_insert(root, 4);
    root = bst_insert(root, 6);

    preorder_traversal(root);
    printf("NULL\n\n");

    inorder_traversal(root);
    printf("NULL\n\n");

    postorder_traversal(root);
    printf("NULL\n\n");
    
    printf("\n\n");


    /*
    while(option != 6) {
        printf("Select An Option: ");
        scanf("%d", &option);

        switch(option) {
            // Option 1:
            case 1:
                break;

            // Option 2:
            case 2:
                break;

            // Option 3:
            case 3:
                break;

            // Default Wrong Input 
            default:
                printf("Wrong Input");
                break;
        } 
    }
    */

    return 0;
}