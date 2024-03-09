class Solution {
  public:
    int countNumbersWithUniqueDigits(const int n) const {
        if (n == 0) return 1;

        int res = 10, acc = 9, crnt = 9;
        for (int i = 2; i <= n; i++)
            res += acc *= crnt--;

        return res;
    }
};
