#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next = NULL;

    Node(int data){
        this->data = data;
    }
};

void traversal(Node *head) {
    if (head == NULL)
        return;

    Node *temp = head;

    do {
        cout << temp->data << " — ";
        temp = temp->next;
    } while (temp != head);

    cout << "head" << '\n';
}

void insertFront(Node *&head, int val){
    Node *newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        head->next = head;
        return;
    }

    Node* temp = head;

    do {
        temp = temp->next;
    } while (temp->next != head);

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertBack(Node *&head, int val){
    Node *newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        head->next = head;
    }
    Node *temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
}

void deleteFront(Node *&head){
    if(head == NULL) return;

    if(head->next == head){
        delete head;
    }

    Node *temp = head;
    Node *delNode = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;
    delete delNode;
}

void deleteBack(Node *&head){
    if(head == NULL) return;

    if(head->next == head){
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }

    Node *delNode = temp->next;
    temp->next = head;
    delete delNode;
}

int main(){

    Node *head = NULL;
    head = new Node(10);
    head->next = head;
    // head->next = new Node(20);
    // head->next->next = new Node(30);
    // head->next->next->next = new Node(40);
    // head->next->next->next->next = head;

    cout << "\nTraversal\n";
    traversal(head);

    cout << "\nInsert Front\n";
    insertFront(head, 5);
    traversal(head);

    cout << "\nInsert Back\n";
    insertBack(head, 55);
    traversal(head);

    cout << "\nDelete Front\n";
    deleteFront(head);
    traversal(head);

    cout << "\nDelete Back\n";
    deleteBack(head);
    traversal(head);


    return 0;
}