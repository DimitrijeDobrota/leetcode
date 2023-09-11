class Solution {
  public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        sort(begin(costs), end(costs),
             [](const auto &a, const auto &b) { return (a[0] - a[1]) < (b[0] - b[1]); });
        int n = costs.size() / 2, res = 0;
        for (int i = 0; i < n; i++)
            res += costs[i][0] + costs[i + n][1];
        return res;
    }
};

// Little optimization
class Solution {
  public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        const int n = costs.size() / 2;
        nth_element(begin(costs), begin(costs) + n, end(costs),
                    [](const auto &a, const auto &b) { return (a[0] - a[1]) < (b[0] - b[1]); });
        int res = 0;
        for (int i = 0; i < n; i++)
            res += costs[i][0] + costs[i + n][1];
        return res;
    }
};
