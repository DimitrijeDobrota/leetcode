class UnionFind {
    int n, cnt = n;
    mutable vector<int> root;
    vector<int> size;

  public:
    UnionFind(int n) : n(n), root(n), size(n, 1) { iota(root.begin(), root.end(), 0); }
    UnionFind(const UnionFind &uf) : n(uf.n), cnt(uf.cnt), root(uf.root), size(uf.size) {}

    int find(int x) const {
        while (x != root[x]) {
            x = root[x] = root[root[x]];
        }
        return x;
    }

    void join(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;

        if (size[x] > size[y]) swap(x, y);
        root[x] = y;
        size[y] += size[x];
        cnt--;
    }

    bool connected(int x, int y) const { return find(x) == find(y); }

    void reset() {
        memset(size.data(), 0x00, size.size() * sizeof(int));
        iota(begin(root), end(root), 0);
    }
};

class Solution {
    static constexpr const int maxi = 100001;
    typedef array<int, maxi> cache_t;

  public:
    bool canTraverseAllPairs(const vector<int> &nums) const {
        const int n = size(nums);
        static UnionFind uf(2 * maxi + 1);
        uf.reset();

        if (n == 1) return true;

        static cache_t cache = {{0}};
        if (!cache[2]) {
            for (int i = 2; i < size(cache); i++) {
                if (cache[i]) continue;
                for (int j = i; j < size(cache); j += i) {
                    cache[j] = i;
                }
            }
        }

        static char seen[maxi];
        memset(seen, 0x00, sizeof(seen));

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) return false;
            seen[nums[i]] = 1;
            for (int val = nums[i]; val > 1;) {
                const int prime = cache[val];
                const int root = prime + maxi;
                uf.join(root, nums[i]);
                while (val % prime == 0)
                    val /= prime;
            }
        }

        int count = 0;
        for (int i = 0; i < maxi; i++)
            count += seen[i] && i == uf.find(i);
        return count == 1;
    }
};
