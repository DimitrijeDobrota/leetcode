class Solution {
  int dp[21][21];

  int rec(const vector<int> &nums, int i, int j) {
    if (i == j) return nums[i];
    if (dp[i][j] != -1) return dp[i][j];

    int left = nums[i] - rec(nums, i + 1, j);
    int right = nums[j] - rec(nums, i, j - 1);

    return dp[i][j] = max(left, right);
  }

public:
  Solution() { memset(dp, 0xFF, sizeof(dp)); }

  bool PredictTheWinner(const vector<int> &nums) {
    return rec(nums, 0, nums.size() - 1) >= 0;
  }
};
