class Solution {
  public:
    int minExtraChar(const string &s, const vector<string> &dictionary) {
        unordered_set<string> us(begin(dictionary), end(dictionary));
        int dp[51] = {0};

        for (int i = s.size() - 1; i >= 0; i--) {
            int mini = s.size();
            for (int j = i; j < s.size(); j++) {
                int crnt = us.count(s.substr(i, j - i + 1)) ? 0 : j - i + 1;
                mini = min(mini, dp[j + 1] + crnt);
            }
            dp[i] = mini;
        }

        return *begin(dp);
    }
};
