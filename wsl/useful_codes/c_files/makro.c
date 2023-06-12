#include "functions.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #define FOREACH_COMP(INDEX, ARRAY, ARRAY_TYPE, SIZE)                           \
//   __extension__({                                                              \
//     bool ret = 0;                                                              \
//     if (__builtin_types_compatible_p(const char *, ARRAY_TYPE))                \
//       ret = INDEX < strlen((const char *)ARRAY);                               \
//     else                                                                       \
//       ret = INDEX < SIZE;                                                      \
//     ret;                                                                       \
//   })

// #define FOREACH_ELEM(INDEX, ARRAY, TYPE)                                       \
//   __extension__({                                                              \
//     TYPE *tmp_array_ = ARRAY;                                                  \
//     &tmp_array_[INDEX];                                                        \
//   })

// #define FOREACH(VAR, ARRAY)                                                    \
//   for (void *array_ = (void *)(ARRAY); array_; array_ = 0)                     \
//     for (size_t i_ = 0; i_ && array_ &&                                        \
//                         FOREACH_COMP(i_, array_, __typeof__(ARRAY),            \
//                                      sizeof(ARRAY) / sizeof((ARRAY)[0]));      \
//          i_++)                                                                 \
//       for (bool b_ = 1; b_; (b_) ? array_ = 0 : 0, b_ = 0)                     \
//         for (VAR = FOREACH_ELEM(i_, array_, __typeof__((ARRAY)[0])); b_; b_ = 0)

// #define FOREACH(item, array, start, size)                                      \
//   for (int i = start, keep = 1; keep && i < size; keep = !keep, i++)           \
//     for (item = array[i]; keep; keep = !keep)
#define for_each_item(item, list)                                              \
  for (typeof(item) *item = list->head; item != NULL; item = item->next)
#define foreach(item, array)                                                   \
  for (int keep = 1, count = 0, size = sizeof(array) / sizeof *(array);        \
       keep && count != size; keep = !keep, count++)                           \
    for (item = (array) + count; keep; keep = !keep)
#define for_each_item_1(item, list)                                            \
  for (T *item = list->head; item != NULL; item = item->next)
#define foreach_item_2(item, array)                                            \
  for (int keep = 1, count = 0, size = sizeof(array) / sizeof *(array);        \
       keep && count != size; keep = !keep, count++)                           \
    for (item = (array) + count; keep; keep = !keep)
int main(int argc, char *argv[]) {

  int values[] = {1, 2, 3};
  foreach (int *v, values) {
    printf("value: %d\n", *v);
  }
  int n, i;

  // Rastgele sayı üretimi için tohum değerini ayarla
  srand(time(NULL));

  for (i = 0; i < 5; i++) {
    int randomNumber =
        rand() % 100 + 1; // 1 ile 100 arasında rastgele sayı üret
    BasaEkleme(randomNumber);
  }
  struct node *temp;
  struct node *start = NULL;
  // for_each_item(temp, start) { printf("%d\n", temp->data); };
  Goster();
  BastanSilme();
  Goster();
  SondanSilme();
  struct node *for_node;
  for_each_item(for_node, start) { printf("%d", for_node->data); }
  return 1;
}
