class Solution {
    vector<char> next[6][6];
    unordered_map<string, bool> seen;

    bool rec(const string &bottom) {
        if (bottom.size() == 1) return true;
        if (seen.count(bottom)) return seen[bottom];

        vector<string> prev, crnt;
        for (int i = 1; i < size(bottom); i++) {
            const int c = bottom[i - 1] - 'A', n = bottom[i] - 'A';
            for (const char c : next[c][n]) {
                if (prev.empty()) {
                    crnt.push_back(string(1, c));
                    continue;
                }
                for (const auto &s : prev) {
                    if (next[s.back() - 'A'][c - 'A'].empty()) continue;
                    crnt.push_back(s + c);
                }
            }
            if (crnt.empty()) return false;

            prev = crnt;
            crnt.clear();
        }

        bool res = false;
        for (const auto &s : prev) {
            if (!rec(s)) continue;
            res = true;
            break;
        }
        return seen[bottom] = res;
    }

  public:
    bool pyramidTransition(const string &bottom, const vector<string> &allowed) {
        for (const auto &s : allowed)
            next[s[0] - 'A'][s[1] - 'A'].push_back(s[2]);
        return rec(bottom);
    }
};
