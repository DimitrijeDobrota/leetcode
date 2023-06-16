class Solution {
  vector<vector<long long>> table;
  const int MOD = 1E9 + 7;

  void generate(int numRows) {
    table.resize(numRows);
    table[0] = {1};
    for (int i = 1; i < numRows; i++) {
      table[i] = vector<long long>(i + 1);
      table[i][0] = table[i][i] = 1;
      for (int j = 1; j < i; j++) {
        table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
      }
    }
  }

  long long rec(const vector<int> &nums) {
    int n = nums.size();
    if (n <= 2) return 1;

    vector<int> l, r;
    for (int i = 1; i < n; i++) {
      (nums[i] < nums.front() ? l : r).push_back(nums[i]);
    }

    long long lr = rec(l) % MOD, rr = rec(r) % MOD;
    return (((table[n - 1][l.size()] * lr) % MOD) * rr) % MOD;
  }

public:
  int numOfWays(vector<int> &nums) {
    generate(nums.size() + 1);
    return rec(nums) % MOD - 1;
  }
};
