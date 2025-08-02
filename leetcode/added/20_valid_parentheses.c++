#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
  Validates if a string of parentheses is valid

  Iterate over each char in the input string; O(n)
    If its an opening parenthes -> push onto the stack

    If its a closing parenthes:
      and if its the first element in the input -> return false

      peek the curr top element from the stack

      if the element peeked is not a matching opening parenthes -> return false
      else remove the opening parenthes from the stack and move on

    If after removal off all the matching pairs the stack is not empty(more opening than closing parenthes) -> return false

    return true otherwise

    // Time Complexity: O(n), Space Complexity: O(n) due to stack
*/

class Solution {
public:
  bool isValid(string s) {
    if(s.length() <= 1) {
      return false;
    }
    stack<char> stack;

    for(char x : s) {
      if(x == '(' || x == '{' || x == '[') {
        stack.push(x);
      } else {
        if(stack.size() < 1) {
          return false;
        }
        char c = stack.top();
        switch(x) {
          case ')': 
            if(c != '(') return false;
            break;
          case '}': 
            if(c != '{') return false;
            break;
          case ']': 
            if(c != '[') return false;
            break;
        }
        stack.pop();
      }
    }

    if(stack.size() != 0) {
      return false;
    }

    return true;
  }
};


int main(void) {
  Solution sol;

  //string input = "()";
  string input = "(){}[]";
  cout << sol.isValid(input) << endl;

  return 0;
}
