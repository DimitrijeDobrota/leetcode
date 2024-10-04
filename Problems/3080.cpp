class Solution {
  public:
    vector<long long> unmarkedSumArray(vector<int> &nums, const vector<vector<int>> &queries) const {
        const int n = size(nums), m = size(queries);
        long long sum = accumulate(begin(nums), end(nums), 0ll);

        const auto mark = [&](int idx) {
            if (nums[idx] < 0) return false;
            sum += nums[idx] = -nums[idx];
            return true;
        };

        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++)
            pairs[i] = {nums[i], i};
        sort(begin(pairs), end(pairs));

        int crnt = 0;
        vector<long long> res(m);
        for (int i = 0; i < m; i++) {
            mark(queries[i][0]);

            int k = queries[i][1];
            while (crnt < n && k > 0) {
                k -= mark(pairs[crnt++].second);
            }

            res[i] = sum;
        }

        return res;
    }
};
