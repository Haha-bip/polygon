#include <iostream>
void Quicksort(int* array, int size) {
  int left = 0;
  int right = size - 1;
  int middle = array[rand() % size];
  do {
    while (array[left] < middle) {
      left++;
    }
    while (array[right] > middle) {
      right--;
    }
    if (left <= right) {
      int temporary = array[left];
      array[left] = array[right];
      array[right] = temporary;
      left++;
      right--;
    }
  } while (left <= right);
  if (right > 0) {
    Quicksort(array, right + 1);
  }
  if (left < size) {
    Quicksort(&array[left], size - left);
  }
}

int main() {
  int number;
  std::cin >> number;
  int* array = new int[number];
  for (int count = 0; count < number; count++) {
    std::cin >> array[count];
  }
  Quicksort(array, number);
  for (int count = 0; count < number; count++) {
    std::cout << array[count] << " ";
  }
  delete[] array;
}