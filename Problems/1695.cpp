class Solution {
  public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
        const int n = nums.size();
        int left = 0, right = accumulate(begin(nums), end(nums), 0);
        for (int i = 0; i < n; ++i) {
            right -= nums[i], left += nums[i];
            nums[i] = right - left + (2 * i - n + 2) * nums[i];
        }
        return nums;
    }
};
