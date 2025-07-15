#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for(int x : nums) {
            map[x]++;
        }

        vector<pair<int, int>> pairs(map.begin(), map.end());

        // descending order
        sort(pairs.begin(), pairs.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                  return a.second > b.second;
             });

        vector<int> res;

        for(int i = 0; i < k; i++) {
           res.push_back(pairs[i].first);
        }
        return res;
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
