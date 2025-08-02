#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
  Iterate over each token in the strings array; O(n)

    If its an operation token -> pop two values from the stack, perform the operation and push the value

    Else (its a value) -> push the value onto the stack for

  The last element on the stack is the valid computation according to Reverse Polish Notation

  // Time Complexity: O(n); Space Complexity: O(n) due to stack
*/

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> stack;

    for (const string &x : tokens) {
      if (x == "+") {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        stack.pop();

        stack.push(val1 + val2);
      } else if (x == "-") {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        stack.pop();

        stack.push(val2 - val1);
      } else if (x == "/") {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        stack.pop();

        stack.push(val2 / val1);
      } else if (x == "*") {
        int val1 = stack.top();
        stack.pop();
        int val2 = stack.top();
        stack.pop();

        stack.push(val1 * val2);
      } else {
        stack.push(stoi(x));
      }
    }

    return stack.top();
  }
};

int main(void) {
  Solution sol;

  vector<string> input = {"4", "13", "5", "/", "+"};

  cout << sol.evalRPN(input) << endl;
  return 0;
}
