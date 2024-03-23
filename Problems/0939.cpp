class Solution {
    static int hash(int x, int y) { return 40000 * x + y; }

  public:
    int minAreaRect(const vector<vector<int>> &points) const {
        const int n = size(points);
        unordered_set<int> us;
        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                const int x1 = points[i][0], y1 = points[i][1];
                const int x2 = points[j][0], y2 = points[j][1];
                if (us.count(hash(x1, y2)) && us.count(hash(x2, y1))) {
                    res = min(res, abs(x1 - x2) * abs(y2 - y1));
                }
            }
            us.insert(hash(points[i][0], points[i][1]));
        }

        return res != INT_MAX ? res : 0;
    }
};
