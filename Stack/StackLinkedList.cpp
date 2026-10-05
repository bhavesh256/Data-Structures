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

Node*top=nullptr;

// Push
void push(int val) {

    Node*newNode=new (nothrow) Node(val);

    // Overflow / memory allocation failure
    if (newNode==nullptr) {
        cout<<"Overflow: Memory allocation failed!\n";
        return;
    }

    newNode->next=top;
    top=newNode;
}

// Pop
int pop() {

    // Underflow
    if (top==nullptr) {
        cout<<"Underflow\n";
        return-1;
    }

    Node*delNode=top;

    int popData=delNode->data;

    top=top->next;

    delete delNode;

    return popData;
}

// Peek
int peek() {

    // Underflow
    if (top==nullptr) {
        cout<<"Underflow\n";
        return-1;
    }

    return top->data;
}

// Check if empty
bool isEmpty() {
    return top==nullptr;
}

// Traverse stack
void traverse() {

    if (top==nullptr) {
        cout<<"Empty Stack\n";
        return;
    }

    Node*temp=top;

    while (temp!=nullptr) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<'\n';
}

int main() {

    push(10);
    push(20);
    push(30);

    cout<<"Popped: "<<pop()<<'\n';

    cout<<"Top: "<<peek()<<'\n';

    if (isEmpty())
        cout<<"Empty\n";
    else
        cout<<"Not Empty\n";

    cout<<"Stack: ";
    traverse();

    return 0;
}