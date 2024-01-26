class Solution {
  public:
    bool carPooling(const vector<vector<int>> &trips, int capacity) const {
        static int count[1001];
        memset(count, 0x00, sizeof(count));

        for (const auto &trip : trips) {
            count[trip[1]] += trip[0];
            count[trip[2]] -= trip[0];
        }

        for (int i = 0; i < 1001; i++) {
            capacity -= count[i];
            if (capacity < 0) return false;
        }

        return true;
    }
};
