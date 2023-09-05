
#pragma GCC optimize("fast")
static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
  public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, const vector<vector<int>> &queries) {
        vector<int> res;
        res.reserve(queries.size());
        int sum = 0;
        for (int n : nums)
            if (n % 2 == 0) sum += n;
        for (const auto q : queries) {
            if (nums[q[1]] % 2 == 0) sum -= nums[q[1]];
            nums[q[1]] += q[0];
            if (nums[q[1]] % 2 == 0) sum += nums[q[1]];
            res.push_back(sum);
        }
        return res;
    }
};
