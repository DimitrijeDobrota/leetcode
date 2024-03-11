class Solution {
  public:
    int minOperations(const vector<vector<int>> &grid, int x) const {
        static int dp[100001];
        vector<int> vec;

        for (const auto &row : grid)
            vec.insert(end(vec), begin(row), end(row));
        sort(begin(vec), end(vec));

        for (int i = 0, acc = 0; i < size(vec) - 1; i++) {
            const int crnt = vec[i + 1] - vec[i];
            if (crnt % x) return -1;
            dp[i + 1] = acc += (i + 1) * crnt;
        }

        int res = INT_MAX;
        for (int i = size(vec) - 1, acc = 0; i > 0; i--) {
            acc += (size(vec) - i) * (vec[i] - vec[i - 1]);
            res = min(res, acc + dp[i - 1]);
        }

        return res != INT_MAX ? res / x : 0;
    }
};
