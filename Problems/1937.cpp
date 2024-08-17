class Solution {
  public:
    long long maxPoints(vector<vector<int>> &points) const {
        const int n = size(points), m = size(points[0]);
        static long long crnt[100001], left[100001], right[100001];

        for (int j = 0; j < m; j++)
            crnt[j] = points[0][j];
        for (int i = 1; i < n; i++) {

            left[0] = crnt[0];
            for (int j = 1; j < m; j++) {
                left[j] = max(left[j - 1], crnt[j] + j);
            }

            right[m - 1] = crnt[m - 1] - (m - 1);
            for (int j = m - 2; j >= 0; j--) {
                right[j] = max(right[j + 1], crnt[j] - j);
            }

            for (int j = 0; j < m; j++) {
                crnt[j] = points[i][j] + max(left[j] - j, right[j] + j);
            }
        }

        return *max_element(crnt, crnt + m);
    }
};
