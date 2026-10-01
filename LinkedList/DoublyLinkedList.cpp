#include <iostream>
using namespace std;

struct Node {
    Node* prev = NULL;
    int data;
    Node* next = NULL;

    Node(int data){
        this->data = data;
    }
};

// Forward Traversal — O(N)
void forwardTraversal(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " — ";
        temp = temp->next;
    }
    cout << "null" << '\n';
}

// Backward Traversal — O(2N)
void backwardTraversal(Node *head){
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        cout << temp->data << " — ";
        temp = temp->prev;
    }
    cout << "null" << '\n';
}

// BAckward Traversal — O(N)
void backwardTraversalWithTail(Node *tail){
    Node *temp = tail;

    while(temp != NULL){
        cout << temp->data << " — ";
        temp = temp->prev;
    }
    cout << "null" << '\n';
}

// Insert Front — O(1)
void insertFront(Node *&head, int val){
    Node *newNode = new Node(val);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert Back — O(N)
void insertBack(Node *&head, Node *&tail, int val){
    
    Node *newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    tail = newNode;
}

// Insert Back — O(1)
void insertBackUsingTail(Node *&tail, int val){
    Node *newNode = new Node(val);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Insert at K-th position — O(N)
void insertAtKth(Node *&head, int val, int pos){
    Node *temp = head;
    Node *newNode = new Node(val);

    if(head == NULL) return;

    if(pos == 1){
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }

    int currPos = 1;
    while(currPos < pos-1){
        currPos++;
        temp = temp->next;      
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
} 

// Delete Front
void deleteFront(Node *&head){
    if(head == NULL) return;

    Node *temp = head;

    temp->next->prev = NULL;
    head = temp->next;
    delete temp;
}

// Delete Back Using Tail
void deleteBackUsingTail(Node *&tail){
    if(tail == NULL) return;

    Node *temp = tail;

    temp->prev->next = NULL;
    tail = temp->prev;
    delete temp;
}

// Delete Back
void deleteBack(Node *&head, Node *&tail){
    if(head == NULL) return;

    Node *temp = head;

    while(temp->next){
        temp=temp->next;
    }

    temp->prev->next = NULL;
    tail = temp->prev;
    delete temp;
}

// Delete k-th Node
void DeleteKthNode(Node *&head, int pos) {
    if (head == NULL || pos <= 0)
        return;

    if (pos == 1) {
        Node *delNode = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete delNode;
        return;
    }

    Node *temp = head;
    int currPos = 1;

    while (temp != NULL && currPos < pos) {
        temp = temp->next;
        currPos++;
    }

    // Position doesn't exist
    if (temp == NULL)
        return;

    Node *delNode = temp;

    // Connect previous node to next node
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    // Connect next node to previous node
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete delNode;
}

// Reverse 
void reverse(Node *&head, Node *&tail) {
    Node *temp = head;

    while (temp != NULL) {
        Node *nextNode = temp->next;

        temp->next = temp->prev;
        temp->prev = nextNode;

        temp = nextNode;
    }

    // Swap head and tail
    Node *tempHead = head;
    head = tail;
    tail = tempHead;
}

int main(){

    Node *head = new Node(10);
    Node *tail = head;

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
    cout << "\nBackward Terversal\n";
    backwardTraversal(head);

    // Backward Traversal Using tail
    cout << "\nBackward Terversal Using tail\n";
    backwardTraversalWithTail(tail);

    // Insert Front
    cout << "\nInsert Front\n";
    insertFront(head, 9);
    forwardTraversal(head);

    // Insert Back
    cout << "\nInsert Back\n";
    insertBack(head, tail, 7);
    insertBack(head, tail, 2);
    forwardTraversal(head);
    backwardTraversalWithTail(tail);

    // Insert Back
    cout << "\nInsert Back Using Tail\n";
    insertBackUsingTail(tail, 17);
    insertBackUsingTail(tail, 12);
    forwardTraversal(head);
    backwardTraversalWithTail(tail);

    // Insert at K-th Position
    cout << "\nInsert at k-th Position\n";
    insertAtKth(head, 66, 4);
    forwardTraversal(head);

    // Delete Front
    cout << "\nDelete Front\n";
    deleteFront(head);
    forwardTraversal(head);

    // Delete Back Using Tail
    cout << "\nDelete Front Using Tail\n";
    deleteBackUsingTail(tail);
    forwardTraversal(head);

    // Delete Back
    cout << "\nDelete Front\n";
    deleteBack(head, tail);
    forwardTraversal(head);   

    // Delete K-th Node
    cout << "\nDelete K-th Node\n";
    DeleteKthNode(head, 6);
    forwardTraversal(head);   

}