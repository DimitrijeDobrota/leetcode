class Solution {
  public:
    vector<string> createGrid(const int n, const int m) const {
        vector<string> res(n, std::string(m, '#'));
        for (std::size_t i = 0; i < n; i++)
            res[i][m - 1] = '.';
        std::ranges::fill(res[0], '.');
        return res;
    }
};
