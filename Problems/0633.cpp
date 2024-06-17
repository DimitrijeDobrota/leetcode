class Solution {
  public:
    bool judgeSquareSum(const int c) const {
        long left = 0, right = sqrt(c);

        while (left <= right) {
            const long mid = left * left + right * right;
            if (mid == c) return true;
            if (mid < c)
                left++;
            else
                right--;
        }

        return false;
    }
};
