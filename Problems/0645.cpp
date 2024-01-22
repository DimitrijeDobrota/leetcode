class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) const {
        const int n = size(nums);
        int dbl = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            const int num = abs(nums[i]);
            if (nums[num - 1] < 0) dbl = num;
            nums[num - 1] = -nums[num - 1];
            sum += num;
        }
        return {dbl, n * (n + 1) / 2 - (sum - dbl)};
    }
};
