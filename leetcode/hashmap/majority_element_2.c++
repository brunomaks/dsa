#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Extended Bayer-Moore Voting Algorithm
class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int n = nums.size();
    vector<int> result;
    int first = 0, second = 0;
    int firstCount = 0, secondCount = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] == first) {
        firstCount++;
      } else if (nums[i] == second) {
        secondCount++;
      } else if (firstCount == 0) {
        first = nums[i];
        firstCount = 1;
      } else if (secondCount == 0) {
        second = nums[i];
        secondCount = 1;
      } else {
        firstCount--;
        secondCount--;
      }
    }

    firstCount = 0;
    secondCount = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == first)
        firstCount++;
      else if (nums[i] == second)
        secondCount++;
    }

    // There can be at most 2 elements that satisfy the condition
    int baseline = n / 3;
    if (firstCount > baseline) {
      result.push_back(first);
    }
    if (secondCount > baseline) {
      result.push_back(second);
    }

    return result;
  }
};

// My attempt
// class Solution {
// public:
//   vector<int> majorityElement(vector<int>& nums) {
//     unordered_map<int, int> hashmap;
//
//     for(int i = 0; i < nums.size(); i++) {
//       hashmap[nums[i]]++;
//       if(hashmap.size() > 2) {
//         for(auto it = hashmap.begin(); it != hashmap.end();) {
//           it->second--;
//           if(it->second == 0) {
//             it = hashmap.erase(it);
//           } else {
//             ++it;
//           }
//         }
//       }
//     }
//
//     int baseline = nums.size() / 3; // max 2 elements that satisfy the
//     condition vector<int> res; for(const auto& [key, value] : hashmap) {
//       int count = 0;
//       for(int i = 0; i < nums.size(); i++) {
//         if(nums[i] == key) {
//           count++;
//         }
//       }
//       if(count > baseline) {
//         res.push_back(key);
//       }
//     }
//
//     return res;
//   }
// };

void print(const vector<int> &v) {
  for (const int &x : v) {
    cout << x << " ";
  }
  cout << endl;
}

int main(void) {
  Solution sol;

  // vector<int> input = { 1, 2, 1 };
  // vector<int> input = { 1, 2, 1, 2 };
  // vector<int> input = { 3, 2, 1, 2, 3 };
  // vector<int> input = { 1, 2, 3, 2, 3 };
  // vector<int> input = { 4, 4, 4, 4, 6, 7, 2, 2, 2, 2 };
  vector<int> input = {4, 4, 1, 2, 3, 5, 6, 7, 4, 4};

  print(sol.majorityElement(input));
  return 0;
}
