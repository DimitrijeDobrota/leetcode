#include "../Templates/Union_Find.cpp"

class Solution {
  public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isConnected[i][j]) uf.join(i, j);

        return uf.count();
    }
};
