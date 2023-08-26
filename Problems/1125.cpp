class Solution {
  public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people) {
        int n = people.size(), m = req_skills.size();
        unordered_map<string, int> index;
        for (int i = 0; i < m; i++)
            index[req_skills[i]] = i;
        vector<int> masks(n);
        for (int i = 0; i < n; i++) {
            for (string skill : people[i])
                masks[i] |= 1 << index[skill];
        }

        vector<long long> dp(1 << m, (1LL << n) - 1);
        dp[0] = 0;
        for (int mask = 1; mask < (1 << m); mask++) {
            for (int i = 0; i < n; i++) {
                int smask = mask & ~masks[i];
                if (smask == mask) continue;
                long long pmask = dp[smask] | (1LL << i);
                if (__builtin_popcountll(pmask) < __builtin_popcountll(dp[mask])) dp[mask] = pmask;
            }
        }

        long long answerMask = dp[(1 << m) - 1];
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if ((answerMask >> i) & 1) res.push_back(i);
        }
        return res;
    }
};
