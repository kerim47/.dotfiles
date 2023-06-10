#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int size = 0;

void bubbleSort(int array[], int size) {
  int i, j, temp;

  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void selectionSort(int arr[], int n) {
  int i, j, min_idx;

  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;
    swap(&arr[min_idx], &arr[i]);
  }
}

void insertionSort(int array[], int size) {
  int i, j, key;
  for (i = 1; i < size; i++) {
    key = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = key;
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void merge(int array[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = array[left + i];
  for (j = 0; j < n2; j++)
    R[j] = array[mid + 1 + j];

  i = 0;
  j = 0;
  k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    array[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int array[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);

    merge(array, left, mid, right);
  }
}

void shellSort(int array[], int size) {
  int i, j, temp, gap;
  for (gap = size / 2; gap > 0; gap /= 2) {
    for (i = gap; i < size; i++) {
      temp = array[i];
      for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
        array[j] = array[j - gap];
      }
      array[j] = temp;
    }
  }
}

void heapify(int array[], int size, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < size && array[left] > array[largest])
    largest = left;

  if (right < size && array[right] > array[largest])
    largest = right;

  if (largest != i) {
    int temp = array[i];
    array[i] = array[largest];
    array[largest] = temp;

    heapify(array, size, largest);
  }
}

void heapSort(int array[], int size) {
  for (int i = size / 2 - 1; i >= 0; i--)
    heapify(array, size, i);

  for (int i = size - 1; i > 0; i--) {
    int temp = array[0];
    array[0] = array[i];
    array[i] = temp;

    heapify(array, i, 0);
  }
}

void *mergeSortThread(void *arg) {
  int *mergeArray = (int *)arg;
  clock_t start = clock();
  clock_t end = clock();
  double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Merge Sort çalışma süresi    : %f saniye\n", elapsed_time);
  pthread_exit(NULL);
}

void *shellSortThread(void *arg) {
  int *shellArray = (int *)arg;
  clock_t start = clock();
  clock_t end = clock();
  double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Shell Sort çalışma süresi    : %f saniye\n", elapsed_time);
  pthread_exit(NULL);
}

void *heapSortThread(void *arg) {
  int *heapArray = (int *)arg;
  clock_t start = clock();
  clock_t end = clock();
  double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Heap Sort çalışma süresi     : %f saniye\n", elapsed_time);
  pthread_exit(NULL);
}

void *bubbleSortThread(void *arg) {
  int *bubbleArray = (int *)arg;
  clock_t start = clock();
  bubbleSort(bubbleArray, size);
  clock_t end = clock();
  double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Bubble Sort çalışma süresi   : %f saniye\n", elapsed_time);
  pthread_exit(NULL);
}

void *quickSortThread(void *arg) {
  int *quickArray = (int *)arg;
  clock_t start = clock();
  quickSort(quickArray, 0, size - 1);
  clock_t end = clock();
  double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Quick Sort çalışma süresi    : %f saniye\n", elapsed_time);
  pthread_exit(NULL);
}

void *selectionSortThread(void *arg) {
  int *selectionArray = (int *)arg;
  clock_t start = clock();
  selectionSort(selectionArray, size);
  clock_t end = clock();
  double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Selection Sort çalışma süresi: %f saniye\n", elapsed_time);
  pthread_exit(NULL);
}

void *insertionSortThread(void *arg) {
  int *insertionArray = (int *)arg;
  clock_t start = clock();
  insertionSort(insertionArray, size);
  clock_t end = clock();
  double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Insertion Sort çalışma süresi: %f saniye\n", elapsed_time);
  pthread_exit(NULL);
}

int main() {
  printf("Dizi boyutunu girin: ");
  scanf("%d", &size);

  int array[size];

  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }

  int bubbleArray[size];
  int quickArray[size];
  int selectionArray[size];
  int insertionArray[size];
  int mergeArray[size];
  int shellArray[size];
  int heapArray[size];

  for (int i = 0; i < size; i++) {
    bubbleArray[i] = array[i];
    quickArray[i] = array[i];
    selectionArray[i] = array[i];
    insertionArray[i] = array[i];
    mergeArray[size] = array[i];
    shellArray[size] = array[i];
    heapArray[size] = array[i];
  }

  printf("\n-------------- Sonuçlar --------------\n");
  pthread_t threads[7];
  pthread_create(&threads[0], NULL, bubbleSortThread, (void *)bubbleArray);
  pthread_create(&threads[1], NULL, quickSortThread, (void *)quickArray);
  pthread_create(&threads[2], NULL, selectionSortThread,
                 (void *)selectionArray);
  pthread_create(&threads[3], NULL, insertionSortThread,
                 (void *)insertionArray);
  pthread_create(&threads[4], NULL, mergeSortThread, (void *)mergeArray);
  pthread_create(&threads[5], NULL, shellSortThread, (void *)shellArray);
  pthread_create(&threads[6], NULL, heapSortThread, (void *)heapArray);
  void *result;
  pthread_join(threads[0], &result);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);
  pthread_join(threads[3], NULL);
  pthread_join(threads[4], NULL);
  pthread_join(threads[5], NULL);
  pthread_join(threads[6], NULL);
  printf("--------------------------------------\n");
  return 0;
}

