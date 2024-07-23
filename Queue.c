#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next; 
} node;

typedef struct queue {
    struct node *head;
    struct node *tail;
} queue;

void print_queue(queue* qline) {
    if (qline->head == NULL) {
        printf("NULL\n\n");
        return;
    }
    
    node* current = qline->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n\n");
}

void enqueue(queue* qline, int data) {
    
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    
    if(qline->head == NULL) {
        qline->head = new_node;
        qline->tail = new_node;
        return;
    }

    qline->tail->next = new_node;
    qline->tail = new_node;
}

void deque(queue* qline, int data) {
    
}

int main() {

    queue* qline = (queue*)malloc(sizeof(queue));

    qline->head = NULL;
    qline->tail = NULL; 

    printf("\n");

    enqueue(qline, 3);
    enqueue(qline, 1);
    enqueue(qline, 7);

    print_queue(qline);
}