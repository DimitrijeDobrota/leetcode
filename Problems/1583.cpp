class Solution {
    static int position[501][501];
    bitset<500> unhappy;

    void is_unhappy(const int x, const int y, const int u, const int v) {
        if (position[x][u] < position[x][y] && position[u][x] < position[u][v]) {
            unhappy.set(x), unhappy.set(u);
        }
    }

  public:
    int unhappyFriends(const int n, const vector<vector<int>> &preferences,
                       const vector<vector<int>> &pairs) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                position[i][preferences[i][j]] = j;
            }
        }

        for (int i = 0; i < n / 2; i++) {
            const int x = pairs[i][0], y = pairs[i][1];
            for (int j = i + 1; j < n / 2; j++) {
                const int u = pairs[j][0], v = pairs[j][1];
                is_unhappy(x, y, u, v);
                is_unhappy(x, y, v, u);
                is_unhappy(y, x, u, v);
                is_unhappy(y, x, v, u);
            }
        }
        return unhappy.count();
    }
};

int Solution::position[501][501];
