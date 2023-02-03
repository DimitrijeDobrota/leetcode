class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    vector<string> mat(numRows);

    int mode = 1, x = 0;
    for (char c : s) {
      mat[x].push_back(c);
      x += mode;
      if (x == numRows - 1 || x == 0) mode *= -1;
    }

    string res = "";
    for (const auto &r : mat) res += r;
    return res;
  }
};
