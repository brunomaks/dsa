#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
bool isValidSudoku(vector<vector<char>>& board) {
    int row[9][9] = {0};
    int col[9][9] = {0};
    int box[3][3][9] = {0};

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          int value = board[i][j] - '1'; // 0 to 8

          if (row[i][value]++ > 0) return false;
          if (col[j][value]++ > 0) return false;
          if (box[i / 3][j / 3][value]++ > 0) return false;
        }
      }
    }

    return true;
  }
};

int main(void) {
  Solution sol;

  vector<vector<char>> board = {
      {'5','3','.','.','7','.','.','.','.'},
      {'6','.','.','1','9','5','.','.','.'},
      {'.','9','8','.','.','.','.','6','.'},
      {'8','.','.','.','6','.','.','.','3'},
      {'4','0','.','8','.','3','.','.','1'},
      {'7','.','.','.','2','.','.','.','6'},
      {'.','6','.','.','.','.','2','8','.'},
      {'.','.','.','4','1','9','.','.','5'},
      {'.','.','.','.','8','.','.','7','9'}
  };
  cout << sol.isValidSudoku(board) << endl;
  return 0;
}
