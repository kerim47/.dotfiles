#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mergeAlternately(char *word1, char *word2) {
  int len_1 = strlen(word1);
  int len_2 = strlen(word2);
  int i, j, k;
  char *merged;

  merged = malloc(sizeof(char) * (len_1 + len_2 + 1));
  i = j = k = 0;

  while ((i < len_1) && (i < len_2)) {
    merged[k++] = word1[i++];
    merged[k++] = word2[j++];
  }

  while (i < len_1) {
    merged[k++] = word1[i++];
  }

  while (j < len_2) {
    merged[k++] = word1[j++];
  }
  merged[k] = '\0';
  return merged;
}

int main() {
  char word1[] = "abc";
  char word2[] = "pqr";
  char *merged = mergeAlternately(word1, word2);
  printf("Merged string: %s\n", merged);
  free(merged);

  return 0;
}

