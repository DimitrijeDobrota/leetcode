class Solution {
    static uint dp[11][301];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int minDifficulty(const vector<int> &jobDifficulty, int d, int idx = 0) const {
        if (d == 0) return (idx != jobDifficulty.size()) * UINT_MAX;
        if (jobDifficulty.size() - idx < d) return -1;
        if (dp[d][idx] != UINT_MAX) return dp[d][idx];
        uint res = UINT_MAX, maxi = 0;
        for (int i = idx; i < jobDifficulty.size(); i++) {
            maxi = max(maxi, (uint)jobDifficulty[i]);
            const int next = minDifficulty(jobDifficulty, d - 1, i + 1);
            if (next == UINT_MAX) continue;
            res = min(res, maxi + next);
        }
        dp[d][idx] = res != UINT_MAX ? res : res - 1;
        return res;
    }
};

uint Solution::dp[11][301];
