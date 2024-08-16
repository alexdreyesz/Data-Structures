#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *array;
    int size;
    int capacity;
} Heap;

Heap* createHeap();
void swap();
void percolateUp();
void percolateDown();
void insert();
void delete();

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

void percolateUp() {

}

void percolateDown() {
    
}

int main() {
    Heap* heap = createHeap();

    printf("Array: %d\n", heap->array[0]);
    printf("Size: %d\n", heap->size);
    printf("Capacity: %d\n", heap->capacity);

    return 0;
} 