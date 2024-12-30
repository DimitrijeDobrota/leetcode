class Solution {
  public:
    vector<int> findWordsContaining(const vector<string> &words, char x) const {
        vector<int> res;

        for (int i = 0; i < size(words); i++) {
            if (words[i].find(x) != string::npos) {
                res.push_back(i);
            }
        }

        return res;
    }
};
