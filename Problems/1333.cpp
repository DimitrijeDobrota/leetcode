class Solution {
  public:
    vector<int> filterRestaurants(const vector<vector<int>> &restaurants, int veganFriendly, int maxPrice,
                                  int maxDistance) const {
        vector<int> res;
        for (int i = 0; i < restaurants.size(); i++) {
            if (restaurants[i][3] > maxPrice || restaurants[i][4] > maxDistance) continue;
            if (veganFriendly && !restaurants[i][2]) continue;
            res.push_back(i);
        }
        sort(begin(res), end(res), [&](int a, int b) {
            return restaurants[a][1] != restaurants[b][1] ? restaurants[a][1] > restaurants[b][1]
                                                          : restaurants[a][0] > restaurants[b][0];
        });
        for (int i = 0; i < res.size(); i++)
            res[i] = restaurants[res[i]][0];
        return res;
    }
};
