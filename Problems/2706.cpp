class Solution {
  public:
    int buyChoco(const vector<int> &prices, int money) const {
        int a = prices[0], b = prices[1];
        if (a > b) swap(a, b);
        for (int i = 2; i < prices.size(); i++) {
            if (a > prices[i]) {
                b = a;
                a = prices[i];
            } else if (b > prices[i]) {
                b = prices[i];
            }
        }
        return a + b <= money ? money - (a + b) : money;
    }
};
