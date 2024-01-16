class Solution {
  public:
    long long coloredCells(int n) const { return 1 + 2ll * n * (n - 1); }
};
