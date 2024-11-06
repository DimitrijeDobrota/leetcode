class Solution {
  public:
    int arrangeCoins(int n) const { return (sqrt(8l * n + 1) - 1) / 2; }
};
