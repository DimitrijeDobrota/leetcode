class Solution {
  public:
    bool valid(int i, int m, int j, int n) { return i >= 0 && i <= m && j >= 0 && j <= n; }

    void quick_adjust(int &i, int &j, bool &up) {
        if (up)
            i++;
        else
            j++;
        up = !up;
    }

    void move(int &i, int &j, bool &up) {
        if (up) {
            i--;
            j++;
        } else {
            i++;
            j--;
        }
    }

    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        vector<int> res;
        bool up = true;
        int i = 0, j = 0;
        int m = mat.size() - 1, n = mat[0].size() - 1;

        while (true) {
            res.push_back(mat[i][j]);
            if (i == m && j == n) break;

            move(i, j, up);

            if (!valid(i, m, j, n)) {
                quick_adjust(i, j, up);
                while (!valid(i, m, j, n))
                    move(i, j, up);
            }
        }

        return res;
    }
};
