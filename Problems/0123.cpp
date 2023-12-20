class Solution {
  public:
    int maxProfit(const vector<int> &prices) const {
        int cost1 = INT_MAX, cost2 = INT_MAX;
        int profit1 = 0, profit2 = 0;

        for (const int price : prices) {
            cost1 = min(cost1, price);
            profit1 = max(profit1, price - cost1);
            cost2 = min(cost2, price - profit1);
            profit2 = max(profit2, price - cost2);
        }

        return profit2;
    }
};
