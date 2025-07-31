#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

// Insert all elements into a set for O(1) average lookups. (average cuz hash collisions can make it O(n) in the worst case)
//
// Iterate through each number in the array:
//
//     For each number num, check if num - 1 exists in the set.
//
//         If it does, skip it (since it's not the start of a sequence).
//
//         If it doesn't, it means num could be the start of a new sequence.
//
//             Initialize counter = 1, and while num + counter exists in the set, increment counter.
//
//     Track the maximum counter seen.

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
      int maxCounter = 0;
      for(int curr : nums) {
        counter = 0;

        if(hashset.find(curr - 1) == hashset.end()) { // IS NOT in the set
          counter = 1;
          while(hashset.find(curr + counter) != hashset.end()) { // IS in the set
            counter++;
          }
          if(counter > maxCounter) {
            maxCounter = counter;
          }
        }
      }
      return maxCounter;
    }
};

int main(void) {
  Solution sol;

  vector<int> nums = { 100, 4, 200, 1, 3, 2 };
  cout << sol.longestConsecutive(nums) << endl;
  return 0;
}
