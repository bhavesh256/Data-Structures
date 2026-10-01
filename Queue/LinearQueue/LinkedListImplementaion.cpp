#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node *front = nullptr;
Node *rear = nullptr;

void traverse(){
    Node *temp = front;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void enqueue(int val){
    Node *newNode = new Node(val);

    if(front == nullptr && rear == nullptr){
        front = newNode;
        rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = rear->next;
}

void dequeue(){
    if(front == nullptr){
        cout << "Underflow";
        return;
    }

    Node *delNode = front;
    front = front->next;

    if(front == nullptr){
        rear = nullptr;
    }

    delete delNode;
}

int peek(){
    if(front == nullptr && rear == nullptr){
        cout << "Underflow";
        return -1;
    }

    return front->data;
}

int main(){

    enqueue(10); 
    enqueue(20);
    enqueue(30);
    traverse(); cout << '\n';
    dequeue();
    enqueue(40);
    dequeue();
    traverse(); cout << '\n';
    cout << peek() << endl;
    
}