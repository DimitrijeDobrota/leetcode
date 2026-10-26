#include "../Templates/Union_Find.cpp"

class Solution {
  public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        int count = 0;
        UnionFind uf(n);
        for (auto &edge : connections) {
            const auto x = uf.find(edge[0]), y = uf.find(edge[1]);
            if (x == y)
                count++;
            else
                uf.join_roots(x, y);
        }
        return count < uf.count() - 1 ? -1 : uf.count() - 1;
    }
};
