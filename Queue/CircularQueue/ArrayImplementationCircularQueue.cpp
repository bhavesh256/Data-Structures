#include <iostream>
using namespace std;
#define SIZE 5

int front = -1;
int rear = -1;
int arr[SIZE];

void enqueue(int val){
    if((rear+1)%SIZE == front){
        cout << "Overflow\n";
        return;
    }

    if(front == -1 && rear == -1){
        front = rear = 0;
    }
    else {
        rear = (rear+1)%SIZE;
    }
    arr[rear] = val;
}

int dequeue(){
    int dequeuedEle;
    if(front == -1){
        cout << "Underflow\n";
        return -1;
    }
    else if(front == rear){
        dequeuedEle = arr[front];
        front = rear = -1;
    }
    else{
        dequeuedEle = arr[front];
        front = (front+1)%SIZE;
    }
    return dequeuedEle;
}

void traverse(){
    if(front == -1 && rear == -1){
        cout << "Underflow\n";
        return;
    }

    int i = front;
    for(i; i!=rear; i=(i+1)%SIZE){
        cout << arr[i] << " ";
    }
    cout << arr[i] << '\n';
}

void peek(){
    if(front == -1 && rear == -1){
        cout << "Underflow\n";
        return;
    }
    cout << arr[front] << '\n';
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    // cout << dequeue() << '\n';
    // cout << dequeue() << '\n';
    // cout << dequeue() << '\n';
    traverse();
    peek();
}