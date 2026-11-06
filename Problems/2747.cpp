class Solution {
  public:
    vector<int> countServers(int n, vector<vector<int>> &logs, int x, const vector<int> &queries) const {
        std::ranges::sort(logs, [](auto &log1, auto &log2) { return log1[1] < log2[1]; });

        std::vector<std::pair<int, int>> indices(std::size(queries));
        for (const auto [idx, query] : std::views::enumerate(queries)) {
            indices[idx] = {query, idx};
        }
        std::ranges::sort(indices);

        std::size_t left = 0;
        std::size_t right = 0;
        std::size_t total = n;

        std::vector<int> count(n + 1, 0);
        std::vector<int> result(std::size(queries));
        for (const auto [query, index] : indices) {
            while (right < std::size(logs) && logs[right][1] <= query) {
                if (count[logs[right][0]]++ == 0) total--;
                right++;
            }

            while (left < right && logs[left][1] < query - x) {
                if (--count[logs[left][0]] == 0) total++;
                left++;
            }

            result[index] = total;
        }

        return result;
    }
};
