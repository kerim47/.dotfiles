#include <stdio.h>
#include <stdlib.h>
#define NAN(item) (item == NULL)

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

void SonaEkleme(int);
void BasaEkleme(int);
void BastanSilme();
void SondanSilme();
void Goster();

int main(void) {
  SonaEkleme(10);
  SonaEkleme(20);
  BasaEkleme(30);
  BasaEkleme(40);
  Goster();
  BastanSilme();
  Goster();
  SondanSilme();
  Goster();

  return 1;
}
void SonaEkleme(int data) {
  struct node *tmp;
  tmp = malloc(sizeof(struct node));
  if (NAN(tmp))
    return;
  tmp->next = NULL;
  tmp->prev = NULL;
  tmp->data = data;
  if (NAN(head)) {
    head = tmp;
    tail = tmp;
  } else {
    // Sona ekleme yapma
    tail->next = tmp;
    tmp->prev = tail;
    tail = tmp;
  }
}

void Goster() {

  struct node *iter = head;
  while (iter != NULL) {
    printf("%d -> ", iter->data);
    iter = iter->next;
  }
  printf("NULL\n");
}
void BasaEkleme(int data) {
  struct node *temp = malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;
  temp->prev = NULL;
  if (NAN(head))
    head = tail = temp;
  else {
    temp->next = head;
    temp->prev = temp;
    head = temp;
  }
}
void BastanSilme() {
  struct node *ptr;
  if (!NAN(head)) {
    ptr = head;
    printf("Deleted data : %d\n", head->data);
    if (NAN(head->next)) {
      head = NULL;
      free(ptr);
      return;
    }
    head = head->next;
    head->prev = NULL;
    free(ptr);
  }
}

// Sondan deger silme
void SondanSilme() {

  struct node *ptr, *tmp;

  if (NAN(head))
    return;
  else if (NAN(head->next)) {
    printf("Deleted data : %d\n", head->data);
    free(head);
    head = NULL;
    tail = NULL;
  } else {
    ptr = head;
    struct node *ptr;
    ptr = tail;
    printf("Deleted data : %d\n", ptr->data);
    tail->prev->next = NULL;
    tail = tail->prev;
    free(ptr);
  }
}
