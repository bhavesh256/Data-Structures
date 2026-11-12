#include <iostream>
#include <queue>
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

// in_order : L root R
void in_order(Node *&root) {
    if(root == nullptr) return;
    in_order(root->leftChild);
    cout << root->data << " ";
    in_order(root->rightChild);
}

// pre_order : root L R
void pre_order(Node* &root){
    if(root == nullptr) return;
    cout << root->data << " ";
    pre_order(root->leftChild);
    pre_order(root->rightChild);
}

// post_order : L R root
void post_order(Node* &root){
    if(root == nullptr) return;
    post_order(root->leftChild);
    post_order(root->rightChild);
    cout << root->data << " ";
}

/*
Level Order Traversal (using Queue)
    - Check if root == nullptr; if so, return immediately (empty tree).
    - Initialize an empty queue of node pointers: queue<Node*> q;
    - Push the root node into the queue: q.push(root);
    - Repeat the following steps while the queue is not empty (!q.empty()):
        - Store the front node of the queue in a temporary pointer: Node* curr = q.front();
        - Remove the front node from the queue: q.pop();
        - Process (print) the data of the current node: cout << curr->data << " ";
        - If the left child exists (curr->left != nullptr), push it into the queue: q.push(curr->left);
        - If the right child exists (curr->right != nullptr), push it into the queue: q.push(curr->right);
    - Terminate when the queue becomes empty
*/
void level_order(Node* &root){
    if(root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->leftChild != nullptr) q.push(curr->leftChild);
        if(curr->rightChild != nullptr) q.push(curr->rightChild);
    }
}

bool search(Node* &root, int key) {
    if(root == nullptr) return false;

    Node *temp = root;
    while(temp != nullptr){
        if(key == temp->data){
            return true;
        }
        else if(key < temp->data){
            temp = temp->leftChild;
        }
        else {
            temp = temp->rightChild;
        }
    }

    return false;
}

Node* iterative_searching_in_BST(Node* root, int key){
    while(root != nullptr && root->data != key){
        
        if(key < root->data){
            root = root->leftChild;
        } else {
            root = root->rightChild;
        }
    }
    return root;
}

Node* recursive_searching_in_BST(Node* root, int key){
    if(root == nullptr || root->data == key){
        return root;
    }
    if(key < root->data){
        return recursive_searching_in_BST(root->leftChild, key);
    }
    return recursive_searching_in_BST(root->rightChild, key);
}

Node* insert(Node* root, int val) {
    if(root == nullptr){
        return new Node(val);
    }

    if(val < root->data){
        root->leftChild = insert(root->leftChild, val);
    } else if(val > root->data){
        root->rightChild = insert(root->rightChild, val);
    }

    return root;
}

int main(){
    Node *root = new Node(10);
    root->leftChild = new Node(7);
    root->rightChild = new Node(15);
    root->leftChild->leftChild = new Node(5);
    root->leftChild->rightChild = new Node(8);
    root->rightChild->leftChild = new Node(13);

    cout << "In-order : ";
    in_order(root);
    cout << "\nPre-order : ";
    pre_order(root);
    cout << "\nPost-order : ";
    post_order(root);
    cout << "\nLevel-order : ";
    level_order(root);
    search(root, 13) ? cout << "\nfound\n" : cout << "\nnot found\n";
    cout << iterative_searching_in_BST(root, 13)->data << '\n';
    cout << recursive_searching_in_BST(root, 13)->data << '\n';


    // insertion
    Node* bst_root = nullptr;
    bst_root = insert(bst_root,10);
    insert(bst_root,4);
    insert(bst_root,14);
    insert(bst_root,24);
    insert(bst_root,2);

    cout << "In-order : ";
    in_order(bst_root);
}