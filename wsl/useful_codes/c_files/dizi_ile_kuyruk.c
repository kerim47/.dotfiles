#include <stdio.h>
#define MAX_SIZE 5 // Kuyruğun maksimum boyutu

int queue[MAX_SIZE]; // Kuyruk için dizi
int rear = -1;       // Kuyruğun sonu
int front = -1;      // Kuyruğun başı

// Kuyruk işlemleri
void enqueue(int item);
int dequeue();
int front_item();
int is_empty();
int is_full();
int main() {
  // Kuyruğa eleman ekle
  enqueue(10);
  enqueue(20);
  enqueue(30);

  // Kuyruktan eleman sil ve ekrana yazdır
  printf("%d dequeued from the queue\n", dequeue());
  printf("%d dequeued from the queue\n", dequeue());

  // Kuyruktaki ilk elemanı al ve ekrana yazdır
  printf("Front item is %d\n", front_item());

  // Kuyruktaki eleman sayısını al ve ekrana yazdır
  printf("Size of the queue is %d\n", rear - front + 1);

  return 0;
}

// Kuyruğa eleman ekle
void enqueue(int item) {
  if (is_full()) {
    printf("Queue is full!\n");
    return;
  }
  rear++;
  queue[rear] = item;
  if (front == -1) {
    front = 0;
  }
}

// Kuyruktan eleman sil
int dequeue() {
  int item;
  if (is_empty()) {
    printf("Queue is empty!\n");
    return -1;
  }
  item = queue[front];
  front++;
  if (front > rear) {
    front = rear = -1;
  }
  return item;
}

// Kuyruktaki ilk elemanı al
int front_item() {
  if (is_empty()) {
    printf("Queue is empty!\n");
    return -1;
  }
  return queue[front];
}

// Kuyruk boş mu kontrolü
int is_empty() {
  if (front == -1 || front > rear) {
    return 1;
  }
  return 0;
}

// Kuyruk dolu mu kontrolü
int is_full() {
  if (rear == MAX_SIZE - 1) {
    return 1;
  }
  return 0;
}