// int main() {
//   int size;
//   printf("Dizi boyutunu girin: ");
//   scanf("%d", &size);

//   int array[size];

//   srand(time(NULL));
//   for (int i = 0; i < size; i++) {
//     array[i] = rand() % 100;
//   }

//   // printf("\n-------- Orijinal Dizi ----------\n");
//   // printArray(array, size);
//   // printf("----------------------------------\n");

//   clock_t start, end;
//   double bubbleSort_time_elapsed;
//   double quick_time_elapsed;
//   double selection_time_elapsed;

//   int bubbleArray[size];
//   int quickArray[size];
//   int selectionArray[size];

//   for (int i = 0; i < size; i++) {
//     bubbleArray[i] = array[i];
//     quickArray[i] = array[i];
//     selectionArray[i] = array[i];
//   }

//   printf("\n-------------- Sonuçlar --------------\n");
//   start = clock();
//   bubbleSort(bubbleArray, size);
//   end = clock();
//   bubbleSort_time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

//   start = clock();
//   quickSort(quickArray, 0, size - 1);
//   end = clock();
//   quick_time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

//   start = clock();
//   selectionSort(selectionArray, size);
//   end = clock();
//   selection_time_elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

//   // printf("\n-------- Orijinal Dizi ----------\n");
//   // printArray(array, size);
//   // printf("\n----------------------------------\n");

//   // printf("\n---------- Bubble Sort -----------\n");
//   // printArray(bubbleArray, size);
//   // printf("Çalışma Süresi: %f saniye\n", cpu_time_used);
//   // printf("----------------------------------\n");

//   // printf("\n---------- Quick Sort ------------\n");
//   // printArray(quickArray, size);
//   // printf("Çalışma Süresi: %f saniye\n", cpu_time_used);
//   // printf("----------------------------------\n");

//   // printf("\n--------- Selection Sort ---------\n");
//   // printArray(selectionArray, size);
//   // printf("Çalışma Süresi: %f saniye\n", cpu_time_used);
//   // printf("----------------------------------\n");

//   printf("Bubble Sort Çalışma Süresi: %f saniye\n", bubbleSort_time_elapsed);
//   printf("Quick Sort Çalışma Süresi: %f saniye\n", quick_time_elapsed);
//   printf("Selection Sort Çalışma Süresi: %f saniye\n",
//   selection_time_elapsed);
//   printf("---------------------------------------\n");
//   return 0;
// }
// int main() {
//   pthread_t thread1, thread2, thread3;
//   int rc;

//   pthread_create(&thread1, NULL, function1, NULL);
//   pthread_create(&thread2, NULL, function2, NULL);
//   pthread_create(&thread3, NULL, function3, NULL);

//   // İlk olarak biten thread'ın tamamlanmasını bekleyin
//   void *result;
//   pthread_join(thread1, &result);
//   pthread_join(thread2, NULL);
//   pthread_join(thread3, NULL);

//   return 0;
// }
