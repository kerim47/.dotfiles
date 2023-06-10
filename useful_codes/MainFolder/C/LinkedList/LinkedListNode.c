#include <stdlib.h>
#include "LinkedListNode.h"

LinkedListNode* newLinkedListNode(int Value)
{
  LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
  newNode->Value = Value;
  newNode->Next  = NULL;
  return newNode;
}
