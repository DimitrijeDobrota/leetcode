class UnionFind {
    int n, cnt = n;
    vector<int> root, size;

  public:
    UnionFind(int n) : n(n), root(n), size(n, 1) { iota(root.begin(), root.end(), 0); }

    int find(int x) {
        while (x != root[x])
            x = root[x] = root[root[x]];
        return x;
    }

    void join(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            if (size[x] > size[y]) swap(x, y);
            root[x] = y;
            size[y] += size[x];
            cnt--;
        }
    }

    int count() { return cnt; }
    bool connected(int x, int y) { return find(x) == find(y); }
};

class Solution {
  public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps) {
        int n = source.size();
        UnionFind uf(n);

        for (auto &s : allowedSwaps)
            uf.join(s[0], s[1]);

        vector<unordered_map<int, int>> vus(n);
        for (int i = 0; i < n; i++) {
            int pos = uf.find(i);
            vus[pos][target[i]]++;
            vus[pos][source[i]]--;
        }

        int res = 0;
        for (int i = 0; i < n; i++)
            for (auto [_, val] : vus[i])
                res += abs(val);

        return res / 2;
    }
};
