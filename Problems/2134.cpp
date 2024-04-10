class Solution {
  public:
    int minSwaps(const vector<int> &nums) const {
        const int total = accumulate(begin(nums), end(nums), 0);
        const int n = size(nums);

        if (total == n) return 0;

        int cnt = 0, res = INT_MAX;
        for (int i = 0; i < total; i++)
            cnt += nums[i];
        for (int j = 0, k = total; j < n; j++) {
            res = min(res, total - cnt);
            cnt += nums[k] - nums[j];
            if (++k == n) k = 0;
        }

        return res;
    }
};
