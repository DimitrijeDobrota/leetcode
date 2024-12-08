class Solution {
  public:
    int maxTwoEvents(const vector<vector<int>> &events) const {
        using type_t = tuple<int, int, int>;
        vector<type_t> times;

        times.reserve(2 * size(events));
        for (const auto &e : events) {
            times.emplace_back(e[0], 1, e[2]);
            times.emplace_back(e[1] + 1, 0, e[2]);
        }

        sort(begin(times), end(times));

        int res = 0, maxi = 0;
        for (const auto [time, is_start, val] : times) {
            if (is_start)
                res = max(res, val + maxi);
            else
                maxi = max(maxi, val);
        }

        return res;
    }
};
