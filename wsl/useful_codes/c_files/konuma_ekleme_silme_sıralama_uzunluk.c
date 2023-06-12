#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *head = NULL;
int size = 0;

void insert(int position, int value) {
  // yeni düğüm için bellek ayrımlama
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = value;
  new_node->next = NULL;

  // liste boş ise
  if (head == NULL) {
    head = new_node;
    size++;
    return;
  }

  // listenin başına ekleme yapma
  if (position == 1) {
    new_node->next = head;
    head = new_node;
    size++;
    return;
  }

  // listenin sonuna ekleme yapma
  if (position == size + 1) {
    Node *current_node = head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
    size++;
    return;
  }

  // konuma ekleme yapma
  if (position > 1 && position <= size) {
    Node *current_node = head;
    for (int i = 1; i < position - 1; i++) {
      current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
    size++;
    return;
  }

  // hatalı konum girildi ise exception fırlatma
  printf("Hatali konum girildi.\n");
  exit(0);
}

void delete(int position) {
  // liste boş ise
  if (head == NULL) {
    return;
  }

  // listenin başından eleman silme yapma
  if (position == 1) {
    Node *temp = head;
    head = head->next;
    free(temp);
    size--;
    return;
  }

  // konumdan eleman silme yapma
  if (position > 1 && position <= size) {
    Node *current_node = head;
    Node *previous_node = NULL;
    for (int i = 1; i < position; i++) {
      previous_node = current_node;
      current_node = current_node->next;
    }
    previous_node->next = current_node->next;
    free(current_node);
    size--;
    return;
  }

  // hatalı konum girildi ise exception fırlatma
  printf("Hatali konum girildi.\n");
  exit(0);
}

void print_list() {
  Node *current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

// Liste uzunluğunu hesaplayan fonksiyon
int uzunluk() {
  int count = 0;
  Node *current = head;

  while (current != NULL) {
    count++;
    current = current->next;
  }

  return count;
}

// Elemanları büyükten küçüğe sıralı olarak ekleme fonksiyonu
void insert_sorted(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (head == NULL || data > head->data) {
    new_node->next = head;
    head = new_node;
  } else {
    Node *current = head;

    while (current->next != NULL && data <= current->next->data) {
      current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
  }
}

int main() {

  // eleman ekleme işlemi yapma
  insert(1, 10);
  insert(2, 20);
  insert(3, 30);
  insert(4, 40);

  // elemanları yazdırma
  printf("Liste: ");
  print_list();

  // konuma ekleme işlemi yapma
  insert(1, 25); // 10 20 25 30 40

  // elemanları yazdırma
  printf("Liste: ");
  print_list();

  // konumdan silme işlemi yapma
  delete (3); // 10 20 30 40

  // elemanları yazdırma
  printf("Liste: ");
  print_list();

  // elemanları yazdırma
  printf("Liste uzunlugu: %d\n", uzunluk());

  // // elemanları sıralı olarak ekleme
  // insert_sorted(30);
  // insert_sorted(10);
  // insert_sorted(40);
  // insert_sorted(20);
  // print_list();

  return 0;
}
