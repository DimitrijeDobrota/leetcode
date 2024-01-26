class Solution {
    unordered_set<string> seen;

  public:
    int maxUniqueSplit(const string &s, int idx = 0) {
        if (idx == size(s)) return size(seen);

        int res = 0;
        string crnt;
        for (int i = idx; i < size(s); i++) {
            auto it = seen.emplace(crnt += s[i]);
            if (!it.second) continue;
            res = max(res, maxUniqueSplit(s, i + 1));
            seen.erase(it.first);
        }

        return res;
    }
};
