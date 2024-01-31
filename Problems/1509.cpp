class Solution {
  public:
    int minDifference(vector<int> &nums) const {
        const int n = size(nums);
        if (n <= 4) return 0;
        partial_sort(begin(nums), begin(nums) + 4, end(nums));
        nth_element(begin(nums) + 4, end(nums) - 4, end(nums));
        sort(end(nums) - 4, end(nums));
        return min({
            nums[n - 1] - nums[3],
            nums[n - 2] - nums[2],
            nums[n - 3] - nums[1],
            nums[n - 4] - nums[0],
        });
    }
};
