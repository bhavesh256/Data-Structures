#include <iostream>
#include <new>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* front = nullptr;
Node* rear = nullptr;

// Traverse circular queue
void traverse() {

    // Underflow / empty queue
    if (front == nullptr) {
        cout << "Underflow\n";
        return;
    }

    Node* temp = front;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);

    cout << '\n';
}

// Enqueue
void enqueue(int val) {

    // Create new node
    Node* newNode = new (nothrow) Node(val);

    // Overflow condition
    if (newNode == nullptr) {
        cout << "Overflow\n";
        return;
    }

    // If queue is empty
    if (front == nullptr) {
        front = newNode;
        rear = newNode;

        // Circular connection
        rear->next = front;

        return;
    }

    // Insert at rear
    rear->next = newNode;
    rear = newNode;

    // Maintain circular connection
    rear->next = front;
}

// Dequeue
int dequeue() {

    // Underflow condition
    if (front == nullptr) {
        cout << "Underflow\n";
        return -1;
    }

    Node* delNode = front;
    int dequeuedData = delNode->data;

    // Only one node
    if (front == rear) {
        front = nullptr;
        rear = nullptr;
    }
    else {
        front = front->next;

        // Maintain circular connection
        rear->next = front;
    }

    delete delNode;

    return dequeuedData;
}

// Peek
int peek() {

    // Underflow condition
    if (front == nullptr) {
        cout << "Underflow\n";
        return -1;
    }

    return front->data;
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    cout << "Queue: ";
    traverse();

    cout << "Deleted: " << dequeue() << '\n';

    cout << "Queue after deletion: ";
    traverse();

    cout << "Front element: " << peek() << '\n';

    return 0;
}