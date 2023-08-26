class UnionFind {
    vector<int> root, rank;
    int n;

  public:
    UnionFind(int n) : n(n), root(n), rank(n, 1) { iota(root.begin(), root.end(), 0); }

    int find(int x) {
        while (x != root[x])
            x = root[x] = root[root[x]];
        return x;
    }

    void join(int x, int y) {
        x = find(x), y = find(y);

        if (x != y) {
            if (rank[x] > rank[y]) swap(x, y);

            root[x] = y;
            rank[y] += rank[x];
        }
    }

    int count() {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += root[i] == i;
        return cnt;
    }
};

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
