class UnionFind {
    // Roots store negative component sizes; other entries store parent indices.
    mutable vector<int> parent;
    int components;
    int largest;

  public:
    class Root {
        friend class UnionFind;
        int value;

        explicit Root(int value)
            : value(value) {}

      public:
        int index() const { return value; }
        bool operator==(const Root &) const = default;
    };

    struct JoinResult {
        Root root;
        bool merged;
    };

    explicit UnionFind(int node_count = 0)
        : parent(node_count, -1),
          components(node_count),
          largest(node_count > 0 ? 1 : 0) {}

    Root find(int x) const {
        while (parent[x] >= 0) {
            int &next_parent = parent[x];
            if (parent[next_parent] >= 0) {
                next_parent = parent[next_parent];
            }
            x = next_parent;
        }
        return Root(x);
    }

    Root add_node() {
        const int node = static_cast<int>(parent.size());
        parent.push_back(-1);
        ++components;
        largest = std::max(largest, 1);
        return Root(node);
    }

    // Handles must name current roots in this instance.
    JoinResult join_roots(Root a, Root b) {
        int x = a.index(), y = b.index();
        if (x == y) return {a, false};

        if (parent[x] < parent[y]) swap(x, y);
        parent[y] += parent[x];
        parent[x] = y;
        largest = std::max(largest, -parent[y]);
        --components;
        return {Root(y), true};
    }

    JoinResult join(int x, int y) { return join_roots(find(x), find(y)); }

    void clear() {
        parent.clear();
        components = 0;
        largest = 0;
    }

    void reset() {
        std::ranges::fill(parent, -1);
        components = static_cast<int>(parent.size());
        largest = parent.empty() ? 0 : 1;
    }

    int size() const { return static_cast<int>(parent.size()); }
    int count() const { return components; }
    bool is_root(int x) const { return parent[x] < 0; }
    int component_size(int x) const { return -parent[find(x).index()]; }
    int max_size() const { return largest; }
    bool connected(int x, int y) const { return find(x) == find(y); }
};
