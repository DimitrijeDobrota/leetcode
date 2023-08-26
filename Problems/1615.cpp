class Solution {
  public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        int mat[101][101] = {0}, degree[101] = {0};
        int res = 0;

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0], v = roads[i][1];
            degree[u]++, degree[v]++;
            mat[u][v] = mat[v][u] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = max(res, degree[i] + degree[j] - mat[i][j]);
            }
        }
        return res;
    }
};
