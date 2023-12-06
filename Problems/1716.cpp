class Solution {
  public:
    int totalMoney(int n) {
        const int whole = n / 7, rest = n % 7;
        int res = whole * (7 * whole + 49) / 2;

        for (int i = 1; i <= rest; i++) {
            res += whole + i;
        }

        return res;
    }
};
