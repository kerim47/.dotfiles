#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {

  LinkedList* list = newLinkedList();
  addLast(list, 20);
  addFirst(list, 30);
  addLast(list, 40);
  addLast(list, 40);
  addBefore(list, 10);
  printList(list);

  return 0;
}

