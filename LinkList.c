#include <stdio.h>
#include <stdlib.h>

// Link List Struct
typedef struct node {
    int data;
    struct node* next;
} node; 

// Print Link List
void print_link(node* head) {   
    if(head == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d --> ", head->data);

    head = head->next;

    print_link(head);
}

// Insert Link List Node To The Head
void insert_head(node** head, int data) {
    node* new_node = (node*)malloc(sizeof(node));

    new_node->data = data;
    new_node->next = *head; 

    *head = new_node;
}

// Insert Link List Node To The Tail
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

// Delete Link List Node From Head
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

// Delete Link List Node From Tail
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

    int option = 0;
    int data = 0;

    printf("MENU: Link List \n");
    printf("Option 1: Insert Head \n");
    printf("Option 2: Insert Tail \n");
    printf("Option 3: Delete Head \n");
    printf("Option 4: Delete Tail \n");
    printf("Option 5: Print \n");
    printf("Option 6: Stop Program \n");

    while(option != 6) {

        printf("\nChoose Your Option: ");
        scanf("%d", &option);

        // Link List Menu Options 
        switch (option)
        {
        // Option 1: Insert Head Link List
        case 1:
            printf("Insert Node Value: ");
            scanf("%d", &data);
            insert_head(&head, data);
            break;
        // Option 2: Insert Tail Link List
        case 2:
            printf("Insert Node Value: ");
            scanf("%d", &data);
            insert_tail(&head, data);
            break;
        // Option 3: Delete Head Link List
        case 3:
            delete_head(&head);
            break;
        // Option 4: Delete Tail Link List
        case 4:
            delete_tail(&head);
            break;
        // Option 5: Print Link List 
        case 5:
            print_link(head);
            break;
        // Option 6: Stop Program
        case 6:
            printf("Closing Link List Program \n");
            break;
        // Default Option
        default:
            printf("Invalid Option \n");
            break;
        }
    }

    return 0;
}