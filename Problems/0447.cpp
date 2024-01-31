class Solution {
    static int distance(const vector<int> &a, const vector<int> &b) {
        return pow(b[0] - a[0], 2) + pow(b[1] - a[1], 2);
    }

  public:
    int numberOfBoomerangs(const vector<vector<int>> &points) const {
        const int n = size(points);
        int res = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> um;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                um[distance(points[i], points[j])]++;
            }

            for (const auto [_, cnt] : um) {
                if (cnt == 1) continue;
                res += cnt * (cnt - 1);
            }
        }

        return res;
    }
};
