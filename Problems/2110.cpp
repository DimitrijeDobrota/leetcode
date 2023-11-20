class Solution {
  public:
    long long getDescentPeriods(const vector<int> &prices) const {
        long long res = 1, cnt = 1;
        const int n = prices.size();
        for (int i = 1; i < n; i++) {
            if (prices[i] + 1 != prices[i - 1]) cnt = 0;
            res += ++cnt;
        }
        return res;
    }
};
