class Solution {
    static int search(int height, const vector<pair<int, int>> &st) {
        int low = 0, high = size(st) - 1;
        int ans = -1;

        while (low <= high) {
            const int mid = low + (high - low) / 2;

            if (st[mid].first > height) {
                ans = max(ans, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

  public:
    vector<int> leftmostBuildingQueries(const vector<int> &heights, const vector<vector<int>> &queries) {
        const int n = size(heights), m = size(queries);
        vector<vector<pair<int, int>>> nqueries(n);
        vector<int> res(m, -1);

        for (int i = 0; i < m; i++) {
            int a = queries[i][0];
            int b = queries[i][1];

            if (a > b) swap(a, b);
            if (heights[b] > heights[a] || a == b)
                res[i] = b;
            else
                nqueries[b].emplace_back(heights[a], i);
        }

        vector<pair<int, int>> st;
        for (int i = n - 1; i >= 0; i--) {
            for (const auto &[a, b] : nqueries[i]) {
                const auto pos = search(a, st);
                if (pos >= 0 && pos < size(st)) {
                    res[b] = st[pos].second;
                }
            }

            while (!st.empty() && st.back().first <= heights[i]) {
                st.pop_back();
            }

            st.emplace_back(heights[i], i);
        }

        return res;
    }
};
