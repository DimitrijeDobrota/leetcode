class Solution {
  public:
    int maxProfit(const int k, const vector<int> &prices) const {
        vector<int> cost(k + 1, INT_MAX), profit(k + 1, 0);

        for (const int price : prices) {
            for (int i = 1; i <= k; i++) {
                cost[i] = min(cost[i], price - profit[i - 1]);
                profit[i] = max(profit[i], price - cost[i]);
            }
        }

        return profit[k];
    }
};
