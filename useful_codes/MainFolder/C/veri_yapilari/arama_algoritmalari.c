#include <stdio.h>
#include <time.h>

int linearSearch(int array[], int size, int key) {
  for (int i = 0; i < size; i++) {
    if (array[i] == key) {
      return i; // Anahtar bulunduğunda indeksi döndür
    }
  }
  return -1; // Anahtar bulunamadıysa -1 döndür
}

int binarySearch(int array[], int low, int high, int key) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == key) {
      return mid; // Anahtar bulunduğunda indeksi döndür
    } else if (array[mid] < key) {
      low = mid + 1; // Arama aralığını sağ tarafa kaydır
    } else {
      high = mid - 1; // Arama aralığını sol tarafa kaydır
    }
  }
  return -1; // Anahtar bulunamadıysa -1 döndür
}

int main() {
  int array[] = {1, 5, 8, 12, 18, 20, 25, 30};
  int size = sizeof(array) / sizeof(array[0]);
  int key;

  printf("Aranacak anahtarı girin: ");
  scanf("%d", &key);

  clock_t start, end;
  double linear_time_elapsed, binary_time_elapsed;

  start = clock();
  int linear_result = linearSearch(array, size, key);
  end = clock();
  linear_time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

  if (linear_result == -1) {
    printf("Anahtar bulunamadı.\n");
  } else {
    printf("Anahtar %d, indeks %d'de bulundu.\n", key, linear_result);
  }

  start = clock();
  int binary_result = binarySearch(array, 0, size - 1, key);
  end = clock();
  binary_time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

  if (binary_result == -1) {
    printf("Anahtar bulunamadı.\n");
  } else {
    printf("Anahtar %d, indeks %d'de bulundu.\n", key, binary_result);
  }

  printf("Lineer Arama çalışma süresi: %f saniye\n", linear_time_elapsed);
  printf("Binary Arama çalışma süresi: %f saniye\n", binary_time_elapsed);

  return 0;
}
