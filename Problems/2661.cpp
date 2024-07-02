class Solution {
  public:
    int firstCompleteIndex(const vector<int> &arr, const vector<vector<int>> &mat) const {
        static tuple<int, int> mapping[100001];
        static int rc[100001][2];
        const int n = size(mat), m = size(mat[0]);

        memset(rc, 0x00, 8 * size(arr));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mapping[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < size(arr); i++) {
            const auto [c, r] = mapping[arr[i]];
            if (++rc[r][0] == n) return i;
            if (++rc[c][1] == m) return i;
        }

        return -1;
    }
};
