class Solution {
  public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
        const int n = nums.size(), mask = (1 << maximumBit) - 1;
        vector<int> res(n);
        for (int i = 0, acc = 0; i < n; i++) {
            nums[i] = acc ^= nums[i];
            res[n - i - 1] = nums[i] ^ mask;
        }
        return res;
    }
};
