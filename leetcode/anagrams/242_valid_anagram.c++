#include <iostream>
using namespace std;

/*
  If the string lengths differ - invalid anagram

  Iterate over the all characters in string_1; O(n)
    Increment the index at the character position

  Iterate over the all characters in string_2; O(n)
    Check if the index at the character position was incremented
      - if true: char exists in both
      - if false: char only exists in string_2 => return false;

// Overall: Time Complexity: O(n); Space Complexity: O(1) - constant size counter array
*/

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) {
        return false;
    }

    // Only supports lower case strings
    int freq[26] = { 0 };
    for(char x : s) {
        freq[x - 'a']++;
    }

    for(char x : t) {
        if(freq[x - 'a'] == 0) {
            return false;   
        }
        freq[x - 'a']--;
    }
    return true;
}

int main(void) {
  cout << isAnagram("anagram", "nagaram") << endl;
  return 0;
}
