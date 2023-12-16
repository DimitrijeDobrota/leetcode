class Solution {
  public:
    int trailingZeroes(int n) const {
        int res = 0;
        while (n > 0)
            n /= 5, res += n;
        return res;
    }
};
