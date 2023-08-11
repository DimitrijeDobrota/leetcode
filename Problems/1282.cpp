class Solution {
public:
  vector<vector<int>> groupThePeople(const vector<int> &groupSizes) {
    unordered_map<int, vector<int>> um;
    vector<vector<int>> res;

    for (int i = 0; i < groupSizes.size(); i++) {
      if (groupSizes[i] == 1)
        res.push_back({i});
      else {
        int size = groupSizes[i];
        um[size].push_back(i);
        if (um[size].size() == size) {
          res.push_back({});
          swap(res.back(), um[size]);
        }
      }
    }

    return res;
  }
};
