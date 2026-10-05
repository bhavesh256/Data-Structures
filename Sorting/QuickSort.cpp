#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
  int pivot = arr[high];

  int i = low-1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i+1], arr[high]);

  return i+1;
}

void quickSort(int arr[], int low, int high) {
  if (low >= high)
    return;

  int pivotIndex = partition(arr, low, high);

  quickSort(arr, low, pivotIndex-1);
  quickSort(arr, pivotIndex+1, high);
}

int main() {
  int arr[] = {38, 27, 43, 3, 9, 82, 10};

  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort(arr, 0, n-1);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}