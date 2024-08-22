class Solution {
  public:
    int findComplement(unsigned num) const { return num ^ (0xFFFFFFFF >> std::countl_zero(num)); }
};
