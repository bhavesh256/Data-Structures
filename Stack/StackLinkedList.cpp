#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
} *top = nullptr;

void push(int val){
    Node *newNode = new Node(val);
    if(newNode == nullptr){
        cout << "Memory allocation failed!\n";
        exit(1); // stop the program immediately
    }
    newNode->next = top;
    top = newNode;
}

int pop(){
    if(top == nullptr){
        cout << "Underflow\n";
        return -1;
    }

    Node *delNode = top;
    top = top->next;
    int popData = delNode->data;
    delete delNode;
    return popData;
}

int peek(){
    if(top == nullptr){
        cout << "Underflow\n";
        return -1;
    }
    return top->data;
}

bool isEmpty(){
    return top == nullptr;
}

int main(){
    push(10);
    push(20);
    push(30);
    cout << pop() << '\n';
    cout << peek() << '\n';
    isEmpty() ? cout << "Empty\n" : cout << "Not Empty\n";

    Node *temp = top; 
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}