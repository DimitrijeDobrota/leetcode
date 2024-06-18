class Solution {
  public:
    int maxProfitAssignment(const vector<int> &difficulty, const vector<int> &profit,
                            const vector<int> &worker) const {
        static int profits[100001];
        const int n = size(profit);
        int res = 0;

        memset(profits, 0x00, sizeof(profits));
        for (int i = 0; i < n; i++) {
            profits[difficulty[i]] = max(profits[difficulty[i]], profit[i]);
        }

        for (int i = 1; i < 100001; i++) {
            profits[i] = max(profits[i], profits[i - 1]);
        }

        for (const int m : worker)
            res += profits[m];

        return res;
    }
};
