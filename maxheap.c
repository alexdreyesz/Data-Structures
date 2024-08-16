#include <stdio.h>
#include <stdlib.h>

// Heap Struct
typedef struct Heap {
    int *array;
    int size;
    int capacity;
} Heap;

// Function Declaration 
Heap* createHeap();
void insert(Heap *heap, int value);
void percolateUp(Heap *heap, int index);
void swap(Heap *heap, int child_index, int parent_index);
void delete();
void percolateDown();
void printHeap(Heap* heap);

// Create Heap
Heap* createHeap() {
    Heap *heap =(Heap*)malloc(sizeof(Heap));

    heap->size = 0;
    heap->capacity = 10;
    heap->array = (int*)malloc(sizeof(int) * heap->capacity);

    return heap;
}

// Insert The Value In The Heap 
void insert(Heap *heap, int value) {
    if(heap->size == heap->capacity) {
        heap->capacity = heap->capacity * 2;
        heap->array = (int*)realloc(heap->array, heap->capacity * sizeof(int));
    }

    heap->array[heap->size] = value;
    heap->size++;
    percolateUp(heap, (heap->size - 1));
}

// Helper Function For Insert: Percolate Up The Value Until It Is In The Correct Index
void percolateUp(Heap *heap, int index) {
    while(index > 0) {
        int parent_index = (index - 1) / 2;

        if(heap->array[parent_index] >= heap->array[index]) {
            break;
        }
        
        swap(heap, parent_index, index);

        index = parent_index;
    }    
}

// Helper Fucntion For PercolateUp: Swap The 2 Values
void swap(Heap *heap, int parent_index, int child_index) {
    int temporary = heap->array[parent_index]; 
    heap->array[parent_index] = heap->array[child_index];
    heap->array[child_index] = temporary;
}

// Delete A Value From The Heap 
void delete(Heap* heap, int value) {
    if(heap->size == 0) {
        printf("Heap Is Empty\n\n");
        return;
    }

    int index = -1;

    for(int i = 0; i < heap->size; i++) {
        if(heap->array[i] == value) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("No Value Found\n\n");
        return;
    }

    // Replace The Element To Delete With The Last Element
    heap->array[index] = heap->array[heap->size - 1];
    heap->size--;

    percolateDown(heap, index);
}

// Helper Function For Delete: Percolate Down The Value Until It Is In The Correct Index
void percolateDown(Heap* heap, int index) {
    while (index < heap->size) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heap->size && heap->array[leftChild] > heap->array[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap->size && heap->array[rightChild] > heap->array[largest]) {
            largest = rightChild;
        }

        if (largest == index) {
            break;
        }

        int temp = heap->array[index];
        heap->array[index] = heap->array[largest];
        heap->array[largest] = temp;

        index = largest;
    }
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

    // Delete Values
    delete(heap, 6);
    delete(heap, 7);
    delete(heap, 2);

    // Print Heap After Deleted Values
    printHeap(heap);

    return 0;
} 