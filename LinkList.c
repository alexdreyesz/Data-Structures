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

void insert_tail(node** head, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    node* temp = *head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = new_node; 
}

void delete_head(node** head) {
    if(*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node* temp = *head;

    *head = temp->next;

    free(temp);
}

void delete_tail(node** head) {
    if(*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    
    node* temp = *head;
    node* temp2 = *head;
    
    while (temp->next != NULL) {
        temp2 = temp;
        temp = temp->next;
    }

    temp2->next = NULL;

    free(temp);
}

int main() {
    node* head = NULL; 

    insert_head(&head, 5);
    insert_head(&head, 2);
    insert_head(&head, 3);
    insert_head(&head, 4);

    insert_tail(&head, 10);
    insert_tail(&head, 2);
    insert_tail(&head, 4);

    delete_tail(&head);
    delete_head(&head);

    print_link(head);
}