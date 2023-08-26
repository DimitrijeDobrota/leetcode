class Solution {
  public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> um;
        stringstream ss;
        string t;

        ss.str(s1);
        while (ss >> t)
            um[t]++;

        ss.str(s2);
        ss.clear();
        while (ss >> t)
            um[t]++;

        vector<string> res;
        for (auto &[str, cnt] : um)
            if (cnt == 1) res.push_back(str);
        return res;
    }
};
