#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char label[20];
  int counter;
  struct node *adjList[100];
  struct node *nextNode;
};

struct node *start = NULL;
struct node *last = NULL;

void new_node(char sehir_adi[20]) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  strcpy(newNode->label, sehir_adi);
  newNode->counter = 0;
  newNode->nextNode = NULL;

  if (start == NULL) {
    start = newNode;
    last = newNode;
  } else {
    last->nextNode = newNode;
    last = newNode;
  }
}

void sehir_goster() {
  struct node *currentNode = start;

  printf("Graf Yapisi:\n");

  while (currentNode != NULL) {
    printf("Dugum: %s\n", currentNode->label);
    printf("Komusuluklar: ");

    for (int i = 0; i < currentNode->counter; i++) {
      printf("%s ", currentNode->adjList[i]->label);
    }

    printf("\n\n");
    currentNode = currentNode->nextNode;
  }
}

struct node *search_node(char sehir_adi[20]) {
  struct node *currentNode = start;

  while (currentNode != NULL) {
    if (strcmp(currentNode->label, sehir_adi) == 0) {
      return currentNode;
    }

    currentNode = currentNode->nextNode;
  }

  return NULL;
}

void add_edge(char src[20], char dest[20]) {
  struct node *srcNode = search_node(src);
  struct node *destNode = search_node(dest);

  if (srcNode != NULL && destNode != NULL) {
    srcNode->adjList[srcNode->counter] = destNode;
    destNode->adjList[destNode->counter] = srcNode;
    srcNode->counter++;
    destNode->counter++;
  }
}

void komsu_goster(char src[20]) {
  struct node *srcNode = search_node(src);

  if (srcNode != NULL) {
    printf("%s adli sehre ait komsuluklar:\n", srcNode->label);

    for (int i = 0; i < srcNode->counter; i++) {
      printf("%s\n", srcNode->adjList[i]->label);
    }
  }
}

int main() {
  int choice;
  char sehir_adi[20];
  char src[20];
  char dest[20];

  while (1) {
    printf("1- Yeni dugum olustur\n");
    printf("2- Eklenen sehirleri goster\n");
    printf("3- Sehir adina ait dugumu bul\n");
    printf("4- Dugumler arasinda baglanti kur\n");
    printf("5- Sehirin komsularini goster\n");
    printf("6- Cikis\n");
    printf("Secim yapin: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Sehir adini girin: ");
      scanf("%s", sehir_adi);
      new_node(sehir_adi);
      break;
    case 2:
      sehir_goster();
      break;
    case 3:
      printf("Aranacak sehir adini girin: ");
      scanf("%s", sehir_adi);
      struct node *result = search_node(sehir_adi);

      if (result != NULL) {
        printf("Sehir bulundu: %s\n", result->label);
      } else {
        printf("Sehir bulunamadi.\n");
      }

      break;
    case 4:
      printf("Baglanti kurulacak iki sehir adini girin: ");
      scanf("%s %s", src, dest);
      add_edge(src, dest);
      break;
    case 5:
      printf("Komsularini gormek istediginiz sehir adini girin: ");
      scanf("%s", sehir_adi);
      komsu_goster(sehir_adi);
      break;
    case 6:
      exit(0);
    default:
      printf("Gecersiz secim!\n");
    }
  }

  return 0;
}

