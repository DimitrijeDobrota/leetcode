class Solution {
  public:
    bool arrayStringsAreEqual(const vector<string> &word1, const vector<string> &word2) const {
        int i = 0, j = 0, k = 0, l = 0;
        while (i < word1.size() && j < word2.size()) {
            if (word1[i][k] != word2[j][l]) return false;
            if (++k == word1[i].size()) k = 0, i++;
            if (++l == word2[j].size()) l = 0, j++;
        }
        return i == word1.size() && j == word2.size();
    }
};
