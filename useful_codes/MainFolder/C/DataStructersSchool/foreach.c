#define for_each_item(item, list)                                              \
  for (T *item = list->head; item != NULL; item = item->next)
#define foreach(item, array)                                                   \
  for (int keep = 1, count = 0, size = sizeof(array) / sizeof *(array);        \
       keep && count != size; keep = !keep, count++)                           \
    for (item = (array) + count; keep; keep = !keep)

#include "functions.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

  for_each_item(struct node * temp, start);
  return 1;
}
