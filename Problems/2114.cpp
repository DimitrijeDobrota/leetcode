class Solution {
  public:
    int mostWordsFound(const vector<string> &sentences) const {
        int res = -1;

        for (const auto &s : sentences) {
            res = max(res, (int)count(begin(s), end(s), ' '));
        }

        return res + 1;
    }
};
