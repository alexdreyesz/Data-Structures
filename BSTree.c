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
    node* root = NULL;

    int option = 0;
    int data = 0;

    printf("MENU: BSTree\n");
    printf("Option 1: Insert Node\n");
    printf("Option 2: PreOrder Traversal\n");
    printf("Option 3: Inorder Traversal\n");
    printf("Option 4: PostOrder Traversal\n");
    printf("Option 5: Stop Program\n");

    while(option != 5) {
        printf("\nSelect An Option: ");
        scanf("%d", &option);

        switch(option) {
            // Option 1: Insert Node
            case 1:
                printf("Input Node Value: ");
                scanf("%d", &data);
                root = bst_insert(root, data);
                break;
            // Option 2: PreOrder Traversal
            case 2:
                printf("\nPreOrder Traversal:\n");
                preorder_traversal(root);
                printf("NULL\n\n");
                break;
            // Option 3: Inorder Traversal
            case 3:
                printf("\nInOrder Traversal:\n");
                inorder_traversal(root);
                printf("NULL\n\n");
                break;
            // Option 4: PostOrder Traversal
            case 4:
                printf("\nPostOrder Traversal:\n");
                postorder_traversal(root);
                printf("NULL\n\n");
                break;
            // Option 5: Stop Program
            case 5:
                printf("Program Ended\n");
                break;
            // Default Wrong Input 
            default:
                printf("Wrong Input\n");
                break;
        } 
    }

    return 0;
}