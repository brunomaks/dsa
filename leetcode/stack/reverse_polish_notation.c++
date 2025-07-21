#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

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
