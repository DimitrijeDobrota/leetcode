class Solution {
  public:
    vector<string> wordSubsets(const vector<string> &words1, const vector<string> &words2) const {
        const int n = size(words1), m = size(words2);
        int count[26] = {0};
        vector<string> res;

        for (int i = 0; i < m; i++) {
            int lcount[27] = {0};
            for (char c : words2[i])
                lcount[c - 'a']++;
            for (int j = 0; j < 26; j++) {
                count[j] = max(count[j], lcount[j]);
            }
        }

        for (int i = 0; i < n; i++) {
            int lcount[27] = {0};
            for (char c : words1[i])
                lcount[c - 'a']++;
            for (int k = 0; k < 26; k++) {
                if (lcount[k] < count[k]) goto next;
            }

            res.push_back(words1[i]);
        next:;
        }

        return res;
    }
};
