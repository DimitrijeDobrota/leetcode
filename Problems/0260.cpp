class Solution {
  public:
    vector<int> singleNumber(const vector<int> &nums) {
        long long diff = accumulate(begin(nums), end(nums), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> res = {0, 0};
        for (const int n : nums)
            res[(n & diff) == 0] ^= n;
        return res;
    }
};
