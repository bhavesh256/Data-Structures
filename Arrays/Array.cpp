#include <iostream>
using namespace std;

#define SIZE 100

// Traversal — O(N)
void traverse(int arr[], int n) {

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  cout << '\n';
}

// Insert at Front — O(N)
void insertFront(int arr[], int &n, int val) {

  // Shift elements to the right
  for (int i = n; i > 0; i--) {
    arr[i] = arr[i-1];
  }

  arr[0] = val;
  n++;
}

// Insert at Back — O(1)
void insertBack(int arr[], int &n, int val) {

  arr[n] = val;
  n++;
}

// Insert at Position — O(N)
void insertAtPosition(int arr[], int &n, int val, int pos) {

  // Position starts from 1
  if (pos < 1 || pos > n+1) {
    cout << "Invalid position\n";
    return;
  }

  // Shift elements to the right
  for (int i = n; i >= pos; i--) {
    arr[i] = arr[i-1];
  }

  arr[pos-1] = val;
  n++;
}

// Delete from Front — O(N)
void deleteFront(int arr[], int &n) {

  if (n == 0) {
    cout << "Underflow\n";
    return;
  }

  // Shift elements to the left
  for (int i = 0; i < n-1; i++) {
    arr[i] = arr[i+1];
  }

  n--;
}

// Delete from Back — O(1)
void deleteBack(int arr[], int &n) {

  if (n == 0) {
    cout << "Underflow\n";
    return;
  }

  n--;
}

// Delete from Position — O(N)
void deleteAtPosition(int arr[], int &n, int pos) {

  if (n == 0) {
    cout << "Underflow\n";
    return;
  }

  // Position starts from 1
  if (pos < 1 || pos > n) {
    cout << "Invalid position\n";
    return;
  }

  // Shift elements to the left
  for (int i = pos-1; i < n-1; i++) {
    arr[i] = arr[i+1];
  }

  n--;
}

// Search — O(N)
int search(int arr[], int n, int val) {

  for (int i = 0; i < n; i++) {

    if (arr[i] == val) {
      return i;
    }
  }

  return-1;
}

// Update at Position — O(1)
void update(int arr[], int n, int pos, int val) {

  if (pos < 1 || pos > n) {
    cout << "Invalid position\n";
    return;
  }

  arr[pos-1] = val;
}

// Reverse — O(N)
void reverseArray(int arr[], int n) {

  int start = 0;
  int end = n-1;

  while (start < end) {

    swap(arr[start], arr[end]);

    start++;
    end--;
  }
}

int main() {

  int arr[SIZE] = {1, 2, 3, 4, 5, 6};

  // Number of elements currently present
  int n = 6;

  cout << "Original Array:\n";
  traverse(arr, n);

  // Insert Front
  cout << "\nInsert 0 at Front:\n";
  insertFront(arr, n, 0);
  traverse(arr, n);

  // Insert Back
  cout << "\nInsert 7 at Back:\n";
  insertBack(arr, n, 7);
  traverse(arr, n);

  // Insert at Position
  cout << "\nInsert 99 at Position 4:\n";
  insertAtPosition(arr, n, 99, 4);
  traverse(arr, n);

  // Delete Front
  cout << "\nDelete Front:\n";
  deleteFront(arr, n);
  traverse(arr, n);

  // Delete Back
  cout << "\nDelete Back:\n";
  deleteBack(arr, n);
  traverse(arr, n);

  // Delete at Position
  cout << "\nDelete Position 3:\n";
  deleteAtPosition(arr, n, 3);
  traverse(arr, n);

  // Search
  cout << "\nSearch 5:\n";

  int index = search(arr, n, 5);

  if (index != -1)
    cout << "Found at index: " << index << '\n';
  else
    cout << "Not Found\n";

  // Update
  cout << "\nUpdate Position 2 to 100:\n";
  update(arr, n, 2, 100);
  traverse(arr, n);

  // Reverse
  cout << "\nReverse:\n";
  reverseArray(arr, n);
  traverse(arr, n);

  return 0;
}