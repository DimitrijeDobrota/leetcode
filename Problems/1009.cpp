class Solution {
  public:
    int bitwiseComplement(unsigned num) const {
        if (num == 0) return 1;
        return num ^ (0xFFFFFFFF >> std::countl_zero(num));
    }
};
