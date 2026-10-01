#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Traversal — O(N)
void traverse(Node *&head){
    
    Node *temp = head;

    while(temp != NULL){
        cout << temp->data << " >> ";
        temp = temp->next;
    }
    cout << "NULL" <<'\n';
}

// Reverse

Node* reverseLL(Node *head){
    Node *prev = NULL;
    Node *curr = head;

    while(curr != NULL){
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reverse(Node *&head){
    Node *prev = NULL;
    Node *curr = head;

    while(curr != NULL){
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Insert At HEAD — O(1)
void insertFront(Node *&head, int value){
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Insert At End — O(N)
void insertBack(Node *&head, int val){
    Node *newNode = new Node(val);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert At Mid — O(N)
void insertMiddle(Node *&head, int val, int pos){
    Node *newNode = new Node(val);

    // if-Empty
    if(head == NULL) {
        head = newNode;
        return;
    }

    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }

    int curPos = 1;
    Node *temp = head;
    while(curPos < (pos-1) && temp->next != NULL){
        curPos++;
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at Start
void deleteFront(Node *&head){

    if(head == NULL){
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

// Delete at End
void deleteBack(Node *&head){

    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }

    temp->next = NULL;
    delete temp->next;
}

// Delete Middle
void deleteMiddle(Node *&head, int pos){
    if(head == NULL) return;

    if(pos == 1){
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    int curPos = 1;
    Node *temp = head;
    while(curPos < pos-1){
        curPos++;
        temp = temp->next;
    }
    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
}

// Update Middle
void updateMiddle(Node *&head, int pos, int newVal){
    if(head == NULL) return;

    if(pos == 1){
        head->data = newVal;
        return;
    }

    int curPos = 1;
    Node *temp = head;
    while(curPos < pos){
        curPos++;
        temp = temp->next;
    }
    temp->data = newVal;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Traversal
    cout << "Traversal" << '\n';
    traverse(head);

    // Reverse
    cout << "Reverse" << '\n';
    reverse(head);
    traverse(head);

    // Insert at the front
    cout << "Insert Front" << '\n';
    insertFront(head, 99);
    traverse(head);

    // What is Linked List is Empty
    cout << "Insert Front: Empty LL" << '\n';
    Node *emptyFront = NULL;
    insertFront(emptyFront, 99);
    traverse(emptyFront);

    // Insert at the End
    cout << "Insert End" << '\n';
    insertBack(head, 77);
    traverse(head);

    // What is Linked List is Empty
    Node *emptyBack = NULL;
    traverse(emptyBack);
    insertBack(emptyBack, 99);
    traverse(emptyBack);

    // Insert at the Middle
    cout << "Insert Middle" << '\n';
    insertMiddle(head, 67, 1);
    insertMiddle(head, 22, 5);
    traverse(head);

    // What is Linked List is Empty
    Node *emptyMiddle = NULL;
    traverse(emptyMiddle);
    insertMiddle(emptyMiddle, 67, 3);
    traverse(emptyMiddle);

    // Delete at the Front
    deleteFront(head);
    traverse(head);

    // Delete at the End
    deleteBack(head);
    traverse(head);

    // Delete at the End — 1 Element
    Node *headOneEle = new Node(10);
    deleteBack(headOneEle);
    traverse(headOneEle);

    // Delete at the Middle
    deleteMiddle(head, 3);
    traverse(head);

    // Update at the Middle
    updateMiddle(head, 3, 55);
    traverse(head);

}