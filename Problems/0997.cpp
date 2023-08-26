class Solution {
  public:
    int findJudge(int n, vector<vector<int>> &trust) {
        if (n == 1 && trust.empty()) return 1;

        vector<int> trusted(n + 1, 0);
        unordered_set<int> trusting;

        for (auto &p : trust) {
            trusting.insert(p[0]);
            trusted[p[1]]++;
        }

        for (int i = 1; i <= n; i++)
            if (trusted[i] == n - 1 && !trusting.count(i)) return i;

        return -1;
    }
};
