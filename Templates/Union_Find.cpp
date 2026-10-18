class UnionFind {
    // Roots store negative component sizes; other entries store parent indices.
    mutable vector<int> parent;
    int components;
    int largest;

  public:
    explicit UnionFind(int node_count)
        : parent(node_count, -1),
          components(node_count),
          largest(node_count > 0 ? 1 : 0) {}

    int find(int x) const {
        while (parent[x] >= 0) {
            int &next_parent = parent[x];
            if (parent[next_parent] >= 0) {
                next_parent = parent[next_parent];
            }
            x = next_parent;
        }
        return x;
    }

    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;

        if (parent[x] < parent[y]) swap(x, y);
        parent[y] += parent[x];
        parent[x] = y;
        largest = std::max(largest, -parent[y]);
        --components;
        return true;
    }

    void reset() {
        std::ranges::fill(parent, -1);
        components = static_cast<int>(parent.size());
        largest = parent.empty() ? 0 : 1;
    }

    int count() const { return components; }
    int component_size(int x) const { return -parent[find(x)]; }
    int max_size() const { return largest; }
    bool connected(int x, int y) const { return find(x) == find(y); }
};
