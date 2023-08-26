class Solution {
  public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
        vector<int> root(n), res;
        iota(root.begin(), root.end(), 0);

        for (auto &p : edges)
            root[p[1]] = p[0];

        for (int i = 0; i < n; i++)
            if (i == root[i]) res.push_back(i);

        return res;
    }
};
