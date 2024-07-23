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

int deque(queue* qline) {
    if(qline->head == NULL) {
        return 0;
    }

    node* temp = qline->head;

    int value = temp->data;

    qline->head = qline->head->next;

    if (qline->head == NULL) {
        qline->tail = NULL;
    }

    free(temp);

    return value;
}

int main() {
    queue* qline = (queue*)malloc(sizeof(queue));
    qline->head = NULL;
    qline->tail = NULL; 

    int option = 0;
    int data = 0;

    printf("MENU: Queue \n");
    printf("Option 1: Enqueue \n");
    printf("Option 2: Dequeue \n");
    printf("Option 3: Print \n");
    printf("Option 4: Exit Program \n");

    while(option != 4) {

        printf("\nChoose Your Option: ");
        scanf("%d", &option);

        // Queue Menu Options 
        switch (option) {
        // Option 1: Enqueue Node
        case 1:
            printf("Insert Node Value: ");
            scanf("%d", &data);
            enqueue(qline, data);
            break;
        // Option 2: Dequeue Node
        case 2:
            printf("Dequeue %d\n", deque(qline));
            break;
        // Option 3: Print Queue
        case 3:
            print_queue(qline);
            break;
        // Option 4: Exit Program
        case 4:
            printf("Closing Program \n");
            break;
        // Default Option
        default:
            printf("Invalid Option \n");
            break;
        }
    }
}