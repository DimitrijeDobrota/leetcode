class Solution {
  public:
    vector<string> twoEditWords(const vector<string> &queries, const vector<string> &dictionary) {
        const int n = queries.front().size();

        vector<string> res;
        if (n <= 2) return queries;
        for (const string &query : queries) {
            for (const string &dict : dictionary) {
                int i = 0, j = 0, diff = 0;
                while (i < n) {
                    if (query[i++] == dict[j++]) continue;
                    if (++diff > 2) goto next;
                }
                res.push_back(query);
                break;
            next:;
            }
        }

        return res;
    }
};
