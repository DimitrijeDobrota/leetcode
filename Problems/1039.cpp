class Solution {
    static int dp[51][51];

    static int solve(const int *data, int low, int high) {
        if (high - low < 2) return 0;
        if (dp[low][high] != -1) return dp[low][high];
        int res = INT_MAX;
        if (high - low == 2)
            res = data[low] * data[low + 1] * data[low + 2];
        else {
            const int base = data[low] * data[high];
            for (int i = low + 1; i < high; i++) {
                res = min(res, base * data[i] + solve(data, low, i) + solve(data, i, high));
            }
        }
        return dp[low][high] = res;
    }

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int minScoreTriangulation(const vector<int> &values) const {
        return solve(values.data(), 0, size(values) - 1);
    }
};

int Solution::dp[51][51];
