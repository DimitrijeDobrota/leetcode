class Solution {
  public:
    vector<string> getWordsInLongestSubsequence(const int n, const vector<string> &words,
                                                const vector<int> &groups) const {
        vector<string> res;
        int crnt = groups[0];
        res.push_back(words[0]);
        for (int i = 1; i < n; i++)
            if (groups[i] != crnt) res.push_back(words[i]), crnt = !crnt;
        return res;
    }
};
