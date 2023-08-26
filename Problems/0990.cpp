class UnionFind {
    vector<int> root, rank;

  public:
    UnionFind(int n) : root(n), rank(n, 1) { iota(root.begin(), root.end(), 0); }

    int find(int x) {
        if (x == root[x]) return x;
        return root[x] = find(root[x]);
    }

    void join(int x, int y) {
        x = find(x), y = find(y);

        if (x != y) {
            if (rank[x] > rank[y]) swap(x, y);
            root[y] = x;
            rank[x] += x == y;
        }
    }
};

class Solution {
  public:
    bool equationsPossible(vector<string> &equations) {
        UnionFind uf(26);
        for (auto &s : equations)
            if (s[1] == '=') uf.join(s[0] - 'a', s[3] - 'a');

        for (auto &s : equations)
            if (s[1] == '!' && uf.find(s[0] - 'a') == uf.find(s[3] - 'a')) return false;
        return true;
    }
};
