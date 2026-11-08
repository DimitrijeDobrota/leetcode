class Solution {
public:
    int countServers(const std::vector<std::vector<int>>& grid) const {
        const auto n = std::size(grid);
        const auto m = std::size(grid[0]);

        std::vector<int> column(m, 0);
        std::vector<int> row(n, 0);
        
        for (const auto i: std::views::iota(0UZ, n)) {
            for (const auto j: std::views::iota(0UZ, m)) {
                if (grid[i][j] == 0) continue;
                column[j]++;
                row[i]++;
            }
        }

        std::size_t result = 0;
        for (const auto i: std::views::iota(0UZ, n)) {
            for (const auto j: std::views::iota(0UZ, m)) {
                if (grid[i][j] == 0) continue;
                result += row[i] > 1 || column[j] > 1;
            }
        }
        return result;
    }
};

class Solution {
public:
    int countServers(const std::vector<std::vector<int>>& grid) const {
        const auto n = std::size(grid);
        const auto m = std::size(grid[0]);

        std::vector<int> column(m, 0);
        std::vector<int> single(n, m);
        
        std::size_t result = 0;
        for (const auto i: std::views::iota(0UZ, n)) {
            std::size_t count = 0;
            std::size_t last = m;
            for (const auto j: std::views::iota(0UZ, m)) {
                if (grid[i][j] == 0) continue;
                column[j]++;
                last = j;
                count++;
            }
            if (count == 1) single[i] = last;
            else result += count;
        }

        for (const auto j: single) {
            if (j == m) continue;
            result += column[j] > 1;
        }

        return result;
    }
};