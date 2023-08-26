class Solution {
    typedef unordered_map<char, int> umci;
    bool um_eq(const umci &goal, const umci &crnt) {
        for (auto [k, v] : goal) {
            const auto it = crnt.find(k);
            if (it == crnt.end()) return false;
            if ((*it).second != v) return false;
        }
        return true;
    }

  public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        unordered_map<char, int> goal, crnt;

        for (int i = 0; i < p.size(); i++) {
            goal[p[i]]++;
            crnt[s[i]]++;
        }

        vector<int> res;
        for (int i = p.size(); i < s.size(); i++) {
            if (um_eq(goal, crnt)) res.push_back(i - p.size());
            crnt[s[i - p.size()]]--;
            crnt[s[i]]++;
        }
        if (um_eq(goal, crnt)) res.push_back(s.size() - p.size());
        return res;
    }
};
