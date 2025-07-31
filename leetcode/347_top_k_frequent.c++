#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 1) Add all the elements to the hash map and count frequencies. O(n)
//
// 2) Create a bucket array where indexes are frequencies. O(n)
//
// 3) Push the first K elements to the return array. O(n) when k == n 
//
// Overall: Time Complexity: O(n); Space Complexity: O(n) due to map and vector;

class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> freq;

  for(int x : nums) {
    freq[x]++;
  }

  vector<vector<int>> buckets(nums.size() + 1); // index == frequency
  for(const auto& [num, count] : freq) {
    buckets[count].push_back(num);
  }

  vector<int> result;
  for(int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
    for(int num: buckets[i]) {
      result.push_back(num);
      if(result.size() == k) break;
    }
  }

  return result;
}
};

int main() {
  Solution sol;
  vector<int> input = { 1, 2, 3, 4, 5, 5};
  vector<int> res = sol.topKFrequent(input, 2);
  for(const auto& x : res) {
      cout << x << endl;
  }
  return 0;
}
