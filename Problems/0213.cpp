class Solution {
public:
  // see 198. House Robber
  int rob_single(vector<int> &nums, int start, int end) {
    if (end - start <= 0) return 0;
    int prev1 = 0, prev2 = 0;
    for (int i = start; i < end; i++) {
      int tmp = prev1;
      prev1 = max(prev2 + nums[i], prev1);
      prev2 = tmp;
    }
    return prev1;
  }

  int rob(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    return max(nums[0] + rob_single(nums, 2, nums.size() - 1),
               rob_single(nums, 1, nums.size()));
  }
};
