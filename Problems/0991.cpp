class Solution {
  public:
    int brokenCalc(const int startValue, int target) const {
        int res = 0;
        while (target > startValue) {
            res++;
            if (target % 2 == 0)
                target /= 2;
            else
                target++;
        }
        return res + (startValue - target);
    }
};
