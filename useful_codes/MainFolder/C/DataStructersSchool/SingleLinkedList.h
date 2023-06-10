#ifndef SINGLELINKEDKLIST_H_
#define SINGLELINKEDKLIST_H_
#include <stdbool.h>

struct Node
{
  int data;
  struct Node* next;
};

bool IsNULL(struct Node* tmp);
void Except(const char* msg);
void print();
void addFirst(int);
void addLast();
int deleteFirst();
int deleteLast();
void addAfter(int, int);
int Length();

#endif // !SINGLELINKEDKLIST_H_
