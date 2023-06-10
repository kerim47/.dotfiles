#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "LinkedListNode.h"

typedef struct LinkedList 
{
  LinkedListNode* head;
}LinkedList;

LinkedList* newLinkedList();

void addFirst(LinkedList* refNode, int data);
void addLast(LinkedList* refNode, int data);
void printList(LinkedList* refNode);
void addBefore(LinkedList* refNode, int value);
#endif // !LINKEDLIST_H_
