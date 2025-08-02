#include <stack>

// A simple stack data structure that maintains two stacks:
//                                              one for normal stack operations, and
//                                              another one for keeping track of the min element.

class MinStack {
public:
  MinStack() {}

  void push(int val) {
    stack.push(val);

    if(minStack.empty() || val <= minStack.top()) {
      minStack.push(val);
    }
  }

  void pop() {
    if(stack.top() == minStack.top()) {
      minStack.pop();
    }
    stack.pop();
  }

  int top() {
    return stack.top();
  }

  int getMin() {
    return minStack.top();
  }

private:
  std::stack<int> stack;
  std::stack<int> minStack;
};

int main(void) {
  MinStack* obj = new MinStack();

  obj->push(10);
  obj->pop();
  int param_3 = obj->top();
  int param_4 = obj->getMin();
}
