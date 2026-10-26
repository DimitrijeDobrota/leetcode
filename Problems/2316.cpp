#include "../Templates/Union_Find.cpp"

class Solution {
  public:
    long long countPairs(int n, vector<vector<int>> &edges) {
        UnionFind uf(n);
        for (auto &e : edges)
            uf.join(e[0], e[1]);
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (!uf.is_root(i)) continue;
            const int size = uf.component_size(i);
            res += (long long)size * (n - size);
        }
        return res / 2;
    }
};
