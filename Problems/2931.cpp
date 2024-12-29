class Solution {
  public:
    long long maxSpending(const vector<vector<int>> &values) const {
        const int n = size(values), m = size(values[0]);
        long long res = 0, add = 0;
        static int vec[100001];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vec[m * i + j] = values[i][j];
            }
        }

        sort(vec, vec + n * m, greater());
        for (int i = 0; i < n * m; i++) {
            res += add += vec[i];
        }

        return res;
    }
};
