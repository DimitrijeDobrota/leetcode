class Solution {
public:
  int maximumWealth(vector<vector<int>> &accounts) {
    vector<int> w;
    for (auto &v : accounts) w.push_back(accumulate(v.begin(), v.end(), 0));
    return *max_element(w.begin(), w.end());
  }
};
