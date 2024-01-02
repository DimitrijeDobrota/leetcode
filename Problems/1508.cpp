class Solution {
    static const int MOD = 1E9 + 7;

  public:
    int rangeSum(const vector<int> &nums, int n, int left, int right) const {
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            for (int j = i, acc = 0; j < n; j++) {
                vec.push_back(acc += nums[j]);
            }
        }

        nth_element(vec.begin(), vec.begin() + left - 1, vec.end());
        nth_element(vec.begin() + left, vec.begin() + right - 1, vec.end());
        return accumulate(begin(vec) + left - 1, begin(vec) + right, 0ll) % MOD;
    }
};
