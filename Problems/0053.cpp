class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size(), maxi;
    vector<int> dp(n);

    maxi = dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
      dp[i] = nums[i] + max(dp[i - 1], 0);
      maxi = max(maxi, dp[i]);
    }
    return maxi;
  }
};
