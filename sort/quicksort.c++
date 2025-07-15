#include <iostream>
#include <string>
#include <functional>

using namespace std;

string qsort(const string& s, function<bool(char, char)> comparator) {
  if(s.length() <= 1) {
    return s;
  }

  int pivotIndex = s.length() / 2;
  char pivot = s[pivotIndex];

  string lessPivot, greaterPivot, equalPivot;
  for(int i = 0; i < s.length(); i++) {
    char current = s[i];
    if(comparator(current, pivot)) lessPivot.push_back(current);
    else if(comparator(pivot, current)) greaterPivot.push_back(current);
    else equalPivot.push_back(current);
  }

  return qsort(lessPivot, comparator) + equalPivot + qsort(greaterPivot, comparator);
}

int main(void) {
  cout << qsort("helloworld", [](char a, char b) -> bool { return a > b; }) << endl;
  return 0;
}
