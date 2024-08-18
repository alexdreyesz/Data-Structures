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
int delete(Heap* heap);
void percolateDown(Heap* heap, int index);
void printHeap(Heap* heap);

// Create Heap
Heap* createHeap() {
    Heap* heap = (Heap*)malloc(sizeof(Heap));

    heap->size = 0;
    heap->capacity = 10;
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

// Delete Root From The Heap 
int delete(Heap* heap) {
    if(heap->size == 0) {
        printf("Heap Is Empty\n\n");
        return 0;
    }

    int value = heap->array[0];

    // Replace The Root To Delete With The Last Element
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    percolateDown(heap, 0);

    return value;
}

// Helper Function For Delete: Percolate Down The Value Until It Is In The Correct Index
void percolateDown(Heap* heap, int index) {
    while (index < heap->size) {
        int smallest = index;
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;

        if (left_child < heap->size && heap->array[left_child] < heap->array[smallest]) {
            smallest = left_child;
        }

        if (right_child < heap->size && heap->array[right_child] < heap->array[smallest]) {
            smallest = right_child;
        }

        if (smallest == index) {
            break;
        }

        swap(heap, index, smallest);

        index = smallest;
    }
}

// Print Heap
void printHeap(Heap* heap) {
    if(heap->size == 0) {
        printf("Empty Heap \n\n");
        return;
    }
    
    for(int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }

    printf("\n\n");
}

int main() {
    //Create Heap
    Heap* heap = createHeap();

    // Heapsort Array
    int heapsort[10] = {0}; 

    // Insert Values
    insert(heap, 5);
    insert(heap, 2);
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 6);
    insert(heap, 9);

    // Print Heap
    printHeap(heap);

    // Delete Values
    heapsort[0] = delete(heap);
    heapsort[1] = delete(heap);
    heapsort[2] = delete(heap);
    heapsort[3] = delete(heap);
    heapsort[4] = delete(heap);
    heapsort[5] = delete(heap);

    // Print Heap After Deleted Values
    printHeap(heap);

    for(int i = 0; i < 6; i++) {
    printf("%d ", heapsort[i]);
    }

    printf("\n\n");

    return 0;
}