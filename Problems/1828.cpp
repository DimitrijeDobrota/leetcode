class Solution {
  public:
    vector<int> countPoints(const vector<vector<int>> &points, const vector<vector<int>> &queries) {
        vector<int> res(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int r2 = queries[i][2] * queries[i][2];
            for (int j = 0; j < points.size(); j++) {
                int dx = points[j][0] - queries[i][0];
                int dy = points[j][1] - queries[i][1];
                if (dx * dx + dy * dy <= r2) res[i]++;
            }
        }
        return res;
    }
};
