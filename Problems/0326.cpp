class Solution {
  public:
    bool isPowerOfThree(int n) {
        double x = log10(n) / log10(3);
        return n > 0 && x == round(x);
    }
};
