#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int l = 0;
    int h = nums.size() - 1;

    while(l <= h) {
      int i = (l + h) / 2;
      int m = nums[i];

      if(target > m) {
        l = i + 1;
      } else if(target < m) {
        h = i - 1;
      } else {
        return i;
      }
    }

    return -1;
  }
};

int main(void) {
  Solution sol;

  vector<int> nums = { -1,0,3,5,9,12 };

  cout << sol.search(nums, 12) << endl;
  return 0;
}
