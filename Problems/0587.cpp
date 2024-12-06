class Solution {
    using point_t = vector<int>;

  public:
    vector<point_t> outerTrees(vector<point_t> &trees) const {
        const auto cross = [](const point_t &a, const point_t &b, const point_t &c) {
            return (c[1] - a[1]) * (b[0] - a[0]) - (c[0] - a[0]) * (b[1] - a[1]);
        };

        const auto cmp = [](const point_t &a, const point_t &b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        };

        const int n = size(trees);
        vector<point_t> haul(2 * n);
        int k = 0;

        sort(begin(trees), end(trees), cmp);

        for (int i = 0; i < n; i++) {
            while (k >= 2 && cross(haul[k - 2], haul[k - 1], trees[i]) < 0)
                k--;
            haul[k++] = trees[i];
        }

        for (int i = n - 2, t = k + 1; i >= 0; i--) {
            while (k >= t && cross(haul[k - 2], haul[k - 1], trees[i]) < 0)
                k--;
            haul[k++] = trees[i];
        }

        haul.resize(k);
        sort(begin(haul), end(haul));
        haul.erase(unique(begin(haul), end(haul)), end(haul));

        return haul;
    }
};
