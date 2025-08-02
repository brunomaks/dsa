#include <iostream>
#include <vector>

using namespace std;

/*
  Validates a 9x9 Sudoku board.

  Strategy:
  - Use three 2D arrays to track occurrences of digits 1–9 in:
    * Rows:     row[9][9]
    * Columns:  col[9][9]
    * 3x3 Boxes: box[3][3][9]

  - Each digit is converted from char to index using: value = board[i][j] - '1' (range 0–8)

  - To identify which 3x3 box a cell belongs to, use integer division:
      box[i / 3][j / 3][value]

  - For each filled cell, we check if the digit has already been seen in:
    * that row:    if (row[i][value]++ > 0)
    * that column: if (col[j][value]++ > 0)
    * that box:    if (box[i / 3][j / 3][value]++ > 0)

    This works because:
    - The `++` operator increments **after** checking.
    - So if `row[i][value]` is 0 (unseen), the condition is false, and it's safe.
    - If it's already >0, that means the digit has appeared before => invalid.

  // Overall:
  // Time Complexity: O(1) — fixed size 9x9 board (81 cells)
  // Space Complexity: O(1) — three fixed-size 2D/3D arrays (constant memory)
*/

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
