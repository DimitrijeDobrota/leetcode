class Solution {
  public:
    bool wordPattern(string pattern, string s) {
        vector<string> done(26, "");
        unordered_set<string> st;

        int c = 0;
        istringstream in(s);
        for (string crnt; in >> crnt; ++c) {
            if (c >= pattern.size()) return false;
            int index = pattern[c] - 'a';
            if (done[index].empty()) {
                if (st.count(crnt)) return false;
                st.insert(done[index] = crnt);
            } else if (done[index] != crnt)
                return false;
        }
        if (pattern.size() > c) return false;

        return true;
    }
};
