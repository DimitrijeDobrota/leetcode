class Solution {
  public:
    int maxEnvelopes(vector<vector<int>> &envelopes) const {
        const int n = size(envelopes);

        sort(begin(envelopes), end(envelopes),
             [](const auto &a, const auto &b) { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });

        vector<int> res;
        for (int i = 0; i < n; i++) {
            const auto crnt = envelopes[i][1];
            const auto it = lower_bound(begin(res), end(res), crnt);
            if (it == end(res))
                res.push_back(crnt);
            else
                *it = crnt;
        }

        return size(res);
    }
};
