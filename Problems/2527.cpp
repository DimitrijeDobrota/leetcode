class Solution {
  public:
    int xorBeauty(const vector<int> &nums) {
        int res = 0;
        for (const int n : nums)
            res ^= n;
        return res;
    }
};
