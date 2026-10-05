#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

// Delete every second element
void deleteEverySecondElement(Node *&head) {

  if (head == nullptr)
    return;

  Node *temp = head;

  while (temp != nullptr && temp->next != nullptr) {

    // Node to be deleted
    Node *delNode = temp->next;

    // Skip the node to be deleted
    temp->next = temp->next->next;

    // Delete it
    delete delNode;

    // Move to next remaining node
    temp = temp->next;
  }
}

// Find length
int lengthOfLinkedList(Node *head) {

  Node *temp = head;
  int len = 0;

  while (temp != nullptr) {
    len++;
    temp = temp->next;
  }

  return len;
}

// Middle using length
// Returns FIRST middle for even length
int middleElement(Node *head) {

  if (head == nullptr) {
    cout << "Empty List\n";
    return-1;
  }

  int len = lengthOfLinkedList(head);

  int mid = (len-1) / 2;

  Node *temp = head;

  for (int i = 0; i < mid; i++) {
    temp = temp->next;
  }

  return temp->data;
}

// Middle using fast and slow pointers
// Returns FIRST middle for even length
int middleElementFastAndSlowPointers(Node *head) {

  if (head == nullptr) {
    cout << "Empty List\n";
    return-1;
  }

  Node *slow = head;
  Node *fast = head;

  // Move fast two steps and slow one step
  // until fast reaches the last node
  while (fast->next != nullptr && fast->next->next != nullptr) {

    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->data;
}

// Display linked list
void traverse(Node *head) {

  Node *temp = head;

  while (temp != nullptr) {
    cout << temp->data << " >> ";
    temp = temp->next;
  }

  cout << "NULL\n";
}

int main() {

  int n;
  cin >> n;

  Node *head = nullptr;
  Node *tail = nullptr;

  // Create linked list
  for (int i = 0; i < n; i++) {

    int val;
    cin >> val;

    Node *newNode = new Node(val);

    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  cout << "Original List: ";
  traverse(head);

  cout << "Length: " << lengthOfLinkedList(head) << '\n';

  cout << "Middle: " << middleElement(head) << '\n';

  cout << "Middle Fast and Slow Pointer: "
       << middleElementFastAndSlowPointers(head) << '\n';

  deleteEverySecondElement(head);

  cout << "After deleting every second element: ";
  traverse(head);

  return 0;
}