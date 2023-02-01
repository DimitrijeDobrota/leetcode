class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int h = triangle.size();

    for (int i = 0; i < h - 1; i++) {
      vector<int> vec(i + 2, INT_MAX);
      for (int j = 0; j <= i; j++) {
        vec[j] = min(vec[j], triangle[i][j]);
        vec[j + 1] = min(vec[j + 1], triangle[i][j]);
      }
      for (int j = 0; j <= i + 1; j++) triangle[i + 1][j] += vec[j];
    }
    return *min_element(triangle.back().begin(), triangle.back().end());
  }
};
