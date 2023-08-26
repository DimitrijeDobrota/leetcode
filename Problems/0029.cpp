class Solution {
  public:
    int divide(int dividend, int divisor) {
        if (divisor == INT_MIN) return dividend == INT_MIN;
        if (divisor == INT_MAX) {
            if (dividend == INT_MIN) return -1;
            if (dividend == INT_MAX) return 1;
            return 0;
        }

        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }

        int res = 0, sign = 1;
        if (divisor < 0) divisor = -divisor, sign = -sign;
        if (dividend < 0) {
            if (dividend == INT_MIN) dividend += divisor, res++;
            dividend = -dividend, sign = -sign;
        }

        while (dividend >= divisor) {
            long temp = divisor, count = 1;
            while (temp << 1 <= dividend) {
                temp <<= 1;
                count <<= 1;
            }
            dividend -= temp;
            res += count;
        }
        return sign * res;
    }
};
