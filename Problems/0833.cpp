class Solution {
  public:
    string findReplaceString(const string &s, const vector<int> &indices, const vector<string> &sources,
                             const vector<string> &targets) const {
        const int n = size(indices);

        static int order[10001];
        iota(begin(order), begin(order) + n, 0);
        sort(begin(order), begin(order) + n, [&indices](int i, int j) { return indices[i] < indices[j]; });

        string res;
        int crnt = 0;
        for (int i = 0; i < n; i++) {
            const int idx = order[i], m = size(sources[idx]);
            int pos = 0;

            if (indices[idx] < crnt) continue;
            while (indices[idx] > crnt)
                res += s[crnt++];
            while (pos < m && s[crnt + pos] == sources[idx][pos])
                pos++;
            if (pos == m) res += targets[idx], crnt += m;
        }
        while (crnt < size(s))
            res += s[crnt++];

        return res;
    }
};
