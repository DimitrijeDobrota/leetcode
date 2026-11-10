class Solution {
  public:
    int climbStairs(int n, const vector<int> &costs) const {
        constexpr int inf = std::numeric_limits<int>::max() / 2;
        std::array prev = {0, inf, inf};

        for (const auto cost : costs) {
            const int best = std::min({prev[0] + 1, prev[1] + 4, prev[2] + 9});
            prev = {cost + best, prev[0], prev[1]};
        }

        return prev[0];
    }
};
