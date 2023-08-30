class Solution {
  public:
    long long minimumReplacement(vector<int> &nums) {
        long long int res = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) continue;
            long long num = (nums[i] + nums[i + 1] - 1) / nums[i + 1];
            res += num - 1;
            nums[i] = nums[i] / num;
        }
        return res;
    }
};
