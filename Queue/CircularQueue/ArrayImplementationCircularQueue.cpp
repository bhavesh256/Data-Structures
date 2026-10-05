#include <iostream>
using namespace std;

#define SIZE 5

int front = -1;
int rear = -1;
int arr[SIZE];

// Enqueue
void enqueue(int val) {

  // Overflow condition
  if ((rear+1) % SIZE == front) {
    cout << "Overflow\n";
    return;
  }

  // Queue is empty
  if (front == -1 && rear == -1) {
    front = rear = 0;
  } else {
    rear = (rear+1) % SIZE;
  }

  arr[rear] = val;
}

// Dequeue
int dequeue() {

  // Underflow condition
  if (front == -1) {
    cout << "Underflow\n";
    return-1;
  }

  int dequeuedEle = arr[front];

  // Only one element
  if (front == rear) {
    front = rear = -1;
  } else {
    front = (front+1) % SIZE;
  }

  return dequeuedEle;
}

// Traverse
void traverse() {

  // Queue is empty
  if (front == -1) {
    cout << "Underflow\n";
    return;
  }

  int i = front;

  while (true) {
    cout << arr[i] << " ";

    if (i == rear)
      break;

    i = (i+1) % SIZE;
  }

  cout << '\n';
}

// Peek
void peek() {

  // Queue is empty
  if (front == -1) {
    cout << "Underflow\n";
    return;
  }

  cout << "Front element: " << arr[front] << '\n';
}

int main() {

  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);

  traverse();
  peek();

  cout << "Deleted: " << dequeue() << '\n';
  cout << "Deleted: " << dequeue() << '\n';

  enqueue(60);
  enqueue(70);

  cout << "Queue after deletion and insertion: ";
  traverse();

  peek();

  return 0;
}