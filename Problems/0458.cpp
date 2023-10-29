class Solution {
  public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) const {
        const int tests = minutesToTest / minutesToDie + 1;
        return ceil(log2(buckets) / log2(tests));
    }
};
