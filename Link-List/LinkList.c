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

// Delete Link List And Free It
void free_link(node** head) {
    if(*head == NULL) {
        return;
    }
    
    node* temp = NULL;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Delete Link List Node By Value 
void delete_node_by_value(node** head, int data) { 
    if(*head == NULL) {
        return;
    }

    node* temp1 = *head;
    node* temp2 = *head;

    while (temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;

        if(temp1->data == data) {
            break;
        } 
    }

    temp2->next = temp1->next;
    free(temp1);
}

// Reverse Link List
void reverse_link (node** head) {
    node* temp = *head;
    node* tail = *head;

    while(tail->next != NULL) {
        tail = tail->next;
    }

    node* tail2 = tail;

    while(temp != tail) {
        tail2->next = temp;
        temp = temp->next;
        tail2->next = temp;
    }


}

int main() {
    node* head = NULL; 

    int option = 0;
    int data = 0;

    // Menu Text
    printf("MENU: Link List \n");
    printf("Option 1: Insert Head \n");
    printf("Option 2: Insert Tail \n");
    printf("Option 3: Delete Head \n");
    printf("Option 4: Delete Tail \n");
    printf("Option 5: Delete By Value \n");
    printf("Option 6: Free Link List \n");
    printf("Option 7: Print \n");
    printf("Option 8: Stop Program \n");

    // Menu Options
    while(option != 8) {

        printf("\nChoose Your Option: ");
        scanf("%d", &option);

        // Link List Menu Options 
        switch (option)
        {
        case 1: // Option 1: Insert Head Link List
            printf("Insert Node Value: ");
            scanf("%d", &data);
            insert_head(&head, data);
            break;
        case 2: // Option 2: Insert Tail Link List
            printf("Insert Node Value: ");
            scanf("%d", &data);
            insert_tail(&head, data);
            break;
        case 3: // Option 3: Delete Head Link List
            delete_head(&head);
            break;
        case 4: // Option 4: Delete Tail Link List
            delete_tail(&head);
            break;
        case 5: // Option 5: Delete By Value
            printf("Delete By Value: ");
            scanf("%d", &data);
            delete_node_by_value(&head, data);
            break;
        case 6: // Option 6: Free Link List
            printf("Linked List Deleted\n");
            free_link(&head);
            break;
        case 7: // Option 7: Print Link List 
            print_link(head);
            break;
        case 8: // Option 8: Stop Program
            printf("Closing Link List Program \n");
            break;
        default: // Default Option
            printf("Invalid Option \n");
            break;
        }
    }

    return 0;
}