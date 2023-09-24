class Solution {
    int f(const string &s) {
        int res = 0, mini = s[0];
        for (const char c : s) {
            if (c == mini) res++;
            if (c < mini) {
                mini = c;
                res = 1;
            }
        }
        return res;
    }

  public:
    vector<int> numSmallerByFrequency(const vector<string> &queries, const vector<string> &words) {
        vector<int> res(queries.size()), mem(words.size());
        for (int i = 0; i < words.size(); i++)
            mem[i] = f(words[i]);
        sort(mem.begin(), mem.end());

        for (int i = 0; i < queries.size(); i++) {
            const int t = f(queries[i]);
            res[i] = words.size() - distance(begin(mem), upper_bound(begin(mem), end(mem), t));
        }

        return res;
    }
};
