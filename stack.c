#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

typedef struct stack{
    struct node* top;
    struct node* bottom;
} stack;

void print_stack(stack* line) {
    if(line->bottom == NULL) {
        printf("NULL\n\n");
        return;
    }
    
    node* current = line->bottom;

    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n\n");
}

void push(stack* line, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if(line->bottom == NULL) {
        line->top = new_node;
        line->bottom = new_node;
        return;
    }

    line->top->next = new_node;
    line->top = new_node;
}

int pop(stack* line) {
    if(line->top == NULL) {
        return 0 ;
    }

    node* temp = line->top;

    line->top = line->top->next;

    free(temp);
}

void peek() {

}

int main() {

    stack* line = (stack*)malloc(sizeof(stack));
    line->top = NULL;
    line->bottom = NULL;

    int deleted = 0;

    push(line, 8);
    push(line, 2);
    push(line, 6);
    push(line, 9);
    push(line, 1);

    deleted = pop(line);
    printf("Pop: %d", deleted);

    deleted = pop(line);
    printf("Pop: %d", deleted);

    deleted = pop(line);
    printf("Pop: %d", deleted);

    print_stack(line);

    return 0;
}