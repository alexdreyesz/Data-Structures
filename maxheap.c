#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *array;
    int size;
    int capacity;
} Heap;

Heap* createHeap();
void swap();
void percolateUp(Heap *heap, int index);
void percolateDown();
void insert(Heap *heap, int value);
void delete();
void printHeap(Heap* heap);

Heap* createHeap() {
    Heap *heap =(Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = 10;
    heap->array = (int*)malloc(sizeof(int) * heap->capacity);

    return heap;
}

void swap(Heap *heap, int child_index, int parent_index) {
    int temporary = heap->array[child_index]; 

    
}

void percolateUp(Heap *heap, int index) {
    while(index > 0) {
        int parent_index = (index - 1) / 2;

        if(heap->array[parent_index] >= heap->array[index]) {
            break;
        }

        int temp = heap->array[parent_index];
        heap->array[parent_index] = heap->array[index];
        heap->array[index] = temp;
        index = parent_index;
    }    
}

void percolateDown() {
    
}

void insert(Heap *heap, int value) {
    if(heap->size == heap->capacity) {
        printf("Max Capacity Reached");
        return;
    }

    heap->array[heap->size] = value;
    heap->size++;
    percolateUp(heap, (heap->size - 1));
}

void delete() {

}

void printHeap(Heap* heap) {
    for(int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }

    printf("\n\n");
}

int main() {
    Heap* heap = createHeap();

    insert(heap, 5);
    insert(heap, 2);
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 6);
    insert(heap, 9);

    printHeap(heap);

    return 0;
} 