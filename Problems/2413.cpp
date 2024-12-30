class Solution {
  public:
    int smallestEvenMultiple(int n) const { return n % 2 ? n * 2 : n; }
};
