class Solution {
  public:
    int minImpossibleOR(const vector<int> &nums) const {
        vector<bool> seen(32, false);

        for (const int n : nums) {
            if (__builtin_popcount(n) != 1) continue;
            seen[__builtin_ffs(n) - 1] = true;
        }

        for (int i = 0; i < 32; i++) {
            if (!seen[i]) return 1 << i;
        }
        return -1;
    }
};
