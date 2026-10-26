#include "../Templates/Union_Find.cpp"

class Solution {
  public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edges, vector<vector<int>> &queries) {
        vector<bool> res(queries.size());
        UnionFind uf(n);

        for (int i = 0; i < queries.size(); ++i)
            queries[i].push_back(i);

        const auto cmp = [](auto &a, auto &b) { return a[2] < b[2]; };
        sort(begin(queries), end(queries), cmp);
        sort(begin(edges), end(edges), cmp);

        int i = 0;
        for (auto &q : queries) {
            for (; i < edges.size() && edges[i][2] < q[2]; i++)
                uf.join(edges[i][0], edges[i][1]);
            res[q[3]] = uf.connected(q[0], q[1]);
        }
        return res;
    }
};
