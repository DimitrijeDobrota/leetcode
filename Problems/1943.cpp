class Solution {
  public:
    vector<vector<long long>> splitPainting(const vector<vector<int>> &segments) const {
        static long long prefix[100002];
        static bool seen[100002];

        memset(seen, 0x00, sizeof(seen));
        memset(prefix, 0x00, sizeof(prefix));
        for (const auto seg : segments) {
            prefix[seg[0]] += seg[2];
            prefix[seg[1]] -= seg[2];

            seen[seg[0]] = seen[seg[1]] = 1;
        }

        vector<vector<long long>> res;
        long long crnt = 0, prev = 0;
        for (int i = 1; i < 100002; i++) {
            if (crnt && seen[i]) {
                res.push_back({prev, i, crnt});
            }
            if (seen[i]) prev = i;
            crnt += prefix[i];
        }

        return res;
    }
};
