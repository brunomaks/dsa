#include <vector>
#include <iostream>

using namespace std;

// Boyer-Moore Majority Vote Algorithm
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int majorElem = nums[0];
    int count = 1;

    for(int i = 1; i < nums.size(); i++) {
      if(nums[i] == majorElem) {
        count++;
      } else {
        count--;
        if(count == 0) {
          majorElem = nums[i];
          count++;
        }
      }
    }

    return majorElem;

    }
};

int main(void) {
  Solution sol;

  vector<int> nums = { 2,2,1,1,1,2,2 };
  cout << sol.majorityElement(nums) << endl;

  return 0;
}
