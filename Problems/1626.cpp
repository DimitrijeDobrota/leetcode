class Solution {
  public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int n = scores.size(), res = 0;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {ages[i], scores[i]};
        sort(v.begin(), v.end());

        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            int total = 0;
            for (int j = 0; j < i; j++) {
                if (v[j].second <= v[i].second) dp[i] = max(dp[i], dp[j]);
            }
            res = max(res, dp[i] += v[i].second);
        }

        return res;
    }
};
