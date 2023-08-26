class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size(), k, l;
        for (k = n - 2; k >= 0 && nums[k] >= nums[k + 1]; k--)
            ;

        if (k >= 0) {
            for (l = n - 1; l > k && nums[l] <= nums[k]; l--)
                ;
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        } else {
            reverse(nums.begin(), nums.end());
        }
    }
};
