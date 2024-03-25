class Solution {
  public:
    int minIncrementForUnique(const vector<int> &nums) const {
        static int count[100001];
        memset(count, 0x00, sizeof(count));

        for (const int n : nums)
            count[n]++;

        int res = 0, carry = 0;
        for (int i = 0; i < 100001; i++) {
            if (count[i] >= 1)
                carry += count[i] - 1;
            else if (carry)
                carry--;
            res += carry;
        }

        return res + carry * (carry - 1) / 2;
    }
};
