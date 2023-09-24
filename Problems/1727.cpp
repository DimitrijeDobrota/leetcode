class Solution {
  public:
    int largestSubmatrix(vector<vector<int>> &matrix) {
        const int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0)
                    height[j] = 0;
                else
                    height[j] += 1;
            }

            vector<int> order = height;
            sort(begin(order), end(order));

            for (int j = 0; j < m; j++)
                ans = max(ans, order[j] * (m - j));
        }
        return ans;
    }
};
