class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    function check = [&board](unordered_set<char> &us, int i, int j) {
      if (board[i][j] != '.' && us.count(board[i][j])) return false;
      us.insert(board[i][j]);
      return true;
    };

    unordered_set<char> us1, us2, us3;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++)
        if (!check(us1, i, j) || !check(us2, j, i) ||
            !check(us3, 3 * (i / 3) + (j / 3), 3 * (i % 3) + (j % 3)))
          return false;
      us1.clear();
      us2.clear();
      us3.clear();
    }
    return true;
  }
};
