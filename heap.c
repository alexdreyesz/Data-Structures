#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int *array;
    int size;
    int capacity
} Heap;

Heap * heap_heap(){
    Heap *heap =(Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = 5;
    heap->array = (int*)malloc(sizeof(int) * heap->capacity);

    return heap;
} 

int main() {

    Heap* heap = create_heap(); 
    

    return 0;
} 