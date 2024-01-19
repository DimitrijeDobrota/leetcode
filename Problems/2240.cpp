class Solution {
  public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) const {
        long long res = 0;
        for (; total >= 0; total -= cost1)
            res += 1ll + total / cost2;
        return res;
    }
};
