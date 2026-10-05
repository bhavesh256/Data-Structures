#include <iostream>
using namespace std;

struct Node {
  Node *prev;
  int data;
  Node *next;

  Node(int data) {
    prev = NULL;
    this->data = data;
    next = NULL;
  }
};

// Insert at Front
void insertFront(Node *&head) {

  Node *newNode = new Node(10);

  // Find tail
  Node *tail = head;

  while (tail->next != head) {
    tail = tail->next;
  }

  // Connect new node
  newNode->next = head;
  newNode->prev = tail;

  // Old head's previous becomes new node
  head->prev = newNode;

  // Tail's next becomes new head
  tail->next = newNode;

  // Update head
  head = newNode;
}

// Delete at End
void deleteEnd(Node *&head) {

  // Empty list
  if (head == NULL)
    return;

  // Only one node
  if (head->next == head) {
    delete head;
    head = NULL;
    return;
  }

  // Find tail
  Node *tail = head;

  while (tail->next != head) {
    tail = tail->next;
  }

  // New tail is previous node
  Node *newTail = tail->prev;

  // Connect new tail to head
  newTail->next = head;

  // Head points back to new tail
  head->prev = newTail;

  // Delete old tail
  delete tail;
}

// Traversal
void traverse(Node *head) {

  if (head == NULL)
    return;

  Node *temp = head;

  do {
    cout << temp->data << " <-> ";
    temp = temp->next;
  } while (temp != head);

  cout << "HEAD\n";
}

int main() {

  Node *head = NULL;

  // Create first node
  head = new Node(20);

  // Create second node
  Node *second = new Node(30);
  head->next = second;
  second->prev = head;

  // Create third node
  Node *third = new Node(35);
  second->next = third;
  third->prev = second;

  // Make it circular
  third->next = head;
  head->prev = third;

  cout << "Original:\n";
  traverse(head);

  insertFront(head);

  cout << "After insert front:\n";
  traverse(head);

  deleteEnd(head);

  cout << "After delete end:\n";
  traverse(head);

  return 0;
}