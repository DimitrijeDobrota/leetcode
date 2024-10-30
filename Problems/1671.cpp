class Solution {
  public:
    int minimumMountainRemovals(const vector<int> &nums) const {
        static int left[1001], right[1001];
        const int n = size(nums);
        vector<int> vec;
        int res = 0;

        for (int i = 0; i < n; i++) {
            const auto it = lower_bound(begin(vec), end(vec), nums[i]);
            left[i] = distance(begin(vec), it);
            if (it != end(vec))
                *it = nums[i];
            else
                vec.push_back(nums[i]);
        }

        vec.clear();
        for (int i = n - 1; i >= 0; i--) {
            const auto it = lower_bound(begin(vec), end(vec), nums[i]);
            right[i] = distance(begin(vec), it);
            if (it != end(vec))
                *it = nums[i];
            else
                vec.push_back(nums[i]);

            if (!left[i] || !right[i]) continue;
            res = max(res, left[i] + right[i]);
        }

        return n - res - 1;
    }
};
