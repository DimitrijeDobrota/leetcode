class Solution {
  public:
    int longestStrChain(vector<string> &words) {
        sort(begin(words), end(words), [](const auto &a, const auto &b) { return a.size() < b.size(); });

        static int dp[1001];
        memset(dp, 0x00, sizeof(dp));

        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[j].size() == words[i].size()) continue;
                if (words[j].size() - words[i].size() > 1) break;
                int k = 0, l = 0, diff = 0;
                while (k < words[i].size()) {
                    if (words[i][k] == words[j][l])
                        k++, l++;
                    else {
                        l++;
                        if (diff++) break;
                    }
                }
                if (diff == 2) continue;
                res = max(res, dp[j] = max(dp[j], dp[i] + 1));
            }
        }

        return res + 1;
    }
};
