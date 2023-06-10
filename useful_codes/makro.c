#include <stdio.h>

#define FOREACH(item, arr, start, size)                                        \
  for (int i = start, keep = 1; keep && i < size; keep = !keep, i++)           \
    for (item = arr[i]; keep; keep = !keep)

#define foreach(a, b) for (int a = 0; a < (sizeof(b) / sizeof(b[0])); a++)

#define print(a) (a == NULL) ? "kerim" : a;

int main() {

  int arr[] = {3, 9, 7, 1, 8};
  FOREACH(int z, arr, 0, 5) {
    printf("Shanii Demo index: %d. element: %d\n", i, z);
  }

  foreach (i, arr) {
    printf("index: %d. element: %d\n", i, arr[i]);
  }
}
