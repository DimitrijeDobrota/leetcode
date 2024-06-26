class Solution {
  public:
    int maxWidthRamp(const vector<int> &nums) const {
        vector<pair<int, int>> vec;
        int res = 0;

        for (int i = 0; i < size(nums); i++) {
            if (empty(vec) || vec.back().first > nums[i])
                vec.emplace_back(nums[i], i);
            else {
                const auto opt = lower_bound(begin(vec), end(vec), make_pair(nums[i], INT_MAX), greater());
                res = max(res, i - opt->second);
            }
        }

        return res;
    }
};
