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
        return 0 ;
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

    int deleted = 0;

    push(&top, 8);
    push(&top, 2);
    push(&top, 6);
    push(&top, 9);
    push(&top, 1);

    print_stack(top);

    deleted = pop(&top);
    printf("Pop: %d\n\n", deleted);

    deleted = pop(&top);
    printf("Pop: %d\n\n", deleted);

    deleted = pop(&top);
    printf("Pop: %d\n\n", deleted);

    print_stack(top);

    return 0;
}