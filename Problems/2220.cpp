class Solution {
  public:
    int minBitFlips(int start, int goal) const { return popcount((unsigned)(start ^ goal)); }
};
