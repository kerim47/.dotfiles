#include "SingleLinkedList.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  for (int i = 0; i < 10; i++) {
    addFirst(i);
  }
  print();
  printf("\n");
  // for (int i = 0; i < 10; i++) {
  //   printf("%d\n", deleteLast());
  // }
  addAfter(8, 56);
  print();
  printf("\n");
  return 0;
}
