class Solution {
    static int dp[1001][1001];

    static int solve(const vector<int> &stones, int i, int j, int sum) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        const int a = sum - stones[i] - solve(stones, i + 1, j, sum - stones[i]);
        const int b = sum - stones[j] - solve(stones, i, j - 1, sum - stones[j]);

        return dp[i][j] = max(a, b);
    }

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int stoneGameVII(const vector<int> &stones) const {
        const int sum = accumulate(begin(stones), end(stones), 0);
        return solve(stones, 0, size(stones) - 1, sum);
    }
};

int Solution::dp[1001][1001];
