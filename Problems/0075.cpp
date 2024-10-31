class Solution {
  public:
    void sortColors(vector<int> &nums) const {
        int i = 0, j = 0, k = size(nums) - 1;
        while (j <= k) {
            if (nums[j] < 1)
                swap(nums[i++], nums[j++]);
            else if (nums[j] > 1)
                swap(nums[j], nums[k--]);
            else
                j++;
        }
    }
};
