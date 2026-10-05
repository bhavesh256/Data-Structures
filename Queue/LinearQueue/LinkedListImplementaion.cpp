#include <iostream>
#include <new>
using namespace std;

struct Node {
    int data;
    Node*next;

    Node(int data) {
        this->data=data;
        this->next=nullptr;
    }
};

Node*front=nullptr;
Node*rear=nullptr;

// Traverse the queue
void traverse() {
    if (front==nullptr) {
        cout<<"Queue is empty";
        return;
    }

    Node*temp=front;

    while (temp!=nullptr) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// Enqueue operation
void enqueue(int val) {
    Node*newNode=new (nothrow) Node(val);

    // Overflow condition
    if (newNode==nullptr) {
        cout<<"Overflow: Memory allocation failed!"<<endl;
        return;
    }

    // Queue is empty
    if (front==nullptr) {
        front=newNode;
        rear=newNode;
        return;
    }

    // Insert at rear
    rear->next=newNode;
    rear=newNode;
}

// Dequeue operation
void dequeue() {
    // Underflow condition
    if (front==nullptr) {
        cout<<"Underflow: Queue is empty!"<<endl;
        return;
    }

    Node*delNode=front;
    front=front->next;

    // If queue becomes empty
    if (front==nullptr) {
        rear=nullptr;
    }

    delete delNode;
}

// Peek operation
int peek() {
    // Underflow condition
    if (front==nullptr) {
        cout<<"Underflow: Queue is empty!"<<endl;
        return-1;
    }

    return front->data;
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout<<"Queue: ";
    traverse();
    cout<<endl;

    dequeue();
    enqueue(40);
    dequeue();

    cout<<"Queue after operations: ";
    traverse();
    cout<<endl;

    cout<<"Front element: "<<peek()<<endl;

    dequeue();
    dequeue();
    dequeue();   // Underflow

    return 0;
}