#include <stdio.h>
#include <stdlib.h>

// Heap Struct
typedef struct Heap {
    int* array;
    int capacity;
    int size;
} Heap;

// Function Declaration 
Heap* createHeap();
void insert(Heap* heap, int value);
void percolateUp(Heap* heap, int index);
void swap(Heap* heap, int parent_index, int child_index);
void printHeap(Heap* heap);

// Create Heap
Heap* createHeap() {
    Heap* heap = (Heap*)malloc(sizeof(Heap));

    heap->capacity = 10;
    heap->size = 0;
    heap->array = (int*)malloc(heap->capacity * sizeof(int));

    return heap;
}

// Insert The Value In The Heap 
void insert(Heap* heap, int value) {
    if(heap->size == heap->capacity) {
        heap->capacity = heap->capacity * 2;
        heap->array = (int*)realloc(heap->array, heap->capacity * sizeof(int));
    } 

    heap->array[heap->size] = value;
    heap->size++;
    percolateUp(heap, (heap->size - 1));
}

// Helper Function For Insert: Percolate Up The Value Until It Is In The Correct Index
void percolateUp(Heap* heap, int index) {
    while(index > 0) {
        int parent_index = (index - 1) / 2;

        if(heap->array[parent_index] <= heap->array[index]){
            break;
        }

        swap(heap, parent_index, index);

        index = parent_index;
    }
}

// Helper Fucntion For PercolateUp: Swap The 2 Values
void swap(Heap* heap, int parent_index, int child_index) {
    int temp = heap->array[parent_index];
    heap->array[parent_index] = heap->array[child_index];
    heap->array[child_index] = temp;
}

// Print Heap
void printHeap(Heap* heap) {
    for(int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }

    printf("\n\n");
}

int main() {
    //Create Heap
    Heap* heap = createHeap();

    // Insert Values
    insert(heap, 5);
    insert(heap, 2);
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 6);
    insert(heap, 9);

    // Print Heap
    printHeap(heap);

    return 0;
}