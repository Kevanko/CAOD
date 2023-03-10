#include "header.h"

int getrand(int min, int max) {
  return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

// radixSort
//  Функция для поиска максимального числа в массиве
int getMax(uint32_t arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}
// Функция для сортировки массива по цифре
void countSort(uint32_t arr[], int n, int exp) {
  uint32_t *output = (uint32_t *)malloc(sizeof(uint32_t) * n);
  int i, count[10] = {0};

  // Считаем количество вхождений каждой цифры
  for (i = 0; i < n; i++) {
    count[(arr[i] / exp) % 10]++;
  }

  // Суммируем значения в count, чтобы получить позицию каждого элемента в
  // output
  for (i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  // Ставим элементы в правильном порядке в output
  for (i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  // Копируем отсортированный массив из output в arr
  for (i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

// Функция для сортировки массива по разрядам
void radixSort(uint32_t arr[], int n) {
  int m = getMax(arr, n);

  // Сортировка по цифрам
  for (int exp = 1; m / exp > 0; exp *= 10) {
    countSort(arr, n, exp);
  }
}

// Quick Sort
void swap(uint32_t *a, uint32_t *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(uint32_t arr[], int low, int high) {
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

void quickSort(uint32_t arr[], int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

// Odd-Even Sort
void oddEvenSort(uint32_t arr[], int n) {
  int sorted = 0;
  while (!sorted) {
    sorted = 1;
    for (int i = 1; i < n - 1; i += 2) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        sorted = 0;
      }
    }
    for (int i = 0; i < n - 1; i += 2) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        sorted = 0;
      }
    }
  }
}

