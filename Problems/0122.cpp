class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        prices.push_back(INT_MIN);
        for (int i = 0, j = 0; i < prices.size() - 1; i++) {
            while (prices[j] < prices[j + 1])
                j++;
            profit += prices[j] - prices[i];
            i = j++;
        }
        return profit;
    }
};
