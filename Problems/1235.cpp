class Solution {
  public:
    int jobScheduling(const vector<int> &startTime, const vector<int> &endTime,
                      const vector<int> &profit) const {
        static int indices[50001];
        const int n = profit.size();

        iota(begin(indices), begin(indices) + n, 0);
        sort(begin(indices), begin(indices) + n,
             [&endTime](int a, int b) { return endTime[a] < endTime[b]; });

        map<int, int> dp = {{0, 0}};
        for (int i = 0; i < n; i++) {
            const int idx = indices[i];
            const int crnt = profit[idx] + prev(dp.upper_bound(startTime[idx]))->second;
            if (crnt > dp.rbegin()->second) dp[endTime[idx]] = crnt;
        }

        return dp.rbegin()->second;
    }
};
