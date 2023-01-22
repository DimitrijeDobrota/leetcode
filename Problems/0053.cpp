// memorization approach
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

// optimized, memorize only the previous value
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size(), maxi, prev;
    maxi = prev = nums[0];
    for (int i = 1; i < n; i++) maxi = max(maxi, prev = nums[i] + max(prev, 0));
    return maxi;
  }
};
