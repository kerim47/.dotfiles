#include <stdio.h>
#include <stdlib.h>


typedef struct Node{

  int value;
  struct Node* next;
  
} Node;

Node* head = NULL;
void addFirst(int);
void addLast(int);
void print();

int main (int argc, char *argv[])
{
  addFirst(10);
  addFirst(20);
  addFirst(30);
  addFirst(40);
  addFirst(50);
  print();
  return 0;
}


void addLast(int value)
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  Node* iter = head;
  if (head == NULL)
  {
    addFirst(value);
    return;
  }

  while (iter->next != NULL) iter = iter->next;
  newNode->next = NULL;
  newNode->value = value;
  iter->next = newNode;
}


void addFirst(int value)
{
  Node* node = (Node*)malloc(sizeof(Node));
    
  if (head == NULL) 
  {
     node->next = NULL;
     node->value = value;
     head = node;
     return;
  }  
  node->value = value;
  node->next = head;
  head = node;
}

void print()
{
  Node* iter = head;
  while (iter != NULL) {
    printf("%d ->", iter->value);
    iter = iter->next;
  }
  printf("NULL\n");
}
