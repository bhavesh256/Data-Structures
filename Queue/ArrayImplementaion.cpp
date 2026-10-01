#include <iostream>
using namespace std;

#define MAX 5
int queue_arr[MAX];
int front = -1;
int rear = -1;

// [][][][][]

void enqueue(int val){
    if(rear == MAX-1){
        cout << "Overflow\n";
        return;
    }
    else if(front == -1 && rear == -1){
        front++;
    }
    rear++;
    queue_arr[rear] = val;
}

int dequeue(){
    if(front == -1 && rear == -1){
        cout << "Underflow\n";
        return -1;
    }
    int poppedData = queue_arr[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else front++;
    return poppedData;
}

void traversal(){
    if(front == -1 && rear == -1){
        cout << "Empty Queue\n";
        return;
    }
    for(int i=front; i<=rear; i++){
        cout << queue_arr[i] << " ";
    }
}

int peek(){
    if(front == -1 && rear == -1) return -1;
    return queue_arr[front];
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    cout << dequeue() << '\n';
    // cout << dequeue() << '\n';
    // cout << dequeue() << '\n';
    // cout << dequeue() << '\n';
    traversal(); cout << '\n';
    cout << peek() << '\n';
}