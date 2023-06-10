#include "SingleLinkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node *start = NULL;
int length = 0;
void addLast() {
  struct Node *temp, *ptr;
  temp = (struct Node *)malloc(sizeof(struct Node));
  if (IsNULL(temp)) {
    Except("Yetersiz bellek alani.");
  }
  printf("Veriyi girin : ");
  scanf("%d", &temp->data);
  temp->next = NULL;

  if (IsNULL(start)) {
    start = temp;
  } else {
    ptr = start;
    while (!IsNULL(ptr->next)) {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
  length++;
}

void print() {
  struct Node *iter = start;
  while (!IsNULL(iter)) {
    printf("%d -> ", iter->data);
    iter = iter->next;
  }
  printf("NULL");
}

void addFirst(int val) {
  struct Node *tmp = malloc(sizeof(struct Node));
  if (IsNULL(tmp)) {
    Except("Yetersiz Bellek Alani.");
  }
  // printf("Veriyi giriniz : ");
  // scanf("%d", &tmp->data);
  tmp->data = val;
  tmp->next = NULL;

  if (IsNULL(start)) {
    start = tmp;
  } else {
    tmp->next = start;
    start = tmp;
  }
  length++;
}

int deleteFirst() {
  int value;
  if (IsNULL(start)) {
    Except("Liste is empty cannot delete");
  } else {
    value = start->data;
    struct Node *garbage = start;
    start = start->next;
    free(garbage);
  }
  length--;
  return value;
}

int deleteLast() {
  int value;
  if (IsNULL(start)) {
    Except("Liste is empty cannot delete");
  } else if (IsNULL(start->next)) {
    value = start->data;
    free(start);
    start = NULL;
  } else {

    struct Node *iter = start;
    struct Node *garbage;

    while (!IsNULL(iter->next)) {
      garbage = iter;
      iter = iter->next;
    }
    value = iter->data;
    garbage->next = NULL;
    free(iter);
  }
  length--;
  return value;
}

void Except(const char *msg) {
  fprintf(stderr, "%s", msg);
  exit(EXIT_FAILURE);
}

bool IsNULL(struct Node *tmp) { return (tmp == NULL) ? 1 : 0; }

int Length() {
  struct Node *iter = start;
  int length = 0;
  while (!IsNULL(iter)) {
    length++;
    iter = iter->next;
  }
  return length;
}

void addAfter(int index, int value) {
  struct Node *newNode = malloc(sizeof(struct Node));
  struct Node *iter = start;

  if (IsNULL(start)) {
    if (index == 0) {
      newNode->next = NULL;
      newNode->data = value;
      start = newNode;
    }
  } else {
    if (index == 0) {
      newNode->data = value;
      newNode->next = start;
      start = newNode;
    } else if (index < length && index > 0) {
      struct Node *tmp = start;
      for (int i = 0; i < index; i++) {
        tmp = iter;
        iter = iter->next;
      }
      newNode->data = value;
      newNode->next = tmp->next;
      tmp->next = newNode;
    }
  }
}
