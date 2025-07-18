#include <iostream>
#include <string>
#include <stack>

using namespace std;

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
