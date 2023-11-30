class Solution {
  public:
    int minimumOneBitOperations(int n) const {
        bitset<32> res, num(n);
        res[31] = num[31];
        for (int i = 30; i >= 0; i--) {
            res[i] = res[i + 1] ^ num[i];
        }
        return res.to_ulong();
    }
};
