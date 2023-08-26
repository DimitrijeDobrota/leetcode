class Solution {
  public:
    int maximumXOR(vector<int> &nums) {
        int res = 0;
        for (const int n : nums)
            res |= n;
        return res;
    }
};
