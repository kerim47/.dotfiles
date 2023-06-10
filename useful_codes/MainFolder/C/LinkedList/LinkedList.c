#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "LinkedListNode.h"

/*
 * Copyright (c) 2023 Abdulkerim. All Rights Reserved. 
 */

// Yeni bir dugum olusturma 
LinkedList* newLinkedList() {
  LinkedList* newNode = malloc(sizeof(LinkedList));
  newNode->head = NULL;
  return newNode;
}

// Dugumun başına eleman ekleme
void addFirst(LinkedList* refNode, int data){
  LinkedListNode* newNode = newLinkedListNode(data);
  newNode->Next = refNode->head;
  refNode->head = newNode;
}

// Dugumun sonuns eleman ekleme
void addLast(LinkedList* refNode, int data) {
  LinkedListNode* newNode = newLinkedListNode(data);
  LinkedListNode* iter = refNode->head;
  if(iter != NULL)
  {
    while (iter->Next != NULL)
    {
      iter = iter->Next;
    }
    iter->Next = newNode;
  }
  else
  {
    refNode->head = newNode;
    return;
  }
}

void addBefore(LinkedList* refNode, int value)
{
  LinkedListNode* newNode = newLinkedListNode(value);
  if (refNode->head != NULL)
  {
    LinkedListNode* iter = refNode->head;
    while (iter->Next != NULL)
    {
       
    }
  }
  else
  {
     fprintf(stderr, "Hata: ptr NULL degerinde\n");
     exit(EXIT_FAILURE);
  }
}

// Dugum listesini yazdirma
void printList(LinkedList* refNode) {
  LinkedListNode* current = refNode->head;
  while (current != NULL) 
  {
    printf("%d -> ", current->Value);
    current = current->Next;
  }
  printf("NULL\n");
}

