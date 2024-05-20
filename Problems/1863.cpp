class Solution {
  public:
    int subsetXORSum(const vector<int> &nums) const {
        const int n = size(nums);
        int res = 0;

        for (uint16_t mask = 1; mask < (1 << n); mask++) {
            uint16_t crnt = mask, acc = 0;
            while (crnt) {
                const uint8_t idx = countr_zero(crnt);
                acc ^= nums[idx];
                crnt ^= 1 << idx;
            }
            res += acc;
        }

        return res;
    }
};
