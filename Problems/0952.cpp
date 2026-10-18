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

class Solution {
  public:
    int largestComponentSize(const vector<int> &nums) const {
        static std::array<int, 100'001> least_prime;
        static std::array<int, 100'001> remainder;
        static std::array<int, 100'001> primes;
        static std::array<int, 100'001> owner;
        static std::size_t primes_size;

        const auto n = std::size(nums);
        const auto max = std::ranges::max(nums);

        primes_size = 0;
        std::ranges::fill(least_prime, 0);
        std::ranges::fill(remainder, 1);

        for (int candid = 2; candid <= max; candid++) {
            if (least_prime[candid] == 0) {
                primes[primes_size++] = candid;
                least_prime[candid] = candid;
            }

            for (int j = 0; candid * primes[j] <= max; j++) {
                remainder[candid * primes[j]] = candid;
                least_prime[candid * primes[j]] = primes[j];
                if (primes[j] == least_prime[candid]) break;
            }
        }

        UnionFind uf(n);
        std::ranges::fill(owner, -1);
        for (auto [idx, value] : std::views::enumerate(nums)) {
            auto num = value;
            while (num > 1) {
                const int prime = least_prime[num];
                if (owner[prime] == -1)
                    owner[prime] = idx;
                else
                    uf.join(idx, owner[prime]);

                do {
                    num = remainder[num];
                } while (num > 1 && least_prime[num] == prime);
            }
        }

        return uf.max_size();
    }
};
