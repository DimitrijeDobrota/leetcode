class Solution {
  public:
    vector<int> findLonely(vector<int> &nums) {
        sort(begin(nums), end(nums));

        vector<int> res;
        const int n = nums.size() - 1;
        for (int i = 0; i <= n; i++) {
            if (i < n && nums[i] == nums[i + 1]) continue;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (i > 0 && nums[i] - 1 == nums[i - 1]) continue;
            if (i < n && nums[i] + 1 == nums[i + 1]) continue;
            res.push_back(nums[i]);
        }
        return res;
    }
};
