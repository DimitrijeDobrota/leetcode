class Solution {
  public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k) {
        int res = 0;

        for (unsigned i = 0; i < size(nums); i++) {
            if (popcount(i) != k) continue;
            res += nums[i];
        }

        return res;
    }
};
