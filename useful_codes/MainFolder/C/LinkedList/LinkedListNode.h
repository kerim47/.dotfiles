#ifndef LINKEDLISTNODE_H_
#define LINKEDLISTNODE_H_

// Olusturulacak yeni dugumun verilerini ifade eder.
typedef struct LinkedListNode
{
  struct LinkedListNode* Next;
  int Value;

}LinkedListNode;

// Olusturulan yeni dugumun kendisini dondurur.
LinkedListNode* newLinkedListNode(int);

#endif // !LINKEDLISTNODE_H_
