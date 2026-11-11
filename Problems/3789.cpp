class Solution {
  public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1,
                          long long need2) const {
        const auto shared = std::min(need1, need2);
        return shared * std::min(costBoth, cost1 + cost2) + (need1 - shared) * std::min(cost1, costBoth) +
               (need2 - shared) * std::min(cost2, costBoth);
    }
};
