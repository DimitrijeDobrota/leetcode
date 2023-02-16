class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0), hsum = sum / 2;
    if (sum % 2) return false;
    vector<bool> dp(hsum + 1, false);

    dp[0] = true;
    for (int num : nums)
      for (int j = hsum; j >= num; j--)
        if (dp[j - num]) dp[j] = true;

    return dp.back();
  }
};
