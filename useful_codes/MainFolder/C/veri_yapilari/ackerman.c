#include <math.h>
#include <stdio.h>
#include <time.h>

int recursive_ackermann(int m, int n) {
  if (m == 0) {
    return n + 1;
  } else if (m > 0 && n == 0) {
    return recursive_ackermann(m - 1, 1);
  } else if (m > 0 && n > 0) {
    return recursive_ackermann(m - 1, recursive_ackermann(m, n - 1));
  }
  return -1;
}

float ortalama = 0;

float mean(int sayilar[], int uzunluk) {
  if (uzunluk == 1)
    return (float)sayilar[uzunluk - 1];
  else
    return ((float)(mean(sayilar, uzunluk - 1) * (uzunluk - 1) +
                    sayilar[uzunluk - 1]) /
            uzunluk);
}

float recursive_mean(int sayilar[], int uzunluk) {
  int i = 0;
  float toplam = 0;
  for (; i < uzunluk; i++) {
    toplam += sayilar[i];
  }
  return (float)(toplam / uzunluk);
}

float recursive_var(int sayilar[], int uzunluk) {
  float ara_sonuc = 0;
  if (uzunluk == 0)
    return 0;
  ara_sonuc = pow((float)(sayilar[uzunluk - 1] - ortalama), 2);
  return ara_sonuc + recursive_var(sayilar, uzunluk - 1);
}

float var(int sayilar[], int uzunluk) {
  int i = 0;
  float toplam = 0;
  for (; i < uzunluk; i++) {
    toplam += pow((float)(sayilar[i] - ortalama), 2);
  }
  return (float)(toplam / (uzunluk - 1));
}

int main() {
  int m, n;
  printf("m degerini girin: ");
  scanf("%d", &m);
  printf("n degerini girin: ");
  scanf("%d", &n);

  int result = recursive_ackermann(m, n);
  printf("recursive_Ackermann(%d, %d) = %d\n", m, n, result);

  int sayilar[] = {1, 4, 7, 2, 3, 6};
  int uzunluk = sizeof(sayilar) / sizeof(sayilar[0]);
  ortalama = mean(sayilar, uzunluk);
  float recursive_ortalama = mean(sayilar, uzunluk);
  float varyans = recursive_var(sayilar, uzunluk) / (uzunluk - 1);

  printf("Ortalama           : %.2f\n", ortalama);
  printf("recursive_ortalama : %.2f\n", recursive_ortalama);
  printf("Varyans            : %.2f\n", varyans);
  printf("Standart Sapma     : %.2f\n", sqrt(varyans));

  return 0;
}
