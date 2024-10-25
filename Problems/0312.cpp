class Solution {
  public:
    int maxCoins(vector<int> &nums) const {
        nums.insert(begin(nums), 1);
        nums.push_back(1);

        const int n = size(nums);
        static int dp[303][303];

        // dp[i][j]: coins obtained from bursting all the balloons between index i and j (not including i or
        // j) dp[i][j] = max(nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]) (k in (i+1,j))

        memset(dp, 0x00, sizeof(dp));
        for (int d = 2; d < n; d++) {
            for (int l = 0; l < n - d; l++) {
                const int r = l + d;
                for (int k = l + 1; k < r; k++) {
                    dp[l][r] = max(dp[l][r], nums[l] * nums[k] * nums[r] + dp[l][k] + dp[k][r]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
