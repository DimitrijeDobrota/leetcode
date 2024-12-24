class Solution {
    using vvi = vector<vector<int>>;

    static int middle(const vvi &edges) {
        static int count[100001];
        const int n = size(edges) + 1;
        vvi adj(n);

        memset(count, 0x00, sizeof(count));

        for (const auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            count[edge[0]]++;
            count[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (count[i] != 1) continue;
            q.push(i);
        }

        int crnt = 0, left = n, lvl;
        for (lvl = 0; left > 2; lvl++) {
            left -= size(q);

            for (int k = size(q); k > 0; k--) {
                crnt = q.front(), q.pop();

                for (const auto next : adj[crnt]) {
                    if (--count[next] != 1) continue;
                    q.push(next);
                }
            }
        }

        return 2 * lvl + (left == 2);
    }

  public:
    int minimumDiameterAfterMerge(const vvi &edges1, const vvi &edges2) const {
        const auto d1 = middle(edges1);
        const auto d2 = middle(edges2);

        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};
