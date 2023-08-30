class Solution {
  public:
    int numSpecialEquivGroups(const vector<string> &words) {
        unordered_set<string> st;
        const int n = words[0].size();
        for (const auto &word : words) {
            string s1, s2;
            for (int i = 0; i < n; i += 2)
                s1 += word[i];
            for (int i = 1; i < n; i += 2)
                s2 += word[i];
            sort(begin(s1), end(s1));
            sort(begin(s2), end(s2));
            st.insert(s1 + ' ' + s2);
        }
        return st.size();
    }
};
