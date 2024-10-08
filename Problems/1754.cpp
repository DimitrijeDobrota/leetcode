class Solution {
  public:
    string largestMerge(const string &word1, const string &word2) const {
        const int n = size(word1), m = size(word2);
        int i = 0, j = 0;
        string res;

        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                res += word1.substr(i) > word2.substr(j) ? word1[i++] : word2[j++];
            } else {
                res += word1[i] > word2[j] ? word1[i++] : word2[j++];
            }
        }

        return res + word1.substr(i) + word2.substr(j);
    }
};
