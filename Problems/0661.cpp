class Solution {
  public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img) const {
        const int n = img.size() - 1;
        const int m = img[0].size() - 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                int sum = 0, count = 0;
                for (int k = max(i - 1, 0); k <= min(i + 1, n); k++) {
                    for (int l = max(j - 1, 0); l <= min(j + 1, m); l++) {
                        sum += img[k][l] & 0xFF;
                        count++;
                    }
                }
                img[i][j] |= (sum / count) << 8;
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                img[i][j] >>= 8;
            }
        }
        return img;
    }
};
