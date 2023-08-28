class Solution {
    int dp[501];

  public:
    Solution() { memset(dp, 0xFF, sizeof(dp)); }
    int maxSumAfterPartitioning(const vector<int> &arr, const int k, int idx = 0) {
        if (idx == arr.size()) return 0;
        if (dp[idx] != -1) return dp[idx];

        int maxi = arr[idx];
        int res = maxi + maxSumAfterPartitioning(arr, k, idx + 1);
        for (int i = idx + 1; i < idx + k && i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
            res = max(res, (i - idx + 1) * maxi + maxSumAfterPartitioning(arr, k, i + 1));
        }

        return dp[idx] = res;
    }
};
