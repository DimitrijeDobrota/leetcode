class Solution {
  public:
    int leastBricks(const vector<vector<int>> &wall) const {
        const int n = size(wall);
        unordered_map<int, int> count;

        for (const auto &row : wall) {
            long long crnt = 0;
            for (int i = 0; i < size(row) - 1; i++) {
                count[crnt += row[i]]++;
            }
        }

        int res = 0;
        for (const auto [_, v] : count)
            res = max(res, v);
        return n - res;
    }
};
