#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next = NULL;

    Node(int data) {
        this->data = data;
    }
};

// Traversal — O(N)
void traversal(Node* head) {

    if (head == NULL)
        return;

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "HEAD\n";
}

// Insert at Front — O(N)
void insertFront(Node*& head, int val) {

    Node* newNode = new Node(val);

    // Empty list
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }

    // Find last node
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    // Insert new node before head
    newNode->next = head;
    temp->next = newNode;

    // Update head
    head = newNode;
}

// Insert at Back — O(N)
void insertBack(Node*& head, int val) {

    Node* newNode = new Node(val);

    // Empty list
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }

    // Find last node
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    // Insert after last node
    newNode->next = head;
    temp->next = newNode;
}

// Delete Front — O(N)
void deleteFront(Node*& head) {

    // Empty list
    if (head == NULL)
        return;

    // Only one node
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    // Find last node
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    // Save node to delete
    Node* delNode = head;

    // Last node points to new head
    temp->next = head->next;

    // Move head
    head = head->next;

    delete delNode;
}

// Delete Back — O(N)
void deleteBack(Node*& head) {

    // Empty list
    if (head == NULL)
        return;

    // Only one node
    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    // Find second-last node
    Node* temp = head;

    while (temp->next->next != head) {
        temp = temp->next;
    }

    // Last node
    Node* delNode = temp->next;

    // Second-last points to head
    temp->next = head;

    delete delNode;
}

int main() {

    Node* head = NULL;

    // Create first node
    head = new Node(10);
    head->next = head;

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