#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("cikti olarak verildi : %d\n", i);
        fflush(stdout); // Çıktı tamponunu hemen temizleyin
    }
    return 0;
}

