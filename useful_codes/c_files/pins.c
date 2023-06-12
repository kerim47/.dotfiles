#include <stdio.h>

void printPins(int pins) {
  for (int i = 0; i < 16; i++) {
    if (pins & (1 << i)) {
      printf("Pin %d: HIGH\n", i + 1);
    }
  }
}

int main() {
  int pin1 = 0x0001;  // Örnek olarak 1. pin seçildi
  int pin2 = 0x0002;  // Örnek olarak 2. pin seçildi
  int pin3 = 0x0004;  // Örnek olarak 3. pin seçildi
  int pin4 = 0x0008;  // Örnek olarak 3. pin seçildi
  int pin5 = 0x0010;  // Örnek olarak 3. pin seçildi
  int pin6 = 0x0020;  // Örnek olarak 3. pin seçildi
  int pin7 = 0x0040;  // Örnek olarak 3. pin seçildi
  int pin8 = 0x0080;  // Örnek olarak 3. pin seçildi
  int pin9 = 0x0100;  // Örnek olarak 3. pin seçildi
  int pin10 = 0x0200; // Örnek olarak 3. pin seçildi
  int pin11 = 0x0400; // Örnek olarak 3. pin seçildi
  int pin12 = 0x0800; // Örnek olarak 3. pin seçildi
  int pin13 = 0x1000; // Örnek olarak 3. pin seçildi
  int pin14 = 0x2000; // Örnek olarak 3. pin seçildi
  int pin15 = 0x4000; // Örnek olarak 3. pin seçildi
  int pin16 = 0x8000; // Örnek olarak 3. pin seçildi

  int pins = pin1 | pin2 | pin3 | pin4 | pin5 | pin6 | pin7 | pin8 | pin9 |
             pin10 | pin11 | pin12 | pin13 | pin14 | pin15 | pin16;

  printPins(pins);

  return 0;
}
