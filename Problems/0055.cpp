class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int n = nums.size(), limit = 0;
        for (int i = 0; i <= limit && i < n; i++)
            limit = max(limit, i + nums[i]);
        return limit >= n - 1;
    }
};
