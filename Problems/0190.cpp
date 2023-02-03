class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    int count = 32, res = 0;
    while (count--) {
      res <<= 1;
      res += n & 1;
      n >>= 1;
    }
    return res;
  }
};
