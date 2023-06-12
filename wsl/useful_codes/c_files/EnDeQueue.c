#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 6

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item) {
  if (rear == MAX_SIZE - 1) {
    printf("Queue is full.\n");
    return;
  }
  if (front == -1) {
    front = 0;
  }
  rear++;
  queue[rear] = item;
}

void dequeue() {
  if (front == -1) {
    printf("Queue is empty.\n");
    return;
  }
  printf("Dequeued item: %d\n", queue[front]);
  front++;
  if (front > rear) {
    front = -1;
    rear = -1;
  }
}

int main() {
  enqueue(1);
  enqueue(5);
  dequeue();
  dequeue();
  dequeue();
  return 0;
}
