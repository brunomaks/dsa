#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

// Insert all elements into a set for O(1) average lookups. O(n)
// (average-case because hash collisions can degrade to O(n) worst-case)
//
// Iterate through each number in the array: O(n)
//
//   For each number num, check if num - 1 exists in the set.
//
//     If it does, skip it (since it's not the start of a sequence).
//
//     If it doesn't, it means num could be the start of a new sequence.
//
//       Initialize counter = 1, and while num + counter exists in the set, increment counter. O(n - 1)
//       However, the while loop runs O(n) in total, not O(n) per element, so the overall complexity does NOT become O(n^2)
//
//       Track the maximum counter seen.
//
// Overall: Time Complexity: O(n) average case, O(n^2) worst-case due to hash collisions;
// Space Complexity: O(n) for the hash set

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

      int maxCounter = 0;
      for(int curr : nums) {

        // If leetcode says time limit exceeded, use .count() instead of .find() == .end()
        if(hashset.find(curr - 1) == hashset.end()) { // IS NOT in the set
          int counter = 1;
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
