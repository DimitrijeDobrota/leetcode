class Solution {
  public:
    int isPrefixOfWord(const string &sentence, const string &searchWord) const {
        stringstream ss(sentence);
        int idx = 1;
        string s;

        while (ss >> s) {
            if (s.starts_with(searchWord)) return idx;
            idx++;
        }

        return -1;
    }
};
