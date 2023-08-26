class Solution {
  public:
    int longestSubarray(const vector<int> &nums) {
        int res = 0, left = 0, zero = -1, i;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i]) continue;
            res = max(res, i - left);
            left = zero + 1;
            zero = i;
        }
        return max(res, i - left) - 1;
    }
};
