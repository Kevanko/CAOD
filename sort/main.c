#include "functions.c"

int main() {
  int PrintArrays = 0;
  int step = 50000;
  int steps = 20;
  int n = step;
  int min_rand = 0, max_rand = 100000;

  char *result_str = (char *)malloc(200 * steps);
  int size_str = 0;

  printf("Size\t\tRadix\t\tQuic\t\tOddEven\n");
  sprintf(result_str, "Size\t\tRadix\t\tQuic\t\tOddEven\n");

  for (; n <= step * steps; n += step) {

    int *radix_arr = (int *)malloc(sizeof(int) * n);
    int *quick_arr = (int *)malloc(sizeof(int) * n);
    int *oddEven_arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
      int tmp = getrand(min_rand, max_rand);
      radix_arr[i] = tmp;
      quick_arr[i] = tmp;
      oddEven_arr[i] = tmp;
    }

    double start;
    double func_time[3] = {0.f, 0.f, 0.f};

    start = wtime();
    radixSort(radix_arr, n);
    func_time[0] = wtime() - start;

    start = wtime();
    quickSort(quick_arr, 0, n - 1);
    func_time[1] = wtime() - start;

    start = wtime();
    oddEvenSort(oddEven_arr, n);
    func_time[2] = wtime() - start;
    if (PrintArrays) {
      printf("\nRadixSort\tQuickSort\tNoddEvenSort: \n");
      for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d \n", radix_arr[i], quick_arr[i], oddEven_arr[i]);
      }
    }
    printf("%d\t\t%f\t%f\t%f \n", n, func_time[0], func_time[1], func_time[2]);
    size_str = strlen(result_str);
    sprintf(result_str + size_str, "%d\t\t%f\t%f\t%f \n", n, func_time[0],
            func_time[1], func_time[2]);
  }
  FILE *file = fopen("sort.dat", "w");
  fprintf(file, result_str);
  fclose(file);
  return 0;
}
