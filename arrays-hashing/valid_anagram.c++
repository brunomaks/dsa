#include <iostream>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) {
        return false;
    }

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
