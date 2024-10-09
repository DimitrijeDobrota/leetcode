static const auto _ = [] {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
  public:
    vector<int> remainingMethods(int n, int k, const vector<vector<int>> &invocations) const {
        static bool seen[100001];
        vector<vector<int>> invoke(n);

        memset(seen, 0x00, sizeof(seen));
        for (const auto &in : invocations) {
            invoke[in[0]].push_back(in[1]);
        }

        queue<int> q;
        q.emplace(k);
        seen[k] = true;
        while (!q.empty()) {
            const int root = q.front();
            q.pop();
            for (const auto next : invoke[root]) {
                if (seen[next]) continue;
                seen[next] = true;
                q.emplace(next);
            }
        }

        for (int i = 0; i < n; i++) {
            if (seen[i]) continue;
            for (const auto in : invoke[i]) {
                if (seen[in]) {
                    vector<int> res(n);
                    iota(begin(res), end(res), 0);
                    return res;
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (seen[i]) continue;
            res.emplace_back(i);
        }

        return res;
    }
};
