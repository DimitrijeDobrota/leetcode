class Solution {
  public:
    int wateringPlants(const vector<int> &plants, int capacity) {
        int res = plants.size(), crnt = capacity;
        for (int i = 0; i < plants.size(); i++) {
            if (crnt >= plants[i])
                crnt -= plants[i];
            else {
                crnt = capacity - plants[i];
                res += 2 * i;
            }
        }
        return res;
    }
};
