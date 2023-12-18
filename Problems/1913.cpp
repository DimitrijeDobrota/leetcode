class Solution {
  public:
    int maxProductDifference(vector<int> &nums) const {
        sort(begin(nums), begin(nums) + 4);
        int a = nums[0], b = nums[1];
        int c = nums[2], d = nums[3];
        for (int i = 4; i < nums.size(); i++) {
            if (nums[i] > d) {
                c = d;
                d = nums[i];
            } else if (nums[i] > c) {
                c = nums[i];
            } else if (nums[i] < a) {
                b = a;
                a = nums[i];
            } else if (nums[i] < b) {
                b = nums[i];
            }
        }
        return c * d - a * b;
    }
};
