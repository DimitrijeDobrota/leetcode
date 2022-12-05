class Solution {
public:
  int heightChecker(vector<int> &heights) {
    int count = 0;
    vector<int> exp = heights;
    sort(exp.begin(), exp.end());

    for (int i = 0; i < heights.size(); i++)
      if (heights[i] != exp[i]) count++;

    return count;
  }
};
