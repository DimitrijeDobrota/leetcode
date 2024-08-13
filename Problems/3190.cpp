class Solution {
  public:
    int minimumOperations(const vector<int> &nums) const {
        int res = 0;

        for (const int n : nums)
            res += (n % 3 != 0);

        return res;
    }
};
