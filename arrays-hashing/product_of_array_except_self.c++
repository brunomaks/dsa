#include <iostream>
#include <vector>

using namespace std;


// Constraints: no division(/) operator, O(n) complexity
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    const int n = nums.size();
    vector<int> res(n);

    int prefix = 1;
    for(int i = 0; i < n; i++) {
      prefix *= nums[i];
      res[i] = prefix;
    }

    int suffix = 1;
    for(int i = n - 1; i > 0; i--) {
      res[i] = suffix * res[i - 1];
      suffix *= nums[i];
    }
    res[0] = suffix;


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

  vector<int> input = { 1, 2, 3, 4 };
  print(sol.productExceptSelf(input));

  return 0;
}
