class Solution {
  public:
    int dominantIndex(vector<int> &nums) {
        int max1, max2, index;
        max1 = max2 = index = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max1) {
                index = i;
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] > max2) {
                max2 = nums[i];
            }
        }
        return 2 * max2 <= max1 ? index : -1;
    }
};
