class Solution {
    static int dp[6001][31];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int lastStoneWeightII(const vector<int> &stones, int total = 0, int crnt = 0) const {
        if (crnt == size(stones)) return total >= 0 ? total : INT_MAX;
        if (dp[total + 3000][crnt] != -1) return dp[total + 3000][crnt];
        return dp[total + 3000][crnt] = min(lastStoneWeightII(stones, total + stones[crnt], crnt + 1),
                                            lastStoneWeightII(stones, total - stones[crnt], crnt + 1));
    }
};

int Solution::dp[6001][31];
