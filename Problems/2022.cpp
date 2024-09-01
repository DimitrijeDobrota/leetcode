class Solution {
  public:
    vector<vector<int>> construct2DArray(const vector<int> &original, int n, int m) const {
        vector<vector<int>> res(n);

        if (m * n != size(original)) return {};
        for (int i = 0, k = 0; i < n; ++i) {
            res[i] = vector(begin(original) + i * m, begin(original) + (i + 1) * m);
        }

        return res;
    }
};
