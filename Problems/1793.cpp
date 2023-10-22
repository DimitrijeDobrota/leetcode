class Solution {
  public:
    int maximumScore(const vector<int> &nums, int k) {
        const int n = nums.size();
        int left = k - 1, right = k + 1, res = nums[k], mini = nums[k];
        while (left >= 0 || right < n) {
            const int a = left >= 0 ? nums[left] : 0;
            const int b = right < n ? nums[right] : 0;
            mini = min(mini, a < b ? nums[right++] : nums[left--]);
            res = max(res, mini * (right - left - 1));
        }
        return res;
    }
};
