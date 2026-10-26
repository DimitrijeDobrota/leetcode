#include "../Templates/Union_Find.cpp"

class Solution {
  public:
    int countIslands(const vector<vector<int>> &grid, int k) const {
        static std::array<int, 100'001> row_storage;
        static std::array<long long, 100'001> sum;
        static UnionFind uf;

        const std::size_t n = std::size(grid);
        const std::size_t m = std::size(grid[0]);
        ;

        const auto create = [&]() {
            const auto root = uf.add_node();
            sum[root.index()] = 0;
            return root;
        };

        const auto join = [&](UnionFind::Root x, UnionFind::Root y) {
            if (x == y) return x;

            const auto total = sum[x.index()] + sum[y.index()];
            const auto root = uf.join_roots(x, y).root;
            sum[root.index()] = total;
            return root;
        };

        const auto row = span{std::data(row_storage), m};
        std::ranges::fill(row, -1);
        uf.clear();
        for (auto i = 0UZ; i < n; ++i) {
            std::optional<UnionFind::Root> left;

            for (auto j = 0UZ; j < m; ++j) {
                if (grid[i][j] == 0) {
                    row[j] = -1;
                    left.reset();
                    continue;
                }

                if (!left) {
                    left = row[j] < 0 ? create() : uf.find(row[j]);
                } else if (row[j] >= 0) {
                    left = join(*left, uf.find(row[j]));
                }

                sum[left->index()] += grid[i][j];
                row[j] = left->index();
            }
        }

        int result = 0;
        for (int label = 0; label < std::size(uf); ++label) {
            if (!uf.is_root(label)) continue;
            result += sum[label] % k == 0;
        }
        return result;
    }
};
