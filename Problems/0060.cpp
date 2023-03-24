class Solution {
public:
  string getPermutation(int n, int k) {
    vector<char> avail = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int factorial = 1, pos;
    string res;
    for (int i = 1; i <= n; i++) factorial *= i;
    for (k--; n; n--) {
      factorial /= n;
      res += avail[pos = k / factorial], k -= pos * factorial;
      for (int i = pos; i < avail.size() - 1; i++) avail[i] = avail[i + 1];
    }
    return res;
  }
};
