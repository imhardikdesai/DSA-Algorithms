#include <iostream>

template <typename A> void bubbleSort(A *array, unsigned int N) {
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        A temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main() {
  int arr[] = {5, 2, 6, 8, 3, 4};
  unsigned int N = 6;
  bubbleSort(arr, N);
  for (int i = 0; i < N; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
