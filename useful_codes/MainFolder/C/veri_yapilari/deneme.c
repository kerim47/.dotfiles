#include <stdio.h>

void hanoi(int n, char kaynak, char hedef, char yardimci) {
  if (n == 1) {
    printf("Diski %c'den %c'ye tası\n", kaynak, hedef);
    return;
  }

  hanoi(n - 1, kaynak, yardimci, hedef);
  printf("Diski %c'den %c'ye tası %d\n", kaynak, hedef, n);
  hanoi(n - 1, yardimci, hedef, kaynak);
}

int main() {
  int diskSayisi;

  printf("Hanoi Kuleleri icin disk sayisini girin: ");
  scanf("%d", &diskSayisi);

  printf("Hanoi Kuleleri adimlari:\n");
  hanoi(diskSayisi, 'A', 'C', 'B');

  return 0;
}
