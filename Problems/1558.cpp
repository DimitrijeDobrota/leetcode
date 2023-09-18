class Solution {
    static constexpr const int size = sizeof(int) * 8 - 1;

  public:
    int minOperations(const vector<int> &nums) {
        int mini = INT_MAX, res = 0;
        for (const int n : nums) {
            if (n) mini = min(mini, __builtin_clz(n));
            res += __builtin_popcount(n);
        }
        return max(0, res + size - mini);
    }
};
