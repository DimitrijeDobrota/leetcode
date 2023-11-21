class Solution {
  public:
    int countNicePairs(const vector<int> &nums) const {
        static const int MOD = 1E9 + 7;
        unordered_map<int, int> count;
        int res = 0;
        for (const int n : nums) {
            a int rev = 0, tmp = n;
            do {
                rev = (rev * 10) + tmp % 10;
            } while ((tmp /= 10) > 0);
            const int crnt = n - rev;
            res = (res + count[crnt]++) % MOD;
        }

        return res;
    }
};
