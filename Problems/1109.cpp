class Solution {
  public:
    vector<int> corpFlightBookings(const vector<vector<int>> &bookings, int n) {
        vector<int> res(n + 1, 0);

        for (const auto &booking : bookings) {
            res[booking[0] - 1] += booking[2];
            res[booking[1]] -= booking[2];
        }

        for (int i = 0, acc = 0; i < n; i++) {
            res[i] = acc += res[i];
        }

        res.resize(n);
        return res;
    }
};
