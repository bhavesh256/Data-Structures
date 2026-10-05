#include <iostream>
#include <new>
using namespace std;

class StackArray {

private:
  int MAX;
  int TOP;
  int *stack_arr;

public:
  // Constructor
  StackArray(int MAX) {
    this->MAX = MAX;
    this->TOP = -1;

    stack_arr = new (nothrow) int[MAX];

    if (stack_arr == nullptr) {
      cout << "Overflow: Memory allocation failed\n";
      this->MAX = 0;
    }
  }

  // Destructor
  ~StackArray() { delete[] stack_arr; }

  // Push
  void push(int val) {

    // Overflow
    if (TOP == MAX-1) {
      cout << "Overflow\n";
      return;
    }

    TOP++;
    stack_arr[TOP] = val;
  }

  // Pop
  int pop() {

    // Underflow
    if (TOP == -1) {
      cout << "Underflow\n";
      return-1;
    }

    return stack_arr[TOP--];
  }

  // Peek
  int peek() {

    // Underflow
    if (TOP == -1) {
      cout << "Underflow\n";
      return-1;
    }

    return stack_arr[TOP];
  }

  // Check if stack is empty
  bool isEmpty() { return TOP == -1; }
};

int main() {

  StackArray st(4);

  st.push(10);
  st.push(30);
  st.push(20);
  st.push(40);

  cout << "Popped: " << st.pop() << '\n';

  cout << "Top: " << st.peek() << '\n';

  cout << "Is Empty: " << st.isEmpty() << '\n';

  return 0;
}