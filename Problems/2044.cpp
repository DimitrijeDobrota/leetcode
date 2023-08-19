class Solution {
  int rec(const vector<int> &nums, const int maxi, int crnt = 0, int idx = 0) {
    if (idx == nums.size()) return crnt == maxi;
    if (crnt == maxi) return 1 << (nums.size() - idx);
    return rec(nums, maxi, crnt, idx + 1) +
           rec(nums, maxi, crnt | nums[idx], idx + 1);
  }

public:
  int countMaxOrSubsets(const vector<int> &nums) {
    int maxi = 0;
    for (int n : nums) maxi |= n;
    return rec(nums, maxi);
  }
};
