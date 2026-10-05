#include <iostream>
using namespace std;

struct Node {
    Node* prev;
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Forward Traversal — O(N)
void forwardTraversal(Node* head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Backward Traversal — O(N) if tail is available
void backwardTraversal(Node* tail) {

    Node* temp = tail;

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    cout << "NULL\n";
}

// Insert Front — O(1)
void insertFront(Node*& head, Node*& tail, int val) {

    Node* newNode = new Node(val);

    // Empty list
    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;

    head = newNode;
}

// Insert Back — O(N)
void insertBack(Node*& head, Node*& tail, int val) {

    Node* newNode = new Node(val);

    // Empty list
    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    tail = newNode;
}

// Insert Back Using Tail — O(1)
void insertBackUsingTail(Node*& head, Node*& tail, int val) {

    Node* newNode = new Node(val);

    // Empty list
    if (tail == NULL) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;

    tail = newNode;
}

// Insert at K-th Position — O(N)
void insertAtKth(Node*& head, Node*& tail, int val, int pos) {

    if (pos <= 0) {
        cout << "Invalid position\n";
        return;
    }

    Node* newNode = new Node(val);

    // Empty list
    if (head == NULL) {

        if (pos == 1) {
            head = tail = newNode;
        }
        else {
            cout << "Invalid position\n";
            delete newNode;
        }

        return;
    }

    // Insert at first position
    if (pos == 1) {

        newNode->next = head;
        head->prev = newNode;

        head = newNode;

        return;
    }

    Node* temp = head;
    int currPos = 1;

    // Move to node before required position
    while (currPos < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        currPos++;
    }

    // Invalid position
    if (currPos != pos - 1) {
        cout << "Invalid position\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    else {
        // Inserting at end
        tail = newNode;
    }

    temp->next = newNode;
}

// Delete Front — O(1)
void deleteFront(Node*& head, Node*& tail) {

    if (head == NULL) {
        cout << "Empty List\n";
        return;
    }

    Node* delNode = head;

    // Only one node
    if (head == tail) {
        head = tail = NULL;
    }
    else {
        head = head->next;
        head->prev = NULL;
    }

    delete delNode;
}

// Delete Back Using Tail — O(1)
void deleteBackUsingTail(Node*& head, Node*& tail) {

    if (tail == NULL) {
        cout << "Empty List\n";
        return;
    }

    Node* delNode = tail;

    // Only one node
    if (head == tail) {
        head = tail = NULL;
    }
    else {
        tail = tail->prev;
        tail->next = NULL;
    }

    delete delNode;
}

// Delete Back — O(N)
void deleteBack(Node*& head, Node*& tail) {

    if (head == NULL) {
        cout << "Empty List\n";
        return;
    }

    // Only one node
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    tail = temp->prev;
    tail->next = NULL;

    delete temp;
}

// Delete K-th Node — O(N)
void deleteKthNode(Node*& head, Node*& tail, int pos) {

    if (head == NULL || pos <= 0) {
        return;
    }

    // Delete first node
    if (pos == 1) {
        deleteFront(head, tail);
        return;
    }

    Node* temp = head;
    int currPos = 1;

    while (temp != NULL && currPos < pos) {
        temp = temp->next;
        currPos++;
    }

    // Position doesn't exist
    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }

    // Delete last node
    if (temp == tail) {
        deleteBackUsingTail(head, tail);
        return;
    }

    // Connect previous node
    temp->prev->next = temp->next;

    // Connect next node
    temp->next->prev = temp->prev;

    delete temp;
}

// Reverse — O(N)
void reverse(Node*& head, Node*& tail) {

    Node* temp = head;

    while (temp != NULL) {

        Node* nextNode = temp->next;

        // Swap next and prev
        temp->next = temp->prev;
        temp->prev = nextNode;

        temp = nextNode;
    }

    // Swap head and tail
    Node* tempHead = head;
    head = tail;
    tail = tempHead;
}

int main() {

    Node* head = new Node(10);
    Node* tail = head;

    head->next = new Node(20);
    head->next->prev = head;
    tail = tail->next;

    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    tail = tail->next;

    // Forward Traversal
    cout << "\nForward Traversal\n";
    forwardTraversal(head);

    // Backward Traversal
    cout << "\nBackward Traversal\n";
    backwardTraversal(tail);

    // Insert Front
    cout << "\nInsert Front\n";
    insertFront(head, tail, 9);
    forwardTraversal(head);

    // Insert Back
    cout << "\nInsert Back\n";
    insertBack(head, tail, 7);
    insertBack(head, tail, 2);
    forwardTraversal(head);
    backwardTraversal(tail);

    // Insert Back Using Tail
    cout << "\nInsert Back Using Tail\n";
    insertBackUsingTail(head, tail, 17);
    insertBackUsingTail(head, tail, 12);
    forwardTraversal(head);
    backwardTraversal(tail);

    // Insert at K-th Position
    cout << "\nInsert at K-th Position\n";
    insertAtKth(head, tail, 66, 4);
    forwardTraversal(head);

    // Delete Front
    cout << "\nDelete Front\n";
    deleteFront(head, tail);
    forwardTraversal(head);

    // Delete Back Using Tail
    cout << "\nDelete Back Using Tail\n";
    deleteBackUsingTail(head, tail);
    forwardTraversal(head);

    // Delete Back
    cout << "\nDelete Back\n";
    deleteBack(head, tail);
    forwardTraversal(head);

    // Delete K-th Node
    cout << "\nDelete K-th Node\n";
    deleteKthNode(head, tail, 6);
    forwardTraversal(head);

    // Reverse
    cout << "\nReverse\n";
    reverse(head, tail);
    forwardTraversal(head);
    backwardTraversal(tail);

    return 0;
}