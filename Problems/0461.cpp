class Solution {
  public:
    int hammingDistance(unsigned x, unsigned y) const { return popcount(x ^ y); }
};
