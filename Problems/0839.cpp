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
    bool similar(const string &s1, const string &s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) continue;
            if (diff < 2)
                diff++;
            else
                return false;
        }
        return true;
    }

  public:
    int numSimilarGroups(const vector<string> &strs) {
        int n = strs.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (similar(strs[i], strs[j])) uf.join(i, j);
            }
        }
        return uf.count();
    }
};
