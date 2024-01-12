static auto _ = []() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();

class Solution {
  public:
    int minOperations(const vector<int> &nums, int k) const {
        for (const int n : nums)
            k ^= n;
        return __builtin_popcount(k);
    }
};
