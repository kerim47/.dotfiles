#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int Value;
  int Valusde;
  void (*set)(struct Node *, int);
  int (*get)(void *);

} Node;

void set(Node *this, int value) { this->Value = value; }

int get(Node *node) { return node->Value; }

Node *newNode() {
  Node *node = (Node *)malloc(sizeof(Node));
  node->Value = 0;
  node->set = (void *)set;
  node->get = (void *)get;
  return node;
}

int main(int argc, char *argv[]) {
  Node *node = newNode();

  node->set((struct Node *)node, 10);
  // printf("get value: %d", node->get(node));
  printf("\n");
  return 0;
}
