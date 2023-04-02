class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    sort(potions.begin(), potions.end());

    vector<int> res;
    for (int i = 0; i < spells.size(); i++) {
      auto it = lower_bound(potions.begin(), potions.end(),
                            ceil(success / (double)spells[i]));
      res.push_back(potions.end() - it);
    }
    return res;
  }
};
