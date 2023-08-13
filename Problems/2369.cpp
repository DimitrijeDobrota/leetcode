class Solution {
  int8_t dp[100001];

public:
  Solution() { memset(dp, 0xFF, sizeof(dp)); }
  bool validPartition(const vector<int> &nums, int idx = 0) {
    if (idx == nums.size()) return true;
    if (idx == nums.size() - 1) return false;

    if (dp[idx] != -1) return dp[idx];

    if (nums[idx] == nums[idx + 1]) {
      if (validPartition(nums, idx + 2)) return dp[idx] = true;
    }

    if (idx == nums.size() - 2) return dp[idx] = false;

    if (nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]) {
      if (validPartition(nums, idx + 3)) return dp[idx] = true;
    }

    if (nums[idx] + 1 == nums[idx + 1] && nums[idx] + 2 == nums[idx + 2]) {
      if (validPartition(nums, idx + 3)) return dp[idx] = true;
    }

    return dp[idx] = false;
  }
};
