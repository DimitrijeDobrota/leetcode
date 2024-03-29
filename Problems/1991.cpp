class Solution {
  public:
    int findMiddleIndex(vector<int> &nums) {
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); left += nums[i++]) {
            right -= nums[i];
            if (left == right) return i;
        }
        return -1;
    }
};
