#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next = NULL;

    Node(int data){
        this->data = data;
    }
};

void deleteEverySecondElement(Node *&head){

    if(head == NULL) return;

    Node *temp = head;
    while(temp != NULL && temp->next != NULL){
        // why temp->next != NULL && temp != NULL ?     Dry run 1 2 3
        Node *delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        temp = temp->next;
    }
}

// Order matters: check temp first before accessing temp->next
// because temp->next will cause a segmentation fault if temp == NULL.
// while(temp != NULL && temp->next != NULL)

int lengthOfLinkedList(Node *head){
    Node *temp = head;

    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }

    return len;
}

int middleElement(Node *head){
    int len = lengthOfLinkedList(head);
    int mid = (len - 1)/2;
    int count = 0;
    Node *temp = head;
    while(count < mid){
        count++;
        temp = temp->next;
    }

    return temp->data;
}

int middleElementFastAndSlowPointers(Node *head){
    Node *fast = head;
    Node *slow = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;
}

int main(){

    int n;
    cin >> n;

    Node *head = NULL;

    for(int i=1; i<=n; i++){
        int val;
        cin >> val;
        Node *newNode = new Node(val);

        if(head == NULL){
            head = newNode;
        }
        else {
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    cout << "Length: " << lengthOfLinkedList(head) << '\n';
    cout << "Middle: " << middleElement(head) << '\n';
    cout << "Middle Fast and Slow Pointer: " << middleElementFastAndSlowPointers(head) << '\n';

    deleteEverySecondElement(head);

    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " >> ";
        temp = temp->next;
    }
    cout << "null" << '\n';
}