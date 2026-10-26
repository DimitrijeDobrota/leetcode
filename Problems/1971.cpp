#include "../Templates/Union_Find.cpp"

class Solution {
  public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        UnionFind uf(n);
        for (auto &p : edges)
            uf.join(p[0], p[1]);

        return uf.find(source) == uf.find(destination);
    }
};
