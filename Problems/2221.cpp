class Solution {
public:
  int triangularSum(vector<int> &nums) {
    for (int k = 0; k < nums.size() - 1; k++) {
      for (int i = 1; i < nums.size() - k; i++) {
        nums[i - 1] = (nums[i - 1] + nums[i]) % 10;
      }
    }
    return nums.front();
  }
};
