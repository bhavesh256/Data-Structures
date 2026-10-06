#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

// Traversal — O(N)
void traverse(Node *&head) {

  if(head == NULL){
    cout << "Underflow";
    return;
  }

  Node *temp = head;

  while (temp != NULL) {
    cout << temp->data << " >> ";
    temp = temp->next;
  }

  cout << "NULL\n";
}

// Reverse Linked List — O(N)
void reverse(Node *&head) {

  if(head == NULL){
    cout << "Underflow";
    return;
  }

  Node *prev = NULL;
  Node *curr = head;
  Node *next = NULL;

  while (curr != NULL) {

    next = curr->next;

    curr->next = prev;

    prev = curr;
    curr = next;
  }

  head = prev;
}

// Insert At HEAD — O(1)
void insertFront(Node *&head, int value) {

  Node *newNode = new Node(value);

  newNode->next = head;
  head = newNode;
}

// Insert At END — O(N)
void insertBack(Node *&head, int val) {

  Node *newNode = new Node(val);

  // Empty linked list
  if (head == NULL) {
    head = newNode;
    return;
  }

  Node *temp = head;

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;
}

// Insert At Position — O(N)
void insertMiddle(Node *&head, int val, int pos) {

  // Invalid position
  if (pos < 1) {
    cout << "Invalid position\n";
    return;
  }

  Node *newNode = new Node(val);

  // Empty list
  if (head == NULL) {

    if (pos == 1) {
      head = newNode;
    } else {
      cout << "Invalid position\n";
      delete newNode;
    }

    return;
  }

  // Insert at first position
  if (pos == 1) {
    newNode->next = head;
    head = newNode;
    return;
  }

  int curPos = 1;
  Node *temp = head;

  // Move to node before required position
  while (curPos < pos-1 && temp->next != NULL) {
    curPos++;
    temp = temp->next;
  }

  // Position does not exist
  if (curPos != pos-1) {
    cout << "Invalid position\n";
    delete newNode;
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

// Delete At START — O(1)
void deleteFront(Node *&head) {

  if (head == NULL) {
    cout << "Empty Linked List\n";
    return;
  }

  Node *temp = head;

  head = head->next;

  delete temp;
}void deleteBack(Node *&head) {

  // Empty list
  if (head == NULL) {
    cout << "Empty Linked List\n";
    return;
  }

  // Only one node
  if (head->next == NULL) {
    delete head;
    head = NULL;
    return;
  }

  Node *temp = head;

  // Stop at second-last node
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  // Save last node
  Node *delNode = temp->next;

  // Remove last node
  temp->next = NULL;

  // Delete last node
  delete delNode;
}

// Delete At END — O(N)
void deleteBack(Node *&head) {

  // Empty list
  if (head == NULL) {
    cout << "Empty Linked List\n";
    return;
  }

  // Only one node
  if (head->next == NULL) {
    delete head;
    head = NULL;
    return;
  }

  Node *temp = head;

  // Stop at second-last node
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  // Save last node
  Node *delNode = temp->next;

  // Remove last node
  temp->next = NULL;

  // Delete last node
  delete delNode;
}

// Delete At Position — O(N)
void deleteMiddle(Node *&head, int pos) {

  if (head == NULL) {
    cout << "Empty Linked List\n";
    return;
  }

  if (pos < 1) {
    cout << "Invalid position\n";
    return;
  }

  // Delete first node
  if (pos == 1) {
    Node *temp = head;

    head = head->next;

    delete temp;
    return;
  }

  int curPos = 1;
  Node *temp = head;

  // Move to node before position
  while (curPos < pos-1 && temp->next != NULL) {
    curPos++;
    temp = temp->next;
  }

  // Position does not exist
  if (temp->next == NULL) {
    cout << "Invalid position\n";
    return;
  }

  Node *delNode = temp->next;

  temp->next = delNode->next;

  delete delNode;
}

// Update At Position — O(N)
void updateMiddle(Node *&head, int pos, int newVal) {

  if (head == NULL) {
    cout << "Empty Linked List\n";
    return;
  }

  if (pos < 1) {
    cout << "Invalid position\n";
    return;
  }

  int curPos = 1;
  Node *temp = head;

  while (curPos < pos && temp != NULL) {
    curPos++;
    temp = temp->next;
  }

  // Position does not exist
  if (temp == NULL) {
    cout << "Invalid position\n";
    return;
  }

  temp->data = newVal;
}

// Length — O(N)
int length(Node *head) {

  int len = 0;
  Node *temp = head;

  while (temp != NULL) {
    len++;
    temp = temp->next;
  }

  return len;
}

int main() {

  Node *head = new Node(10);

  head->next = new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(40);

  // Traversal
  cout << "Traversal:\n";
  traverse(head);

  // Reverse
  cout << "\nReverse:\n";
  reverse(head);
  traverse(head);

  // Insert at front
  cout << "\nInsert Front:\n";
  insertFront(head, 99);
  traverse(head);

  // Insert Front — Empty LL
  cout << "\nInsert Front: Empty LL\n";

  Node *emptyFront = NULL;

  insertFront(emptyFront, 99);
  traverse(emptyFront);

  // Insert at end
  cout << "\nInsert End:\n";
  insertBack(head, 77);
  traverse(head);

  // Insert End — Empty LL
  cout << "\nInsert End: Empty LL\n";

  Node *emptyBack = NULL;

  insertBack(emptyBack, 99);
  traverse(emptyBack);

  // Insert at middle
  cout << "\nInsert Middle:\n";

  insertMiddle(head, 67, 1);
  insertMiddle(head, 22, 5);

  traverse(head);

  // Insert Middle — Empty LL
  cout << "\nInsert Middle: Empty LL\n";

  Node *emptyMiddle = NULL;

  insertMiddle(emptyMiddle, 67, 3);
  traverse(emptyMiddle);

  // Delete at front
  cout << "\nDelete Front:\n";

  deleteFront(head);
  traverse(head);

  // Delete at end
  cout << "\nDelete End:\n";

  deleteBack(head);
  traverse(head);

  // Delete at end — one element
  cout << "\nDelete End: One Element\n";

  Node *headOneEle = new Node(10);

  deleteBack(headOneEle);
  traverse(headOneEle);

  // Delete middle
  cout << "\nDelete Middle:\n";

  deleteMiddle(head, 3);
  traverse(head);

  // Update middle
  cout << "\nUpdate Middle:\n";

  updateMiddle(head, 3, 55);
  traverse(head);

  return 0;
}