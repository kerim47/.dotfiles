#include <stdio.h>
#include <stdlib.h>

struct Heap {
  int *heapArray;
  int size;
  int capacity;
};

struct Heap *createHeap(int capacity) {
  struct Heap *heap = (struct Heap *)malloc(sizeof(struct Heap));
  heap->capacity = capacity;
  heap->size = 0;
  heap->heapArray = (int *)malloc(capacity * sizeof(int));
  return heap;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(struct Heap *heap, int index) {
  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < heap->size && heap->heapArray[left] > heap->heapArray[largest])
    largest = left;

  if (right < heap->size && heap->heapArray[right] > heap->heapArray[largest])
    largest = right;

  if (largest != index) {
    swap(&heap->heapArray[index], &heap->heapArray[largest]);
    heapify(heap, largest);
  }
}

void insert(struct Heap *heap, int value) {
  if (heap->size == heap->capacity) {
    printf("Heap is full, cannot insert more elements.\n");
    return;
  }

  int index = heap->size;
  heap->heapArray[index] = value;
  heap->size++;

  while (index != 0 &&
         heap->heapArray[index] > heap->heapArray[(index - 1) / 2]) {
    swap(&heap->heapArray[index], &heap->heapArray[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

void deleteRoot(struct Heap *heap) {
  if (heap->size == 0) {
    printf("Heap is empty, cannot delete root.\n");
    return;
  }

  heap->heapArray[0] = heap->heapArray[heap->size - 1];
  heap->size--;
  heapify(heap, 0);
}

void printHeap(struct Heap *heap) {
  printf("Heap: ");
  for (int i = 0; i < heap->size; i++) {
    printf("%d ", heap->heapArray[i]);
  }
  printf("\n");
}

int main() {
  struct Heap *heap = createHeap(10);

  insert(heap, 5);
  insert(heap, 3);
  insert(heap, 8);
  insert(heap, 1);
  insert(heap, 7);

  printHeap(heap);

  deleteRoot(heap);

  printHeap(heap);

  return 0;
}
