#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode {
  struct TrieNode *children[ALPHABET_SIZE];
  bool is_end_of_word;
};

struct TrieNode *get_node() {
  struct TrieNode *pNode = NULL;
  pNode = malloc(sizeof(struct TrieNode));
  if (pNode) {
    int i;
    pNode->is_end_of_word = false;
    for (i = 0; i < ALPHABET_SIZE; i++) {
      pNode->children[i] = NULL;
    }
  }
  return pNode;
}

void insert(struct TrieNode *root, const char *key) {
  int level;
  int length = strlen(key);
  int index;

  struct TrieNode *pCrawl = root;

  for (level = 0; level < length; level++) {
    index = CHAR_TO_INDEX(key[level]);
    if (!pCrawl->children[index]) {
      pCrawl->children[index] = get_node();
    }
    pCrawl = pCrawl->children[index];
  }
  pCrawl->is_end_of_word = true;
}

bool search(struct TrieNode *root, const char *key) {
  int level, length, index;
  length = strlen(key);
  struct TrieNode *pCrawl = root;
  for (level = 0; level < length; level++) {
    index = CHAR_TO_INDEX(key[level]);
    if (!pCrawl->children[index]) {
      return false;
    }
    pCrawl = pCrawl->children[index];
  }
  return (pCrawl->is_end_of_word);
}
int main(int argc, char *argv[]) {

  char keys[][8] = {"Kerem",  "Ali",  "Ayse",  "Can",
                    "Aleyna", "Emir", "Oznur", "Emirhan"};

  char output[][32] = {"Sozlukte Yok", "Sozlukte Var"};

  struct TrieNode *root = get_node();

  int i;
  for (i = 0; i < ARRAY_SIZE(keys); i++) {
    insert(root, keys[i]);
  }

  printf("%s --- %s\n", "kerem", output[search(root, "Kerem")]);
  printf("%s --- %s\n", "mehmet", output[search(root, "Mehmet")]);
  printf("%s --- %s\n", "can", output[search(root, "Can")]);
  printf("%s --- %s\n", "oznur", output[search(root, "Oznur")]);

  return 1;
}
