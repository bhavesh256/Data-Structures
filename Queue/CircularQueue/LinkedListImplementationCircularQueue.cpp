#include <iostream>
using namespace std;

struct Node {
    Node *next;
    int data;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
Node *front = nullptr;
Node *rear = nullptr;

void traverse(){
    if(front == nullptr){
        cout << "Underflow\n";
        return;
    }
    Node *temp = front;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
}

void enqueue(int val){
    Node *newNode = new Node(val);

    if(front == nullptr){
        front = newNode;
        rear = newNode;
        rear->next = front;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    rear->next = front;
}

int dequeue() {
    if (front == nullptr) {
        cout << "Underflow\n";
        return -1;
    }

    Node *delNode = front;
    int dequeuedData = delNode->data;

    if (front == rear) {
        front = nullptr;
        rear = nullptr;
    }
    else {
        front = front->next;
        rear->next = front;
    }

    delete delNode;
    return dequeuedData;
}

int peek(){
    if(front == nullptr){
        cout << "Underflow\n";
        return -1;
    }

    return front->data;
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    traverse(); cout << '\n';
    cout << dequeue() << '\n';
    traverse(); cout << '\n';
    cout << peek() <<'\n';
}