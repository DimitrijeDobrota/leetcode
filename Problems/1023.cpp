class Solution {
  public:
    vector<bool> camelMatch(const vector<string> &queries, const string &pattern) {
        vector<bool> res(queries.size(), false);
        for (int k = 0; k < queries.size(); k++) {
            const string &query = queries[k];
            int i = 0, j = 0;
            while (i < query.size()) {
                if (!isupper(query[i])) {
                    if (query[i] == pattern[j]) j++;
                    i++;
                } else {
                    if (j == pattern.size() || query[i] != pattern[j]) goto next;
                    i++, j++;
                }
            }
            if (j == pattern.size()) res[k] = true;
        next:;
        }
        return res;
    }
};
