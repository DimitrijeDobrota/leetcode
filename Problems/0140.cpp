class Solution {
    unordered_set<string> us[10];

    vector<string> rec(const string &s, const int start = 0) {
        const int n = size(s);
        vector<string> res;
        string crnt;

        if (start == n) return {""};
        for (int i = start; i < min(start + 10, n); i++) {
            crnt += s[i];
            if (!us[i - start].count(crnt)) continue;
            for (const auto &s : rec(s, i + 1)) {
                res.push_back(start == 0 ? "" : " ");
                res.back() += crnt + s;
            }
        }

        return res;
    }

  public:
    vector<string> wordBreak(const string &s, const vector<string> &wordDict) {
        for (const auto &word : wordDict)
            us[size(word) - 1].insert(word);
        return rec(s);
    }
};
