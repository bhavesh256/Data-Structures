#include <iostream>
#include <vector>
using namespace std;

/*
1. Bubble Sort

Compare adjacent elements and swap them if they are in the wrong order.

Best Case: O(n) — already sorted (with optimization, bool isSorted;)
Average Case: O(n²)
Worst Case: O(n²) — reverse sorted
Space Complexity: O(1) — in-place
*/
void bubbleSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// 2. Selection Sort
void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n-1; i++) {
        int minIndex = i;

        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

// 3. Insertion Sort
void insertionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

// 4. Merge Sort
void merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> temp;

    int i = left;
    int j = mid+1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= right)
        temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[left+k] = temp[k];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left+(right-left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

// 5. Quick Sort
int partition(vector<int> &arr, int low, int high) {
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

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

// Display array
void display(const vector<int> &arr) {
    for (int x : arr)
        cout << x << " " ;
    cout << endl;
}

// Main function
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original Array: " ;
    display(arr);

// Choose any sorting algorithm

// bubbleSort(arr);
// selectionSort(arr);
// insertionSort(arr);
// mergeSort(arr, 0, arr.size() - 1);
    quickSort(arr, 0, arr.size()-1);

    cout << "Sorted Array: " ;
    display(arr);

    return 0;
}