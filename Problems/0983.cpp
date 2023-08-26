class Solution {
    vector<int> pass = {1, 7, 30};
    unordered_map<int, int> dp;

  public:
    int mincostTickets(vector<int> &days, vector<int> &costs, int start = 0) {
        if (start >= days.size()) return 0;
        if (dp.count(start)) return dp[start];

        int res = INT_MAX;
        for (int k = 0, j = 0; k < pass.size(); k++) {
            while (j < days.size() && days[j] - days[start] < pass[k])
                j++;
            res = min(res, costs[k] + mincostTickets(days, costs, j));
        }

        dp[start] = res;
        return res;
    }
};
