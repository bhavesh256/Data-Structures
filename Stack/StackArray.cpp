#include <iostream>
using namespace std;

struct StackArray{

private:
    int MAX;
    int TOP = -1;
    int *stack_arr;

public:
    StackArray(int MAX){
        this->MAX = MAX;
        stack_arr = new int[MAX];
    }
    ~StackArray(){
        delete[] stack_arr;
    }

    void push(int val){
    
        if(TOP == MAX-1){
            cout << "Overflow\n";
            return;
        }
        TOP++;
        stack_arr[TOP] = val;
    }

    int pop(){
        if(TOP == -1){
            cout << "Underflow";
            return -1;
        }
        
        return stack_arr[TOP--];   
    }

    int peek(){
        if(TOP == -1){
            cout << "Underflow";
            return -1;
        }
        return stack_arr[TOP];
    }

    bool isEmpty(){
        return TOP == -1;
    }
};

int main(){
    StackArray st(4);
    st.push(10);
    st.push(30);
    st.push(20);
    st.push(40);
    cout << st.pop() << '\n';
    cout << st.peek() << '\n';
    cout << st.isEmpty() << '\n';
}