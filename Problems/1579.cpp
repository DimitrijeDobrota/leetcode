#include "../Templates/Union_Find.cpp"

class Solution {
  public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &e) {
        int redundant = 0;

        UnionFind a(n + 1);
        for (int i = 0; i < e.size(); i++)
            if (e[i][0] == 3) redundant += !a.join(e[i][1], e[i][2]).merged;

        UnionFind b = a;
        for (int i = 0; i < e.size(); i++)
            if (e[i][0] == 1)
                redundant += !a.join(e[i][1], e[i][2]).merged;
            else if (e[i][0] == 2)
                redundant += !b.join(e[i][1], e[i][2]).merged;

        // count must be 2, since 0 is not used
        return a.count() == 2 && b.count() == 2 ? redundant : -1;
    }
};
