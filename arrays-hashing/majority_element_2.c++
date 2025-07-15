#include <vector>
#include <iostream>

using namespace std;

// Boyer-Moore Majority Vote Algorithm
class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    int baseline = nums.size() / 3; // max 2 elements that satisfy the condition

    vector<int> res;

    int elem = 0;
    int count = 0;

    for(int i = 0; i < nums.size(); i++) {
      if(count == 0) {
        elem = nums[i];
        count = 1;
      } else if(elem == nums[i]) {
        count++;
      } else {
        count--;
      }
    }

    return res;
  }
};

void print(const vector<int>& v) {
  for(const int& x : v) {
    cout << x << " ";
  }
  cout << endl;
}


int main(void) {
  Solution sol;

  //vector<int> input = { 1, 2, 1 };
  vector<int> input = { 1, 2, 1, 2 };
  //vector<int> input = { 3, 2, 1, 2, 3 };
  //vector<int> input = { 1, 2, 3, 2, 3 };
  //vector<int> input = { 4, 4, 4, 4, 6, 7, 2, 2, 2, 2 };
  //vector<int> input = { 4, 4, 1, 2, 3, 5, 6, 7, 4, 4 };


  print(sol.majorityElement(input));
  return 0;
}
