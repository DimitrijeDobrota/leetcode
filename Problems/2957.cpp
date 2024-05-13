class Solution {
  public:
    int removeAlmostEqualCharacters(const string &word) const {
        int res = 0;

        for (int i = 0; i < size(word) - 1; i++) {
            if (abs(word[i] - word[i + 1]) > 1) continue;
            res++, i++;
        }

        return res;
    }
};
