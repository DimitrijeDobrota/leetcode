int n, cnt = n;
mutable vector<int> root;
vector<int> size;

public:
UnionFind(int n) : n(n), root(n), size(n, 1) { iota(root.begin(), root.end(), 0); }
UnionFind(const UnionFind &uf) : n(uf.n), cnt(uf.cnt), root(uf.root), size(uf.size) {}

int find(int x) const {
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

void reset(int x) {
    root[x] = x;
    size[x] = 0;
}

int count() const { return cnt; }
bool connected(int x, int y) const { return find(x) == find(y); }
}
;

class Solution {
  public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
        sort(begin(meetings), end(meetings), [](const auto &m1, const auto &m2) { return m1[2] < m2[2]; });

        int first = 0;
        UnionFind uf(n);
        uf.join(0, firstPerson);

        meetings.push_back({0, 0, INT_MAX});
        uf.join(meetings[0][0], meetings[0][1]);
        for (int i = 1; i < size(meetings); i++) {
            if (meetings[i][2] == meetings[i - 1][2]) {
                uf.join(meetings[i][0], meetings[i][1]);
            } else {
                for (int j = first; j < i; j++) {
                    if (uf.connected(meetings[j][0], 0)) continue;
                    uf.reset(meetings[j][0]);
                    uf.reset(meetings[j][1]);
                }
                first = i;
                uf.join(meetings[i][0], meetings[i][1]);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (uf.connected(i, 0)) res.push_back(i);
        }
        return res;
    }
};
