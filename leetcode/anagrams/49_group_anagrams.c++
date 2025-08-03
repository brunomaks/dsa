#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
  Iterate over each input string; O(n) where n is the number of strings
    Sort the string (sorted strings produce equal anagrams); O(k log k)
    Push sorted string to the map

  Reconstruct the result vector from the map; O(n)

// Note: Since the alphabet is limited to only lowercase English letters,
// we could use a counting sort or a frequency array to sort in O(k)

// Overall: Time Complexity: O(n*k log(k)); Space Complexity: O(n) due to hashmap;
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;


        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++) {
            string sorted = sort(strs[i]);
            map[sorted].push_back(strs[i]);
        }

        for(const auto& pair : map) {
            result.push_back(pair.second);
        }

        return result;
    }

    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> map;
        for (char c : s) map[c]++;
        for (char c : t) {
            if (map[c] == 0) return false;
        }
        return true;
    }

    // custom quicksort function - works fine for solving this problem
    string sort(string s) {
        if(s.length() <= 1) return s;

        char pivot = s[s.length() / 2];

        string less, greater, equal;
        for(char c : s) {
            if(c < pivot) less.push_back(c);
            else if(c > pivot) greater.push_back(c);
            else equal.push_back(c);
        }

        return sort(less).append(equal).append(sort(greater));
    }
};

void printVectorOfVectors(const vector<vector<string>>& vec) {
    cout << "[\n";
    for (const auto& group : vec) {
        cout << "  [ ";
        for (const auto& str : group) {
            cout << "\"" << str << "\" ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> expected = {
        {"eat", "tea", "ate"},
        {"tan", "nat"},
        {"bat"}
    };

    auto result = sol.groupAnagrams(input);
    printVectorOfVectors(result);
    printVectorOfVectors(expected);
    return 0;
}
