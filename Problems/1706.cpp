class Solution {
    int m, n;

    bool valid_column(int column) { return column >= 0 && column < n; }

    int simulate(int column, vector<vector<int>> &grid) {
        int row = 0;
        while (row < m) {
            int type = grid[row][column];
            int nextc = column + type;
            if (valid_column(nextc) && grid[row][nextc] == type) {
                row++;
                column = nextc;
            } else
                return -1;
        }
        return column;
    }

  public:
    vector<int> findBall(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();

        vector<int> res;
        for (int i = 0; i < n; i++)
            res.push_back(simulate(i, grid));
        return res;
    }
};
