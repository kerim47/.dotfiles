#include "functions.h"
#include "SingleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define for_each_item(item, list)                                              \
  for (T *item = list->head; item != NULL; item = item->next)

struct node *start = NULL;
struct node *end = NULL;

void Goster() {
  struct node *ptr;
  ptr = start;
  while (ptr != NULL) {
    printf("%d -> ", ptr->data);
    ptr = ptr->next;
  }
  printf("NULL\n");
}

// Verilerin dugumun basina eklenmesi
void BasaEkleme(int value) {
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    return;
  }
  temp->data = value;
  temp->next = NULL;

  if (start == NULL) {
    start = temp;
  } else {
    temp->next = start;
    start = temp;
  }
}

// Verilerin dugumun basindan silinmesi
void BastanSilme() {
  struct node *ptr;
  printf("Bastan Silme : %d\n", start->data);
  if (start != NULL) {
    ptr = start;
    start = start->next;
    free(ptr);
  }
}

void SondanSilme() {
  struct node *ptr, *temp;
  if (start == NULL) {
    return;
  } else if (start->next == NULL) {
    free(start);
    start = NULL;
  } else {
    ptr = start;
    while (ptr->next != NULL) {
      temp = ptr;
      ptr = ptr->next;
    }
    temp->next = NULL;
    printf("Sondan Silme : %d\n", ptr->data);
    free(ptr);
  }
}
void KonumaEkleme(int index, int value) {
  if (index >= 0) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if (start == NULL) {
      start = temp;
      return;
    } else {
      struct node *iter = temp;
      struct node *prev = temp;
      while (index) {
      }
    }
  }
}
