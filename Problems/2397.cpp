class Solution {
  public:
    int maximumRows(const vector<vector<int>> &matrix, const int numSelect) const {
        const int n = size(matrix), m = size(matrix[0]);
        unordered_map<uint16_t, int> um;

        for (int i = 0; i < n; i++) {
            uint16_t crnt = 0, cnt = 0;
            for (int j = 0; j < m; j++) {
                crnt |= matrix[i][j] << j;
                cnt += matrix[i][j];
            }
            if (cnt > numSelect) continue;
            um[crnt]++;
        }

        uint16_t res = 0, crnt = (1 << numSelect) - 1;
        while (crnt <= 1 << m) {
            uint16_t count = 0;
            for (const auto [k, v] : um) {
                if ((k & ~crnt) == 0) count += v;
            }
            res = max(res, count);

            uint16_t t = crnt | (crnt - 1);
            crnt = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(crnt) + 1));
        }

        return res;
    }
};
