class Solution {
    int n, m, mod = 1e9 + 7;
    vector<vector<int>> count;
    vector<vector<vector<int>>> dp = vector(10, vector(50, vector(50, -1)));

    int rec(int row, int col, int left) {
        if (count[row][col] == 0) return 0;
        if (left == 0) return 1;
        if (dp[left][row][col] != -1) return dp[left][row][col];

        int &res = dp[left][row][col] = 0;
        for (int i = row; i < n - 1; i++) {
            if (count[row][col] - count[i + 1][col] <= 0) continue;
            res = (res + rec(i + 1, col, left - 1)) % mod;
        }

        for (int i = col; i < m - 1; i++) {
            if (count[row][col] - count[row][i + 1] <= 0) continue;
            res = (res + rec(row, i + 1, left - 1)) % mod;
        }

        return res;
    }

  public:
    int ways(vector<string> &pizza, int k) {
        n = pizza.size(), m = pizza[0].size();
        count = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                count[i][j] = count[i + 1][j] + count[i][j + 1] - count[i + 1][j + 1] + (pizza[i][j] == 'A');

        return rec(0, 0, k - 1);
    }
};
