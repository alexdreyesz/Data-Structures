#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

void print_stack(node* top) {
    if(top == NULL) {
        printf("NULL\n\n");
        return;
    }

    while(top->next != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }

    printf("NULL\n\n");
}

void push(node** top, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;

    if(*top == NULL) {
        *top = new_node;
    } 

    new_node->next = *top;
    *top = new_node;
}

int pop(node** top) {
    if(top == NULL) {
        return 0;
    }

    int value = (*top)->data;

    node* temp = *top;

    *top = (*top)->next;

    free(temp);

    return value;
}

void peek() {

}

int main() {
    node* top = (node*)malloc(sizeof(node));

    int option = 0;
    int data = 0;
    int deleted = 0;

    printf("MENU: Stack \n");
    printf("Option 1: Push \n");
    printf("Option 2: Pop \n");
    printf("Option 3: Peek \n");
    printf("Option 4: Print \n");
    printf("Option 5: Exit Program \n");

    while(option != 5) {
        printf("\nChoose Your Option: ");
        scanf("%d", &option);

        // Stack Menu Options 
        switch (option) {
        case 1: // Option 1: Push Node
            printf("Insert Node Value: ");
            scanf("%d", &data);
            push(&top, data);
            break;
        case 2: // Option 2: Pop Node
            deleted = pop(&top);
            printf("Pop: %d\n", deleted);
            break;
        case 3: // Option 3: Peek Node
            printf("Peek: ");
            break;
        case 4: // Option 4: Print Stack
            print_stack(top);
            break;
        case 5: // Option 4: Exit Program
            printf("Closing Program \n");
            break;
        default: // Default Option
            printf("Invalid Option \n");
            break;
        }
    }

    return 0;
}