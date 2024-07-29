class Solution {
  public:
    long long interchangeableRectangles(const vector<vector<int>> &rectangles) const {
        unordered_map<double, int> um;
        long long res = 0;

        for (const auto &rec : rectangles) {
            res += um[(double)rec[0] / rec[1]]++;
        }

        return res;
    }
};
