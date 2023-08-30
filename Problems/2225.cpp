class Solution {
  public:
    vector<vector<int>> findWinners(const vector<vector<int>> &matches) {
        static int count[100001];
        vector<vector<int>> res(2);

        memset(count, 0xFF, sizeof(count));
        for (const auto &match : matches) {
            if (count[match[0]] == -1) count[match[0]] = 0;
            if (count[match[1]] == -1) count[match[1]] = 0;
            count[match[1]]++;
        }

        for (int player = 1; player <= 100000; player++) {
            if (count[player] == 0) res[0].push_back(player);
            if (count[player] == 1) res[1].push_back(player);
        }
        return res;
    }
};
