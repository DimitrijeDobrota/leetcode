class Solution {
  public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;

        for (int i = 0; i <= rowIndex; i++) {
            vector<int> row;
            row.push_back(1);
            for (int j = 1; j < i; j++)
                row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            if (i != 0) row.push_back(1);
            res.push_back(row);
        }
        return res[rowIndex];
    }
};
