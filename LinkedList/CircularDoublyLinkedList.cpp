#include <iostream>
using namespace std;

struct Node {
    Node *prev;
    int data;
    Node *next;

    Node(int data){
        prev = NULL;
        this->data = data;
        next = NULL;
    }
};

void insertFront(Node *&head){
    Node *newNode = new Node(10);

    Node *temp = head;
    

    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void deleteEnd(Node *&head){
    Node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->prev->next = head;
    delete temp;
}

int main(){
    Node *head = NULL;
    head = new Node(20);
    head->next = new Node(30);
    head->next->prev = head;
    head->next->next = new Node(35);
    head->next->next->prev = head->next;
    head->next->next->next = head;

    insertFront(head);
    deleteEnd(head);

    Node *temp = head;
    do{
        cout << temp->data << " — ";
        temp = temp->next;
    } while (temp != head);
}