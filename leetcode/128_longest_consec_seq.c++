#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if(nums.size() < 1) {
        return 0;
      }
      unordered_set<int> hashset;

      for(int x : nums) {
        hashset.insert(x);
      }

      int counter = 0;
      int longest = 0;
      for(int i = 0; i < nums.size(); i++) {
        int curr = nums[i];
        counter = 0;

        if(hashset.find(curr - 1) == hashset.end()) {
          while(hashset.find(curr + 1) != hashset.end()) {
            counter++;
            curr++;
          }
          if(counter > longest) {
            longest = counter;
          }
        }
      }
      return longest + 1;
    }
};

int main(void) {
  Solution sol;

  vector<int> nums = { 100, 4, 200, 1, 3, 2 };
  cout << sol.longestConsecutive(nums);
  return 0;
}
