#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kullanici_boyut = 0;

struct Tree {
  char file_name[20];
  struct Tree *dal[100];
  struct Tree *onceki_klasor;
  int index;
};

struct Tree *kok = NULL;
struct Tree *bulunan_klasor = NULL;

void klasor_goster(struct Tree *konum) {
  int i = 0;
  printf("%s\n", konum->file_name);

  for (; i < konum->index; i++) {
    printf("%d - %s\n", i + 1, konum->dal[i]->file_name);
  }
}

void klasor_ekle(struct Tree *konum) {
  if (kullanici_boyut != 100) {
    char dosya_adi[20];
    int i = 0;
    konum->dal[konum->index] = (struct Tree *)malloc(sizeof(struct Tree));
    printf("Enter a file name : \n");
    scanf("%s", konum->dal[konum->index]->file_name);
    for (; i < 100; i++) {
      konum->dal[konum->index]->dal[i] = NULL;
    }
    konum->dal[konum->index]->onceki_klasor = konum;
    konum->dal[konum->index]->index = 0;
    konum->index++;
    kullanici_boyut++;
  }
}

void klasor_gir(struct Tree *klasor) { bulunan_klasor = klasor; }

void geri_don() { bulunan_klasor = bulunan_klasor->onceki_klasor; }

int main() {
  int i = 0;
  kok = malloc(sizeof(struct Tree));
  strcpy(kok->file_name, "Yerel Disk C");
  kok->index = 0;
  for (; i < 100; ++i) {
    kok->dal[i] = NULL;
  }

  kok->onceki_klasor = NULL;
  kullanici_boyut++;
  bulunan_klasor = malloc(sizeof(struct Tree));
  bulunan_klasor = kok;
  while (1) {
    int secim;
    klasor_goster(bulunan_klasor);
    if (bulunan_klasor == kok) {
      printf("%d -> Geri don\n", bulunan_klasor->index + 1);
      printf("0 -> Yeni Klasor Ekleme");
      printf("\nSecim Yapiniz : ");
      scanf("%d", &secim);
      if (secim >= 0 && secim < 100) {
        if (secim == 0)
          klasor_ekle(bulunan_klasor);
        else if (secim == bulunan_klasor->index + 1 && bulunan_klasor != kok)
          geri_don();
        else if (bulunan_klasor->dal[secim - 1])
          klasor_gir(bulunan_klasor->dal[secim - 1]);
      }
    }
    printf("\n");
    getchar();
    system("clear");
  }
  return 1;
}
