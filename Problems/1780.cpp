class Solution {
  public:
    bool checkPowersOfThree(int n) {
        while (n > 0 && n % 3 != 2)
            n = (n % 3) ? n - 1 : n / 3;
        return n == 0;
    }
};
