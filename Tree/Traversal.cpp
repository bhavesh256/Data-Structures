#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *leftChild;
    Node *rightChild;

    Node(int data){
        this->data = data;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
};

// inorder : L root R
void inorder(Node *&root) {
    if(root == nullptr) return;
    inorder(root->leftChild);
    cout << root->data << " ";
    inorder(root->rightChild);
}

// preorder : root L R
void preorder(Node* &root){
    if(root == nullptr) return;
    cout << root->data << " ";
    preorder(root->leftChild);
    preorder(root->rightChild);
}

// postorder : L R root
void postorder(Node* &root){
    if(root == nullptr) return;
    postorder(root->leftChild);
    postorder(root->rightChild);
    cout << root->data << " ";
}

int main(){
    Node *root = new Node(1);
    root->leftChild = new Node(2);
    root->rightChild = new Node(3);
    root->leftChild->leftChild = new Node(4);
    root->leftChild->rightChild = new Node(5);
    root->rightChild->leftChild = new Node(6);

    cout << "In-order : ";
    inorder(root);
    cout << "\nPre-order : ";
    preorder(root);
    cout << "\nPost-order : ";
    postorder(root);

}