
// Ordered Query
class Solution {
  public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
        static int maxi[100001] = {0};
        const int n = size(items);

        sort(begin(items), end(items), [](auto &a, auto &b) { return a[0] < b[0]; });

        vector<int> keys = {0};
        keys.reserve(n);

        for (int i = 0, prev = -1; i < n; i++) {
            if (items[i][0] != prev) {
                keys.push_back(prev = items[i][0]);
                maxi[size(keys)] = maxi[size(keys) - 1];
            }
            maxi[size(keys)] = max(maxi[size(keys)], items[i][1]);
        }

        for (auto &query : queries) {
            const auto it = upper_bound(begin(keys), end(keys), query);
            const auto idx = distance(begin(keys), it);
            query = maxi[idx];
        }

        return queries;
    }
};

// Offline Query
class Solution {
  public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) const {
        static int idxes[100001] = {0};
        const int n = size(items), m = size(queries);

        iota(idxes, idxes + m, 0);
        sort(idxes, idxes + m, [&](int a, int b) { return queries[a] < queries[b]; });
        sort(begin(items), end(items), [](auto &a, auto &b) { return a[0] < b[0]; });

        int maxi = 0, idx = 0;
        for (int i = 0, prev = -1; i < n; i++) {
            const int price = items[i][0], value = items[i][1];

            if (price != prev) {
                while (idx < m && queries[idxes[idx]] < price)
                    queries[idxes[idx++]] = maxi;
                if (idx == m) break;
                prev = price;
            }

            maxi = max(maxi, value);
        }
        while (idx < m)
            queries[idxes[idx++]] = maxi;

        return queries;
    }
};
