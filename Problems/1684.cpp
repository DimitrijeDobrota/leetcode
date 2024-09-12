class Solution {
  public:
    int countConsistentStrings(const string &allowed, const vector<string> &words) const {
        bool count[26] = {false};
        int res = 0;

        for (const char c : allowed)
            count[c - 'a'] = true;
        for (const auto &word : words) {
            for (const char c : word) {
                if (!count[c - 'a']) goto next;
            }
            res++;
        next:;
        }

        return res;
    }
};
