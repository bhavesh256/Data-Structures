#include <iostream>
using namespace std;

#define MAX 5

int queue_arr[MAX];
int front = -1;
int rear = -1;

// Enqueue operation
void enqueue(int val) {

  // Overflow condition
  if (rear == MAX-1) {
    cout << "Overflow\n";
    return;
  }

  // If queue is empty
  if (front == -1 && rear == -1) {
    front = 0;
    rear = 0;
  } else {
    rear++;
  }

  queue_arr[rear] = val;
}

// Dequeue operation
int dequeue() {

  // Underflow condition
  if (front == -1) {
    cout << "Underflow\n";
    return-1;
  }

  int poppedData = queue_arr[front];

  // If only one element is present
  if (front == rear) {
    front = -1;
    rear = -1;
  } else {
    front++;
  }

  return poppedData;
}

// Traversal
void traversal() {

  // Empty queue condition
  if (front == -1) {
    cout << "Empty Queue\n";
    return;
  }

  for (int i = front; i <= rear; i++) {
    cout << queue_arr[i] << " ";
  }

  cout << endl;
}

// Peek operation
int peek() {

  // Underflow condition
  if (front == -1) {
    cout << "Underflow\n";
    return-1;
  }

  return queue_arr[front];
}

int main() {

  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);

  cout << "Queue: ";
  traversal();

  cout << "Deleted: " << dequeue() << '\n';
  cout << "Deleted: " << dequeue() << '\n';
  cout << "Deleted: " << dequeue() << '\n';

  cout << "Queue after deletion: ";
  traversal();

  // These will cause overflow because rear == MAX - 1
  enqueue(60);
  enqueue(70);
  enqueue(80);

  cout << "Queue after insertion: ";
  traversal();

  cout << "Peek: " << peek() << '\n';

  return 0;
}