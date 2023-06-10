#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void Ekle(int);
void Goster();

int main() {
  Ekle(10);
  Goster();
  return 1;
}

void ekle(int data) {
  struct Node *temp;
  temp = malloc(sizeof(struct Node));
  if (temp == NULL)
    return;
  temp->data = data;
  temp->next = NULL;

  if (head == NULL) {
    head = temp;
    tail = temp;
    head->next = tail;
    tail->next = head;
    return;
  }
  // Liste boş değilse sona ekleme yapar.
  tail->next = temp;
  tail = temp;
  tail->next = head;
}

void Goster() {
  struct Node *temp;
  temp = head;
  while (temp->next != NULL) {
    printf("%d -> ", temp->data);
  }
  printf("NULL\n");
}
