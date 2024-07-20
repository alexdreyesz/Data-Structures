#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node; 

void print_link(node* head) {   
    if(head == NULL) {
        printf("NULL\n\n");
        return;
    }

    printf("%d --> ", head->data);

    head = head->next;

    print_link(head);
}

void insert_head(node** head, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head; 
    *head = new_node;
}

int main() {
    node* head = NULL; 

    insert_head(&head, 5);
    insert_head(&head, 2);
    insert_head(&head, 3);
    insert_head(&head, 4);

    print_link(head);
}